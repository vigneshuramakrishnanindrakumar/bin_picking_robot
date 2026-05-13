#include <atomic>
#include <memory>
#include <string>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/door_state.hpp"
#include "interfaces/msg/emergency_state.hpp"
#include "interfaces/srv/get_barcode.hpp"

#include "http_server.hpp"
#include "http_client.hpp"

// ---------------------------------------------------------------------------
// Simple JSON helpers (no external library needed for this small schema)
// ---------------------------------------------------------------------------
static int json_int(const std::string & json, const std::string & key)
{
  auto pos = json.find("\"" + key + "\"");
  if (pos == std::string::npos) return -1;
  pos = json.find(':', pos);
  if (pos == std::string::npos) return -1;
  ++pos;
  while (pos < json.size() && (json[pos] == ' ' || json[pos] == '\t')) ++pos;
  return std::stoi(json.substr(pos));
}

static std::string make_confirm_json(int pick_id, bool success,
                                     const std::string & err, int barcode)
{
  std::string err_val = err.empty() ? "null" : ("\"" + err + "\"");
  return "{"
    "\"pickId\":" + std::to_string(pick_id) + ","
    "\"pickSuccessful\":" + (success ? "true" : "false") + ","
    "\"errorMessage\":" + err_val + ","
    "\"itemBarcode\":" + std::to_string(barcode) +
    "}";
}

// ---------------------------------------------------------------------------
// RobotServer node
// ---------------------------------------------------------------------------
class RobotServer : public rclcpp::Node
{
public:
  RobotServer()
  : Node("robot_server"),
    door_closed_(true),
    emergency_pressed_(false),
    latest_barcode_(0)
  {
    door_sub_ = this->create_subscription<interfaces::msg::DoorState>(
      "door_state", 10,
      [this](const interfaces::msg::DoorState::SharedPtr msg) {
        door_closed_ = msg->is_closed;
      });

    emergency_sub_ = this->create_subscription<interfaces::msg::EmergencyState>(
      "emergency_state", 10,
      [this](const interfaces::msg::EmergencyState::SharedPtr msg) {
        emergency_pressed_ = msg->is_pressed;
      });

    barcode_client_ = this->create_client<interfaces::srv::GetBarcode>("get_barcode");

    RCLCPP_INFO(this->get_logger(), "RobotServer started on port 8080.");
  }

  // get barcode from service
  int fetch_barcode()
  {
    if (!barcode_client_->wait_for_service(std::chrono::seconds(2))) {
      RCLCPP_WARN(this->get_logger(), "Barcode service not available.");
      return latest_barcode_.load();
    }

    auto req = std::make_shared<interfaces::srv::GetBarcode::Request>();

    auto fut = barcode_client_->async_send_request(req);

    if (fut.wait_for(std::chrono::seconds(2)) ==
        std::future_status::ready)
    {
      latest_barcode_ = fut.get()->barcode;
    }
    else
    {
      RCLCPP_WARN(this->get_logger(), "Barcode request timed out.");
    }

    return latest_barcode_.load();
  }

  bool door_closed()       const { return door_closed_.load(); }
  bool emergency_pressed() const { return emergency_pressed_.load(); }

private:
  rclcpp::Subscription<interfaces::msg::DoorState>::SharedPtr     door_sub_;
  rclcpp::Subscription<interfaces::msg::EmergencyState>::SharedPtr emergency_sub_;
  rclcpp::Client<interfaces::srv::GetBarcode>::SharedPtr           barcode_client_;

  std::atomic<bool>    door_closed_;
  std::atomic<bool>    emergency_pressed_;
  std::atomic<int32_t> latest_barcode_;
};

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<RobotServer>();


  std::thread ros_thread([&node]() { rclcpp::spin(node); });

  // Hosting on localhost
  const std::string wms_host = "127.0.0.1";
  const int         wms_port = 8081;

  // server on port 8080
  SimpleHttpServer server(8080, [&](const HttpRequest & req) -> HttpResponse {
    HttpResponse resp;

    if (req.method != "POST" || req.path != "/pick") {
      resp.status = 404;
      resp.body   = "{\"error\":\"Not found\"}";
      return resp;
    }

    int pick_id  = json_int(req.body, "pickId");
    int quantity = json_int(req.body, "quantity");
    RCLCPP_INFO(node->get_logger(), "Received pick request: pickId=%d quantity=%d",
                pick_id, quantity);

    bool success = true;
    std::string error_msg;

    if (node->emergency_pressed()) {
      success   = false;
      error_msg = "Emergency button is pressed. Robot cannot move.";
      RCLCPP_WARN(node->get_logger(), "%s", error_msg.c_str());
    } else if (!node->door_closed()) {
      success   = false;
      error_msg = "Cell door is open. Robot cannot move.";
      RCLCPP_WARN(node->get_logger(), "%s", error_msg.c_str());
    }

    int barcode = success ? node->fetch_barcode() : 0;

    // Confirm pick back to WMS
    std::string confirm_body = make_confirm_json(pick_id, success, error_msg, barcode);
    RCLCPP_INFO(node->get_logger(), "Sending confirmPick to WMS: %s", confirm_body.c_str());
    http_post(wms_host, wms_port, "/confirmPick", confirm_body);

    resp.body = "{\"status\":\"processed\",\"pickId\":" + std::to_string(pick_id) + "}";
    return resp;
  });

  server.run();  // blocking call

  rclcpp::shutdown();
  ros_thread.join();
  return 0;
}
