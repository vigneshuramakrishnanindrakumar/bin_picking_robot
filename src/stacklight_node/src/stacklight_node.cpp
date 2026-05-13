#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/door_state.hpp"
#include "interfaces/msg/emergency_state.hpp"
#include "interfaces/msg/stack_light.hpp"

using namespace std::chrono_literals;

// Stack-light states
// -1 = emergency  (e-button pressed)
//  1 = paused     (door open, no emergency)
//  0 = operational (door closed, no emergency)

class StacklightNode : public rclcpp::Node
{
public:
  StacklightNode()
  : Node("stacklight_node"),
    door_closed_(false),
    emergency_pressed_(false)
  {
    publisher_ = this->create_publisher<interfaces::msg::StackLight>("stack_light", 10);

    // Subscriptions to door and emergency topics
    door_sub_ = this->create_subscription<interfaces::msg::DoorState>(
      "door_state", 10,
      std::bind(&StacklightNode::on_door_state, this, std::placeholders::_1));

    emergency_sub_ = this->create_subscription<interfaces::msg::EmergencyState>(
      "emergency_state", 10,
      std::bind(&StacklightNode::on_emergency_state, this, std::placeholders::_1));

    // Publish stack-light state at 1 Hz
    timer_ = this->create_wall_timer(1s, std::bind(&StacklightNode::publish_stack_light, this));

    RCLCPP_INFO(this->get_logger(),
      "StacklightNode started. Publishing on 'stack_light'.");
  }

private:
  void on_door_state(const interfaces::msg::DoorState::SharedPtr msg)
  {
    door_closed_ = msg->is_closed;
  }

  void on_emergency_state(const interfaces::msg::EmergencyState::SharedPtr msg)
  {
    emergency_pressed_ = msg->is_pressed;
  }

  void publish_stack_light()
  {
    auto msg = interfaces::msg::StackLight();

    if (emergency_pressed_) {
      msg.state = -1;  // RED: emergency
    } else if (!door_closed_) {
      msg.state = 1;   // YELLOW: paused (door open)
    } else {
      msg.state = 0;   // GREEN: operational
    }

    publisher_->publish(msg);

    const char * label = (msg.state == -1) ? "EMERGENCY (RED)" :
                         (msg.state ==  1) ? "PAUSED (YELLOW)" : "OPERATIONAL (GREEN)";
    RCLCPP_DEBUG(this->get_logger(), "Stack-light: %s", label);
  }

  rclcpp::Publisher<interfaces::msg::StackLight>::SharedPtr publisher_;
  rclcpp::Subscription<interfaces::msg::DoorState>::SharedPtr door_sub_;
  rclcpp::Subscription<interfaces::msg::EmergencyState>::SharedPtr emergency_sub_;
  rclcpp::TimerBase::SharedPtr timer_;

  bool door_closed_;
  bool emergency_pressed_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<StacklightNode>());
  rclcpp::shutdown();
  return 0;
}
