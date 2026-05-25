#!/bin/bash
set -e

source /opt/ros/humble/setup.bash
source /root/ros2_ws/install/setup.bash

# Start ROS nodes via launch file
ros2 launch bin_picking_launch bin_picking.launch.py &
LAUNCH_PID=$!

# Start the HMI bridge in foreground
python3 /root/ros2_ws/src/hmi/hmi_bridge.py

wait $LAUNCH_PID
