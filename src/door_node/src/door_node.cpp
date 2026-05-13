#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/door_state.hpp"
#include "interfaces/srv/toggle_door.hpp"

using namespace std::chrono_literals;

class DoorNode : public rclcpp::Node
{
public:
  DoorNode() : Node("door_node"), is_closed_(true)
  {
    // Publisher: attribute
    // true  = door closed
    // false = door open 
    publisher_ = this->create_publisher<interfaces::msg::DoorState>("door_state", 10);

    timer_ = this->create_wall_timer(1s, std::bind(&DoorNode::publish_state, this));

    // Service for mocking: toggle state 
    service_ = this->create_service<interfaces::srv::ToggleDoor>(
      "toggle_door",
      std::bind(&DoorNode::handle_toggle, this,
                std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(this->get_logger(),
      "DoorNode started. Initial state: CLOSED. "
      "Publishing on 'door_state', service on 'toggle_door'.");
  }

private:
  void publish_state()
  {
    auto msg = interfaces::msg::DoorState();
    msg.is_closed = is_closed_;
    publisher_->publish(msg);
    RCLCPP_DEBUG(this->get_logger(), "Door state: %s", is_closed_ ? "CLOSED" : "OPEN");
  }

  void handle_toggle(
    const std::shared_ptr<interfaces::srv::ToggleDoor::Request> /*request*/,
    std::shared_ptr<interfaces::srv::ToggleDoor::Response> response)
  {
    is_closed_ = !is_closed_;
    response->new_state = is_closed_;
    RCLCPP_INFO(this->get_logger(),
      "Door toggled -> %s", is_closed_ ? "CLOSED" : "OPEN");
  }

  rclcpp::Publisher<interfaces::msg::DoorState>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Service<interfaces::srv::ToggleDoor>::SharedPtr service_;

  bool is_closed_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DoorNode>());
  rclcpp::shutdown();
  return 0;
}
