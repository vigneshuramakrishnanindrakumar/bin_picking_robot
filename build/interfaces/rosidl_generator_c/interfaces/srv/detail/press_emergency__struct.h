// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:srv/PressEmergency.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__PRESS_EMERGENCY__STRUCT_H_
#define INTERFACES__SRV__DETAIL__PRESS_EMERGENCY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/PressEmergency in the package interfaces.
typedef struct interfaces__srv__PressEmergency_Request
{
  uint8_t structure_needs_at_least_one_member;
} interfaces__srv__PressEmergency_Request;

// Struct for a sequence of interfaces__srv__PressEmergency_Request.
typedef struct interfaces__srv__PressEmergency_Request__Sequence
{
  interfaces__srv__PressEmergency_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__PressEmergency_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/PressEmergency in the package interfaces.
typedef struct interfaces__srv__PressEmergency_Response
{
  bool success;
} interfaces__srv__PressEmergency_Response;

// Struct for a sequence of interfaces__srv__PressEmergency_Response.
typedef struct interfaces__srv__PressEmergency_Response__Sequence
{
  interfaces__srv__PressEmergency_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__PressEmergency_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__PRESS_EMERGENCY__STRUCT_H_
