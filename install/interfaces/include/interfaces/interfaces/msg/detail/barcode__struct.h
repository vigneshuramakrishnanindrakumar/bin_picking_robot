// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Barcode.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__BARCODE__STRUCT_H_
#define INTERFACES__MSG__DETAIL__BARCODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Barcode in the package interfaces.
typedef struct interfaces__msg__Barcode
{
  int32_t barcode;
} interfaces__msg__Barcode;

// Struct for a sequence of interfaces__msg__Barcode.
typedef struct interfaces__msg__Barcode__Sequence
{
  interfaces__msg__Barcode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Barcode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__BARCODE__STRUCT_H_
