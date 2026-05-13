// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/StackLight.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__STACK_LIGHT__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__STACK_LIGHT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__StackLight __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__StackLight __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StackLight_
{
  using Type = StackLight_<ContainerAllocator>;

  explicit StackLight_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  explicit StackLight_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  // field types and members
  using _state_type =
    int8_t;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const int8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::StackLight_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::StackLight_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::StackLight_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::StackLight_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::StackLight_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::StackLight_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::StackLight_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::StackLight_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::StackLight_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::StackLight_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__StackLight
    std::shared_ptr<interfaces::msg::StackLight_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__StackLight
    std::shared_ptr<interfaces::msg::StackLight_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StackLight_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const StackLight_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StackLight_

// alias to use template instance with default allocator
using StackLight =
  interfaces::msg::StackLight_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__STACK_LIGHT__STRUCT_HPP_
