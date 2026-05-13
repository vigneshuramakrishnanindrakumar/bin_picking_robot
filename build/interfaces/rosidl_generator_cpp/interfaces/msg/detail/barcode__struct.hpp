// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Barcode.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__BARCODE__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__BARCODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Barcode __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Barcode __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Barcode_
{
  using Type = Barcode_<ContainerAllocator>;

  explicit Barcode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->barcode = 0l;
    }
  }

  explicit Barcode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->barcode = 0l;
    }
  }

  // field types and members
  using _barcode_type =
    int32_t;
  _barcode_type barcode;

  // setters for named parameter idiom
  Type & set__barcode(
    const int32_t & _arg)
  {
    this->barcode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Barcode_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Barcode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Barcode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Barcode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Barcode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Barcode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Barcode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Barcode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Barcode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Barcode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Barcode
    std::shared_ptr<interfaces::msg::Barcode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Barcode
    std::shared_ptr<interfaces::msg::Barcode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Barcode_ & other) const
  {
    if (this->barcode != other.barcode) {
      return false;
    }
    return true;
  }
  bool operator!=(const Barcode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Barcode_

// alias to use template instance with default allocator
using Barcode =
  interfaces::msg::Barcode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__BARCODE__STRUCT_HPP_
