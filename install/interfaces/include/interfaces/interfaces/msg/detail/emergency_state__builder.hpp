// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/EmergencyState.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__EMERGENCY_STATE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__EMERGENCY_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/emergency_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_EmergencyState_is_pressed
{
public:
  Init_EmergencyState_is_pressed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::EmergencyState is_pressed(::interfaces::msg::EmergencyState::_is_pressed_type arg)
  {
    msg_.is_pressed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::EmergencyState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::EmergencyState>()
{
  return interfaces::msg::builder::Init_EmergencyState_is_pressed();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__EMERGENCY_STATE__BUILDER_HPP_
