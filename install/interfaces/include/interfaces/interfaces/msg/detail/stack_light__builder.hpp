// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/StackLight.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__STACK_LIGHT__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__STACK_LIGHT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/stack_light__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_StackLight_state
{
public:
  Init_StackLight_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::StackLight state(::interfaces::msg::StackLight::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::StackLight msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::StackLight>()
{
  return interfaces::msg::builder::Init_StackLight_state();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__STACK_LIGHT__BUILDER_HPP_
