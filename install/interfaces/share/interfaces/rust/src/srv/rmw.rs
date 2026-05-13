#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__GetBarcode_Request() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__srv__GetBarcode_Request__init(msg: *mut GetBarcode_Request) -> bool;
    fn interfaces__srv__GetBarcode_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetBarcode_Request>, size: usize) -> bool;
    fn interfaces__srv__GetBarcode_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetBarcode_Request>);
    fn interfaces__srv__GetBarcode_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetBarcode_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetBarcode_Request>) -> bool;
}

// Corresponds to interfaces__srv__GetBarcode_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetBarcode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetBarcode_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__srv__GetBarcode_Request__init(&mut msg as *mut _) {
        panic!("Call to interfaces__srv__GetBarcode_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetBarcode_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__GetBarcode_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__GetBarcode_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__GetBarcode_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetBarcode_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetBarcode_Request where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/srv/GetBarcode_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__GetBarcode_Request() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__GetBarcode_Response() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__srv__GetBarcode_Response__init(msg: *mut GetBarcode_Response) -> bool;
    fn interfaces__srv__GetBarcode_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetBarcode_Response>, size: usize) -> bool;
    fn interfaces__srv__GetBarcode_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetBarcode_Response>);
    fn interfaces__srv__GetBarcode_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetBarcode_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetBarcode_Response>) -> bool;
}

// Corresponds to interfaces__srv__GetBarcode_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetBarcode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub barcode: i32,

}



impl Default for GetBarcode_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__srv__GetBarcode_Response__init(&mut msg as *mut _) {
        panic!("Call to interfaces__srv__GetBarcode_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetBarcode_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__GetBarcode_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__GetBarcode_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__GetBarcode_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetBarcode_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetBarcode_Response where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/srv/GetBarcode_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__GetBarcode_Response() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__ToggleDoor_Request() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__srv__ToggleDoor_Request__init(msg: *mut ToggleDoor_Request) -> bool;
    fn interfaces__srv__ToggleDoor_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ToggleDoor_Request>, size: usize) -> bool;
    fn interfaces__srv__ToggleDoor_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ToggleDoor_Request>);
    fn interfaces__srv__ToggleDoor_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ToggleDoor_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ToggleDoor_Request>) -> bool;
}

// Corresponds to interfaces__srv__ToggleDoor_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ToggleDoor_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for ToggleDoor_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__srv__ToggleDoor_Request__init(&mut msg as *mut _) {
        panic!("Call to interfaces__srv__ToggleDoor_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ToggleDoor_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ToggleDoor_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ToggleDoor_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ToggleDoor_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ToggleDoor_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ToggleDoor_Request where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/srv/ToggleDoor_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__ToggleDoor_Request() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__ToggleDoor_Response() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__srv__ToggleDoor_Response__init(msg: *mut ToggleDoor_Response) -> bool;
    fn interfaces__srv__ToggleDoor_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ToggleDoor_Response>, size: usize) -> bool;
    fn interfaces__srv__ToggleDoor_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ToggleDoor_Response>);
    fn interfaces__srv__ToggleDoor_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ToggleDoor_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ToggleDoor_Response>) -> bool;
}

// Corresponds to interfaces__srv__ToggleDoor_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ToggleDoor_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub new_state: bool,

}



impl Default for ToggleDoor_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__srv__ToggleDoor_Response__init(&mut msg as *mut _) {
        panic!("Call to interfaces__srv__ToggleDoor_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ToggleDoor_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ToggleDoor_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ToggleDoor_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ToggleDoor_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ToggleDoor_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ToggleDoor_Response where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/srv/ToggleDoor_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__ToggleDoor_Response() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__PressEmergency_Request() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__srv__PressEmergency_Request__init(msg: *mut PressEmergency_Request) -> bool;
    fn interfaces__srv__PressEmergency_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PressEmergency_Request>, size: usize) -> bool;
    fn interfaces__srv__PressEmergency_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PressEmergency_Request>);
    fn interfaces__srv__PressEmergency_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PressEmergency_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PressEmergency_Request>) -> bool;
}

// Corresponds to interfaces__srv__PressEmergency_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PressEmergency_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for PressEmergency_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__srv__PressEmergency_Request__init(&mut msg as *mut _) {
        panic!("Call to interfaces__srv__PressEmergency_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PressEmergency_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__PressEmergency_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__PressEmergency_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__PressEmergency_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PressEmergency_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PressEmergency_Request where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/srv/PressEmergency_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__PressEmergency_Request() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__PressEmergency_Response() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__srv__PressEmergency_Response__init(msg: *mut PressEmergency_Response) -> bool;
    fn interfaces__srv__PressEmergency_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PressEmergency_Response>, size: usize) -> bool;
    fn interfaces__srv__PressEmergency_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PressEmergency_Response>);
    fn interfaces__srv__PressEmergency_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PressEmergency_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PressEmergency_Response>) -> bool;
}

// Corresponds to interfaces__srv__PressEmergency_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PressEmergency_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for PressEmergency_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__srv__PressEmergency_Response__init(&mut msg as *mut _) {
        panic!("Call to interfaces__srv__PressEmergency_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PressEmergency_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__PressEmergency_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__PressEmergency_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__PressEmergency_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PressEmergency_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PressEmergency_Response where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/srv/PressEmergency_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__PressEmergency_Response() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__ResetEmergency_Request() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__srv__ResetEmergency_Request__init(msg: *mut ResetEmergency_Request) -> bool;
    fn interfaces__srv__ResetEmergency_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ResetEmergency_Request>, size: usize) -> bool;
    fn interfaces__srv__ResetEmergency_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ResetEmergency_Request>);
    fn interfaces__srv__ResetEmergency_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ResetEmergency_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ResetEmergency_Request>) -> bool;
}

// Corresponds to interfaces__srv__ResetEmergency_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ResetEmergency_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for ResetEmergency_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__srv__ResetEmergency_Request__init(&mut msg as *mut _) {
        panic!("Call to interfaces__srv__ResetEmergency_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ResetEmergency_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ResetEmergency_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ResetEmergency_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ResetEmergency_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ResetEmergency_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ResetEmergency_Request where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/srv/ResetEmergency_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__ResetEmergency_Request() }
  }
}


#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__ResetEmergency_Response() -> *const std::ffi::c_void;
}

#[link(name = "interfaces__rosidl_generator_c")]
extern "C" {
    fn interfaces__srv__ResetEmergency_Response__init(msg: *mut ResetEmergency_Response) -> bool;
    fn interfaces__srv__ResetEmergency_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ResetEmergency_Response>, size: usize) -> bool;
    fn interfaces__srv__ResetEmergency_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ResetEmergency_Response>);
    fn interfaces__srv__ResetEmergency_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ResetEmergency_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ResetEmergency_Response>) -> bool;
}

// Corresponds to interfaces__srv__ResetEmergency_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ResetEmergency_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for ResetEmergency_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces__srv__ResetEmergency_Response__init(&mut msg as *mut _) {
        panic!("Call to interfaces__srv__ResetEmergency_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ResetEmergency_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ResetEmergency_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ResetEmergency_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces__srv__ResetEmergency_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ResetEmergency_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ResetEmergency_Response where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces/srv/ResetEmergency_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces__srv__ResetEmergency_Response() }
  }
}






#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__interfaces__srv__GetBarcode() -> *const std::ffi::c_void;
}

// Corresponds to interfaces__srv__GetBarcode
#[allow(missing_docs, non_camel_case_types)]
pub struct GetBarcode;

impl rosidl_runtime_rs::Service for GetBarcode {
    type Request = GetBarcode_Request;
    type Response = GetBarcode_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__interfaces__srv__GetBarcode() }
    }
}




#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__interfaces__srv__ToggleDoor() -> *const std::ffi::c_void;
}

// Corresponds to interfaces__srv__ToggleDoor
#[allow(missing_docs, non_camel_case_types)]
pub struct ToggleDoor;

impl rosidl_runtime_rs::Service for ToggleDoor {
    type Request = ToggleDoor_Request;
    type Response = ToggleDoor_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__interfaces__srv__ToggleDoor() }
    }
}




#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__interfaces__srv__PressEmergency() -> *const std::ffi::c_void;
}

// Corresponds to interfaces__srv__PressEmergency
#[allow(missing_docs, non_camel_case_types)]
pub struct PressEmergency;

impl rosidl_runtime_rs::Service for PressEmergency {
    type Request = PressEmergency_Request;
    type Response = PressEmergency_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__interfaces__srv__PressEmergency() }
    }
}




#[link(name = "interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__interfaces__srv__ResetEmergency() -> *const std::ffi::c_void;
}

// Corresponds to interfaces__srv__ResetEmergency
#[allow(missing_docs, non_camel_case_types)]
pub struct ResetEmergency;

impl rosidl_runtime_rs::Service for ResetEmergency {
    type Request = ResetEmergency_Request;
    type Response = ResetEmergency_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__interfaces__srv__ResetEmergency() }
    }
}


