// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/GetBarcode.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__GET_BARCODE__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__GET_BARCODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/srv/detail/get_barcode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetBarcode_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetBarcode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetBarcode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::GetBarcode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::GetBarcode_Request & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::GetBarcode_Request>()
{
  return "interfaces::srv::GetBarcode_Request";
}

template<>
inline const char * name<interfaces::srv::GetBarcode_Request>()
{
  return "interfaces/srv/GetBarcode_Request";
}

template<>
struct has_fixed_size<interfaces::srv::GetBarcode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::GetBarcode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::GetBarcode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetBarcode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: barcode
  {
    out << "barcode: ";
    rosidl_generator_traits::value_to_yaml(msg.barcode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetBarcode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: barcode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "barcode: ";
    rosidl_generator_traits::value_to_yaml(msg.barcode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetBarcode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::GetBarcode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::GetBarcode_Response & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::GetBarcode_Response>()
{
  return "interfaces::srv::GetBarcode_Response";
}

template<>
inline const char * name<interfaces::srv::GetBarcode_Response>()
{
  return "interfaces/srv/GetBarcode_Response";
}

template<>
struct has_fixed_size<interfaces::srv::GetBarcode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::GetBarcode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::GetBarcode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::GetBarcode>()
{
  return "interfaces::srv::GetBarcode";
}

template<>
inline const char * name<interfaces::srv::GetBarcode>()
{
  return "interfaces/srv/GetBarcode";
}

template<>
struct has_fixed_size<interfaces::srv::GetBarcode>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::GetBarcode_Request>::value &&
    has_fixed_size<interfaces::srv::GetBarcode_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::GetBarcode>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::GetBarcode_Request>::value &&
    has_bounded_size<interfaces::srv::GetBarcode_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::GetBarcode>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::GetBarcode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::GetBarcode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__GET_BARCODE__TRAITS_HPP_
