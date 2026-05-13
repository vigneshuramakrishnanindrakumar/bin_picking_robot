cmake_minimum_required(VERSION 3.8)
project(stacklight_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(interfaces REQUIRED)

add_executable(stacklight_node src/stacklight_node.cpp)
ament_target_dependencies(stacklight_node rclcpp interfaces)

install(TARGETS stacklight_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
