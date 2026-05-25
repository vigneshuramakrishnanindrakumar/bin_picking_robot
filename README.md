# Bin Picking Cell Control

A ROS 2 (Humble) project implementing the control software for a robotic bin-picking cell.

## Architecture

```
Node & Topics
The node interaction is captured as image (rosgraph.png) from rqt_graph

HTTP flow:
  wms_server (8081 client)  ─ POST /pick ─►  robot_server (8080)
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
`bin_picking_launch`
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

Use the launch package to start the ROS nodes together, then start the HMI bridge separately.

```bash
# Source workspace before launching
source ~/ros2_ws/install/setup.bash

# Launch the robot system nodes
ros2 launch bin_picking_launch bin_picking.launch.py
```

In a second terminal, start the HMI bridge:

```bash
cd ~/ros2_ws/src/bin_picking_robot
python3 src/hmi/hmi_bridge.py
```

Open the dashboard in your browser:

```bash
http://localhost:8090
```

## Docker

Build the Docker image from the repository root:

```bash
docker build -t bin_picking_robot .
```

Run the container with the required ports exposed:

```bash
docker run --rm -p 8090:8090 -p 8080:8080 -p 8081:8081 \
  --name bin_picking_robot bin_picking_robot
```

Or use Docker Compose:

```bash
docker compose up --build
```

Then open the dashboard at:

```bash
http://localhost:8090
```

## HMI Controls

The HMI exposes buttons for:
- toggling the door state
- pressing the emergency button
- releasing the emergency button

These controls call ROS services through the HMI bridge and update the dashboard in real time.

## Interacting with the cell manually

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

Then refresh the HMI dashboard at `http://localhost:8090`.

## Notes

- The HMI bridge publishes live `door_state`, `emergency_state`, and `stack_light` updates to the browser.
- The HMI page also receives the latest WMS request and robot response.
- If the Door or Emergency node stops, the dashboard retains the last known state.

## Remarks
This project currently uses a simple service-based state model. Future improvements could add a heartbeat or state-machine layer to better handle node failures and stale state.

