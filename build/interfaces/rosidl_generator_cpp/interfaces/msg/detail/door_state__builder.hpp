// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/DoorState.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DOOR_STATE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__DOOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/door_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_DoorState_is_closed
{
public:
  Init_DoorState_is_closed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::DoorState is_closed(::interfaces::msg::DoorState::_is_closed_type arg)
  {
    msg_.is_closed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::DoorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::DoorState>()
{
  return interfaces::msg::builder::Init_DoorState_is_closed();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DOOR_STATE__BUILDER_HPP_
