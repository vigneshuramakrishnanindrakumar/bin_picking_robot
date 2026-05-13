// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/ToggleDoor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__TOGGLE_DOOR__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__TOGGLE_DOOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/toggle_door__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::ToggleDoor_Request>()
{
  return ::interfaces::srv::ToggleDoor_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_ToggleDoor_Response_new_state
{
public:
  Init_ToggleDoor_Response_new_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::ToggleDoor_Response new_state(::interfaces::srv::ToggleDoor_Response::_new_state_type arg)
  {
    msg_.new_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::ToggleDoor_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::ToggleDoor_Response>()
{
  return interfaces::srv::builder::Init_ToggleDoor_Response_new_state();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__TOGGLE_DOOR__BUILDER_HPP_
