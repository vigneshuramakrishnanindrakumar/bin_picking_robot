// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/EmergencyState.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__EMERGENCY_STATE__STRUCT_H_
#define INTERFACES__MSG__DETAIL__EMERGENCY_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/EmergencyState in the package interfaces.
typedef struct interfaces__msg__EmergencyState
{
  bool is_pressed;
} interfaces__msg__EmergencyState;

// Struct for a sequence of interfaces__msg__EmergencyState.
typedef struct interfaces__msg__EmergencyState__Sequence
{
  interfaces__msg__EmergencyState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__EmergencyState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__EMERGENCY_STATE__STRUCT_H_
