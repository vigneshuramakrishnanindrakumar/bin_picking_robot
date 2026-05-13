#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/emergency_state.hpp"
#include "interfaces/srv/press_emergency.hpp"
#include "interfaces/srv/reset_emergency.hpp"

using namespace std::chrono_literals;

class EmergencyNode : public rclcpp::Node
{
public:
  EmergencyNode() : Node("emergency_node"), is_pressed_(false)
  {
    // Publisher: attribute
    // true  = button pressed
    // false = button released
    publisher_ = this->create_publisher<interfaces::msg::EmergencyState>("emergency_state", 10);

    timer_ = this->create_wall_timer(1s, std::bind(&EmergencyNode::publish_state, this));

    // Service: simulate pressing Emer-button
    press_service_ = this->create_service<interfaces::srv::PressEmergency>(
      "press_emergency",
      std::bind(&EmergencyNode::handle_press, this,
                std::placeholders::_1, std::placeholders::_2));

    // Service for mocking: simulate releasing Emer-button
    reset_service_ = this->create_service<interfaces::srv::ResetEmergency>(
      "reset_emergency",
      std::bind(&EmergencyNode::handle_reset, this,
                std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(this->get_logger(),
      "EmergencyNode started. Initial state: NOT PRESSED. "
      "Services: 'press_emergency', 'reset_emergency'.");
  }

private:
  void publish_state()
  {
    auto msg = interfaces::msg::EmergencyState();
    msg.is_pressed = is_pressed_;
    publisher_->publish(msg);
    RCLCPP_DEBUG(this->get_logger(),
      "E-button state: %s", is_pressed_ ? "PRESSED" : "RELEASED");
  }

  void handle_press(
    const std::shared_ptr<interfaces::srv::PressEmergency::Request> /*request*/,
    std::shared_ptr<interfaces::srv::PressEmergency::Response> response)
  {
    is_pressed_ = true;
    response->success = true;
    RCLCPP_WARN(this->get_logger(), "EMERGENCY BUTTON PRESSED!");
  }

  void handle_reset(
    const std::shared_ptr<interfaces::srv::ResetEmergency::Request> /*request*/,
    std::shared_ptr<interfaces::srv::ResetEmergency::Response> response)
  {
    is_pressed_ = false;
    response->success = true;
    RCLCPP_INFO(this->get_logger(), "Emergency button released.");
  }

  rclcpp::Publisher<interfaces::msg::EmergencyState>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Service<interfaces::srv::PressEmergency>::SharedPtr press_service_;
  rclcpp::Service<interfaces::srv::ResetEmergency>::SharedPtr reset_service_;

  bool is_pressed_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<EmergencyNode>());
  rclcpp::shutdown();
  return 0;
}
