// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/GetBarcode.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__GET_BARCODE__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__GET_BARCODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/get_barcode__struct.hpp"
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
auto build<::interfaces::srv::GetBarcode_Request>()
{
  return ::interfaces::srv::GetBarcode_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_GetBarcode_Response_barcode
{
public:
  Init_GetBarcode_Response_barcode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::GetBarcode_Response barcode(::interfaces::srv::GetBarcode_Response::_barcode_type arg)
  {
    msg_.barcode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::GetBarcode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::GetBarcode_Response>()
{
  return interfaces::srv::builder::Init_GetBarcode_Response_barcode();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__GET_BARCODE__BUILDER_HPP_
