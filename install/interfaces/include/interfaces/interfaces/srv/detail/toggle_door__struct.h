// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:srv/ToggleDoor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__TOGGLE_DOOR__STRUCT_H_
#define INTERFACES__SRV__DETAIL__TOGGLE_DOOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ToggleDoor in the package interfaces.
typedef struct interfaces__srv__ToggleDoor_Request
{
  uint8_t structure_needs_at_least_one_member;
} interfaces__srv__ToggleDoor_Request;

// Struct for a sequence of interfaces__srv__ToggleDoor_Request.
typedef struct interfaces__srv__ToggleDoor_Request__Sequence
{
  interfaces__srv__ToggleDoor_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__ToggleDoor_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ToggleDoor in the package interfaces.
typedef struct interfaces__srv__ToggleDoor_Response
{
  bool new_state;
} interfaces__srv__ToggleDoor_Response;

// Struct for a sequence of interfaces__srv__ToggleDoor_Response.
typedef struct interfaces__srv__ToggleDoor_Response__Sequence
{
  interfaces__srv__ToggleDoor_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__ToggleDoor_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__TOGGLE_DOOR__STRUCT_H_
