#include <chrono>
#include <random>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/barcode.hpp"
#include "interfaces/srv/get_barcode.hpp"

using namespace std::chrono_literals; // mention 's'

class BarcodeNode : public rclcpp::Node
{
public:
  BarcodeNode() : Node("barcode_node"), latest_barcode_(0)
  {
    // seed random generated
    rng_.seed(std::random_device{}());
    dist_ = std::uniform_int_distribution<int32_t>(10000, 99999);  // 5-digit barcode range

    // Pub : barcode sent in 1sec
    publisher_ = this->create_publisher<interfaces::msg::Barcode>("barcode", 10);

    // Timer : generate & publish barcode in 1s
    timer_ = this->create_wall_timer(1s, std::bind(&BarcodeNode::publish_barcode, this));

    // Service: when requested, give response with recent barcode
    service_ = this->create_service<interfaces::srv::GetBarcode>(
      "get_barcode",
      std::bind(&BarcodeNode::handle_get_barcode, this,
                std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(this->get_logger(), "BarcodeNode started. Publishing on 'barcode', service on 'get_barcode'.");
  }

private:
  void publish_barcode()
  {
    latest_barcode_ = dist_(rng_);  
    auto msg = interfaces::msg::Barcode();
    msg.barcode = latest_barcode_;
    publisher_->publish(msg);
    RCLCPP_DEBUG(this->get_logger(), "Published barcode: %d", latest_barcode_);
  }

  void handle_get_barcode(
    const std::shared_ptr<interfaces::srv::GetBarcode::Request> /*request*/,
    std::shared_ptr<interfaces::srv::GetBarcode::Response> response)
  {
    response->barcode = latest_barcode_;
    RCLCPP_INFO(this->get_logger(), "Service called: returning barcode %d", latest_barcode_);
  }

  rclcpp::Publisher<interfaces::msg::Barcode>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Service<interfaces::srv::GetBarcode>::SharedPtr service_;

  int32_t latest_barcode_;
  std::mt19937 rng_;
  std::uniform_int_distribution<int32_t> dist_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<BarcodeNode>());
  rclcpp::shutdown();
  return 0;
}
