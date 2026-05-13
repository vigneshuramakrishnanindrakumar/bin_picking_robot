#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__msg__Barcode() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__msg__Barcode__init(msg: *mut Barcode) -> bool;
    fn interfaces__msg__Barcode__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Barcode>, size: usize) -> bool;
    fn interfaces__msg__Barcode__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Barcode>);
    fn interfaces__msg__Barcode__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Barcode>, out_seq: *mut rosidl_runtime_rs::Sequence<Barcode>) -> bool;
}

// Corresponds to interfaces__msg__Barcode
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Barcode {

    // This member is not documented.
    #[allow(missing_docs)]
    pub barcode: i32,

}



impl Default for Barcode {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__msg__Barcode__init(&mut msg as *mut _) {
        panic!("Call to interfaces__msg__Barcode__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Barcode {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__Barcode__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__Barcode__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__Barcode__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Barcode {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Barcode where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/msg/Barcode";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__msg__Barcode() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__msg__DoorState() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__msg__DoorState__init(msg: *mut DoorState) -> bool;
    fn interfaces__msg__DoorState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DoorState>, size: usize) -> bool;
    fn interfaces__msg__DoorState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DoorState>);
    fn interfaces__msg__DoorState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DoorState>, out_seq: *mut rosidl_runtime_rs::Sequence<DoorState>) -> bool;
}

// Corresponds to interfaces__msg__DoorState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DoorState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_closed: bool,

}



impl Default for DoorState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__msg__DoorState__init(&mut msg as *mut _) {
        panic!("Call to interfaces__msg__DoorState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DoorState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__DoorState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__DoorState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__DoorState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DoorState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DoorState where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/msg/DoorState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__msg__DoorState() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__msg__EmergencyState() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__msg__EmergencyState__init(msg: *mut EmergencyState) -> bool;
    fn interfaces__msg__EmergencyState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EmergencyState>, size: usize) -> bool;
    fn interfaces__msg__EmergencyState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EmergencyState>);
    fn interfaces__msg__EmergencyState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EmergencyState>, out_seq: *mut rosidl_runtime_rs::Sequence<EmergencyState>) -> bool;
}

// Corresponds to interfaces__msg__EmergencyState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EmergencyState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_pressed: bool,

}



impl Default for EmergencyState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__msg__EmergencyState__init(&mut msg as *mut _) {
        panic!("Call to interfaces__msg__EmergencyState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EmergencyState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__EmergencyState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__EmergencyState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__EmergencyState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EmergencyState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EmergencyState where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/msg/EmergencyState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__msg__EmergencyState() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__msg__StackLight() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__msg__StackLight__init(msg: *mut StackLight) -> bool;
    fn interfaces__msg__StackLight__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StackLight>, size: usize) -> bool;
    fn interfaces__msg__StackLight__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StackLight>);
    fn interfaces__msg__StackLight__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StackLight>, out_seq: *mut rosidl_runtime_rs::Sequence<StackLight>) -> bool;
}

// Corresponds to interfaces__msg__StackLight
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// 0 = operational, 1 = paused (door open), -1 = emergency

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StackLight {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: i8,

}



impl Default for StackLight {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__msg__StackLight__init(&mut msg as *mut _) {
        panic!("Call to interfaces__msg__StackLight__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StackLight {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__StackLight__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__StackLight__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__msg__StackLight__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StackLight {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StackLight where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/msg/StackLight";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__msg__StackLight() }
  }
}


