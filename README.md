# Bin Picking Cell Control

A ROS 2 (Humble) project implementing the control software for a robotic bin-picking cell.

## Architecture

```
Node & Topics
The node interaction is captured as image (rosgraph.png) from rqt_graph 

HTTP flow:
  wms_server (8080 client)  ─ POST /pick ─►  robot_server (8080)
                            ─ POST /pick ─►  hmi_bridge (8090)  { update to HMI }
                            ─ POST /confirmPick ─► hmi_bridge (8090) { update to HMI }

  robot_server              ─ POST /confirmPick ─►  wms_server (8081)

  hmi_bridge (8090)         ◄─ GET /state ─ browser
```

## Packages

`interfaces`
`barcode_node` 
`door_node` 
`emergency_node`
`stacklight_node`
`cell_controller`
`hmi`

## Prerequisites

- Ubuntu 22.04
- ROS 2 Humble (`ros-humble-desktop`)
- Python 3.10+

## Build

```bash
# Source ROS 2
source /opt/ros/humble/setup.bash

# Clone repo into your workspace
mkdir -p ~/ros2_ws/src && cd ~/ros2_ws/src
git clone <repo-url> bin_picking_robot

# Build all packages
cd ~/ros2_ws
colcon build --symlink-install

# Source the workspace
source install/setup.bash
```

## Run

Open **six terminals**, each sourced with `source ~/ros2_ws/install/setup.bash`:

```bash
# Terminal 1 — Barcode node
ros2 run barcode_node barcode_node

# Terminal 2 — Door node
ros2 run door_node door_node

# Terminal 3 — Emergency node
ros2 run emergency_node emergency_node

# Terminal 4 — Stack-light node
ros2 run stacklight_node stacklight_node

# Terminal 5 — Robot server (port 8080) 
ros2 run cell_controller robot_server

# Terminal 6 — WMS server (port 8081, sends pick orders every 10 s)
ros2 run cell_controller wms_server

# Terminal 7 — HMI bridge + dashboard
python3 src/hmi/hmi_bridge.py
# Open http://localhost:8090 in your browser
```

## Interacting with the cell

### Toggle door open/closed
```bash
ros2 service call /toggle_door interfaces/srv/ToggleDoor "{}"
```

### Press emergency button
```bash
ros2 service call /press_emergency interfaces/srv/PressEmergency "{}"
```

### Release emergency button
```bash
ros2 service call /reset_emergency interfaces/srv/ResetEmergency "{}"
```

### Get latest barcode
```bash
ros2 service call /get_barcode interfaces/srv/GetBarcode "{}"
```

### Send a manual pick request (bypassing WMS server)
```bash
curl -X POST http://localhost:8080/pick \
  -H "Content-Type: application/json" \
  -d '{"pickId": 99, "quantity": 2}'
```

Then open `http://localhost:8090`.

### Remark
If the Door/Emergency node fails, the last known state is currently retained. This behavior can be improved later by introducing a proper state machine or a heartbeat mechanism to detect node liveness. For now, a service-based approach is used, which simply toggles or updates the currently published state as specified in the documentation.

