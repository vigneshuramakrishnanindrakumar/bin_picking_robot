cmake_minimum_required(VERSION 3.8)
project(cell_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(interfaces REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

# Robot-side server: listens on :8080/pick, calls ROS services, confirms pick to WMS
add_executable(robot_server src/robot_server.cpp)
ament_target_dependencies(robot_server rclcpp interfaces)
target_include_directories(robot_server PRIVATE include ${Boost_INCLUDE_DIRS})
target_link_libraries(robot_server ${Boost_LIBRARIES})

# WMS-side server: listens on :8081/confirmPick and sends pick orders to robot
add_executable(wms_server src/wms_server.cpp)
ament_target_dependencies(wms_server rclcpp interfaces)
target_include_directories(wms_server PRIVATE include ${Boost_INCLUDE_DIRS})
target_link_libraries(wms_server ${Boost_LIBRARIES})

install(TARGETS robot_server wms_server
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/
  DESTINATION include)

ament_package()
