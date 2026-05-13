cmake_minimum_required(VERSION 3.8)
project(emergency_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(interfaces REQUIRED)

add_executable(emergency_node src/emergency_node.cpp)
ament_target_dependencies(emergency_node rclcpp interfaces)

install(TARGETS emergency_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
