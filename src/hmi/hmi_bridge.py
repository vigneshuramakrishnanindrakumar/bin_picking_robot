#!/usr/bin/env python3
# This code is referred from ChatGPT

import json
import random
import threading
from http.server import BaseHTTPRequestHandler, HTTPServer
from pathlib import Path

# ------------------------------------------------------------------
# Try to import rclpy; fall back to a stub so the file can be syntax-
# checked without a ROS install.
# ------------------------------------------------------------------
try:
    import rclpy
    from rclpy.node import Node
    from interfaces.msg import Barcode, DoorState, EmergencyState, StackLight
    HAS_ROS = True
except ImportError:
    HAS_ROS = False

# Shared state (written by ROS callbacks, read by HTTP handler)
state = {
    "last_request":  None,   # dict  {pickId, quantity}
    "last_response": None,   # dict  {pickId, pickSuccessful, errorMessage, itemBarcode}
    "door_closed":   False,
    "emergency_pressed": False,
    "stack_light":   -1,      # 0=green, 1=yellow, -1=red
}
state_lock = threading.Lock()

HMI_PORT = 8090


# ------------------------------------------------------------------
# ROS 2 subscriber node
# ------------------------------------------------------------------
class HmiBridgeNode:
    def __init__(self):
        if not HAS_ROS:
            return
        rclpy.init()
        self.node = Node("hmi_bridge")

        self.node.create_subscription(DoorState, "door_state",
                                      self._on_door, 10)
        self.node.create_subscription(EmergencyState, "emergency_state",
                                      self._on_emergency, 10)
        self.node.create_subscription(StackLight, "stack_light",
                                      self._on_stacklight, 10)

    def _on_door(self, msg):
        with state_lock:
            print(f"[HMI] Door state updated: {'closed' if msg.is_closed else 'open'}")
            state["door_closed"] = msg.is_closed

    def _on_emergency(self, msg):
        with state_lock:
            state["emergency_pressed"] = msg.is_pressed

    def _on_stacklight(self, msg):
        with state_lock:
            state["stack_light"] = msg.state

    def spin(self):
        if HAS_ROS:
            rclpy.spin(self.node)


# ------------------------------------------------------------------
# HTTP handler
# ------------------------------------------------------------------
class HmiHandler(BaseHTTPRequestHandler):
    def log_message(self, fmt, *args):
        pass  # suppress request logs

    def do_GET(self):
        if self.path == "/state":
            with state_lock:
                payload = json.dumps(state)
            self._respond(200, "application/json", payload.encode())

        elif self.path in ("/", "/index.html"):
            html_path = Path(__file__).parent / "index.html"
            if html_path.exists():
                self._respond(200, "text/html", html_path.read_bytes())
            else:
                self._respond(404, "text/plain", b"index.html not found")
        else:
            self._respond(404, "text/plain", b"Not found")

    def do_POST(self):
        # Accept confirmPick from robot_server so we can display it
        if self.path == "/confirmPick":
            length = int(self.headers.get("Content-Length", 0))
            body = self.rfile.read(length).decode()

            try:
                data = json.loads(body)

                normalized = {
                    "pickId": data.get("pickId"),
                    "pickSuccessful": data.get("pickSuccessful", False),
                    "itemBarcode": data.get("itemBarcode", 0),
                    "errorMessage": data.get("errorMessage")
                }

                with state_lock:
                    state["last_response"] = normalized

            except Exception as e:
                print("[HMI] confirmPick parse error:", e)

            self._respond(200, "application/json", b'{"status":"ok"}')

        # Accept pick orders forwarded from WMS so we can display them
        elif self.path == "/pick":
            length = int(self.headers.get("Content-Length", 0))
            body = self.rfile.read(length).decode()

            try:
                data = json.loads(body)

                normalized = {
                    "pickId": data.get("pickId"),
                    "quantity": data.get("quantity")
                }

                with state_lock:
                    state["last_request"] = normalized

            except Exception as e:
                print("[HMI] pick parse error:", e)

            self._respond(200, "application/json", b'{"status":"ok"}')

        else:
            self._respond(404, "text/plain", b"Not found")

    def _respond(self, code, ctype, body):
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(body)))
        self.send_header("Access-Control-Allow-Origin", "*")
        self.end_headers()
        self.wfile.write(body)


# ------------------------------------------------------------------
# Entry point
# ------------------------------------------------------------------
def main():
    bridge = HmiBridgeNode()

    # ROS spin in background
    ros_thread = threading.Thread(target=bridge.spin, daemon=True)
    ros_thread.start()

    # HTTP server (blocks main thread)
    server = HTTPServer(("127.0.0.1", HMI_PORT), HmiHandler)
    print(f"[HMI] Serving at http://localhost:{HMI_PORT}")
    server.serve_forever()


if __name__ == "__main__":
    main()
