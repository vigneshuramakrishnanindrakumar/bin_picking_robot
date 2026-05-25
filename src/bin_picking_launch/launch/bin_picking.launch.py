from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    """
    Launch all nodes for the bin picking robot system.
    
    Nodes launched:
    - barcode_node: Publishes barcode data
    - door_node: Manages door state
    - emergency_node: Handles emergency button state
    - stacklight_node: Controls stack light based on system state
    - cell_controller (robot_server): HTTP API for robot control
    - cell_controller (wms_server): HTTP API for WMS integration
    """

    # Barcode node - publishes random barcodes
    barcode_node = Node(
        package='barcode_node',
        executable='barcode_node',
        name='barcode_node',
        output='screen',
        emulate_tty=True,
    )

    # Door node - manages door state
    door_node = Node(
        package='door_node',
        executable='door_node',
        name='door_node',
        output='screen',
        emulate_tty=True,
    )

    # Emergency node - handles emergency button
    emergency_node = Node(
        package='emergency_node',
        executable='emergency_node',
        name='emergency_node',
        output='screen',
        emulate_tty=True,
    )

    # Stack light node - derives state from door and emergency
    stacklight_node = Node(
        package='stacklight_node',
        executable='stacklight_node',
        name='stacklight_node',
        output='screen',
        emulate_tty=True,
    )

    # Cell controller - robot server (HTTP API on port 8080)
    robot_server = Node(
        package='cell_controller',
        executable='robot_server',
        name='robot_server',
        output='screen',
        emulate_tty=True,
    )

    # Cell controller - WMS server (HTTP API on port 8081)
    wms_server = Node(
        package='cell_controller',
        executable='wms_server',
        name='wms_server',
        output='screen',
        emulate_tty=True,
    )

    return LaunchDescription([
        barcode_node,
        door_node,
        emergency_node,
        stacklight_node,
        robot_server,
        wms_server,
    ])
