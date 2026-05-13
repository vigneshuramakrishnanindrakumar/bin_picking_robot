// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/StackLight.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__STACK_LIGHT__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__STACK_LIGHT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/stack_light__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const StackLight & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StackLight & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StackLight & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::msg::StackLight & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::StackLight & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::StackLight>()
{
  return "interfaces::msg::StackLight";
}

template<>
inline const char * name<interfaces::msg::StackLight>()
{
  return "interfaces/msg/StackLight";
}

template<>
struct has_fixed_size<interfaces::msg::StackLight>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::StackLight>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::StackLight>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__STACK_LIGHT__TRAITS_HPP_
