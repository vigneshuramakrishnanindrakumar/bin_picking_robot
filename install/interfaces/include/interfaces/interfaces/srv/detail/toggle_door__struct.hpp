// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/ToggleDoor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__TOGGLE_DOOR__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__TOGGLE_DOOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__ToggleDoor_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__ToggleDoor_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ToggleDoor_Request_
{
  using Type = ToggleDoor_Request_<ContainerAllocator>;

  explicit ToggleDoor_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit ToggleDoor_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::ToggleDoor_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::ToggleDoor_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::ToggleDoor_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::ToggleDoor_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::ToggleDoor_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::ToggleDoor_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::ToggleDoor_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::ToggleDoor_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::ToggleDoor_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::ToggleDoor_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__ToggleDoor_Request
    std::shared_ptr<interfaces::srv::ToggleDoor_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__ToggleDoor_Request
    std::shared_ptr<interfaces::srv::ToggleDoor_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ToggleDoor_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const ToggleDoor_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ToggleDoor_Request_

// alias to use template instance with default allocator
using ToggleDoor_Request =
  interfaces::srv::ToggleDoor_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__ToggleDoor_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__ToggleDoor_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ToggleDoor_Response_
{
  using Type = ToggleDoor_Response_<ContainerAllocator>;

  explicit ToggleDoor_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_state = false;
    }
  }

  explicit ToggleDoor_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_state = false;
    }
  }

  // field types and members
  using _new_state_type =
    bool;
  _new_state_type new_state;

  // setters for named parameter idiom
  Type & set__new_state(
    const bool & _arg)
  {
    this->new_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::ToggleDoor_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::ToggleDoor_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::ToggleDoor_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::ToggleDoor_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::ToggleDoor_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::ToggleDoor_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::ToggleDoor_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::ToggleDoor_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::ToggleDoor_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::ToggleDoor_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__ToggleDoor_Response
    std::shared_ptr<interfaces::srv::ToggleDoor_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__ToggleDoor_Response
    std::shared_ptr<interfaces::srv::ToggleDoor_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ToggleDoor_Response_ & other) const
  {
    if (this->new_state != other.new_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const ToggleDoor_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ToggleDoor_Response_

// alias to use template instance with default allocator
using ToggleDoor_Response =
  interfaces::srv::ToggleDoor_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct ToggleDoor
{
  using Request = interfaces::srv::ToggleDoor_Request;
  using Response = interfaces::srv::ToggleDoor_Response;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__TOGGLE_DOOR__STRUCT_HPP_
