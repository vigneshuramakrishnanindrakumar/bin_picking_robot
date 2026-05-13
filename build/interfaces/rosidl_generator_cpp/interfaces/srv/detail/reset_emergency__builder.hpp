// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/ResetEmergency.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__RESET_EMERGENCY__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__RESET_EMERGENCY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/reset_emergency__struct.hpp"
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
auto build<::interfaces::srv::ResetEmergency_Request>()
{
  return ::interfaces::srv::ResetEmergency_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_ResetEmergency_Response_success
{
public:
  Init_ResetEmergency_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::ResetEmergency_Response success(::interfaces::srv::ResetEmergency_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::ResetEmergency_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::ResetEmergency_Response>()
{
  return interfaces::srv::builder::Init_ResetEmergency_Response_success();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__RESET_EMERGENCY__BUILDER_HPP_
