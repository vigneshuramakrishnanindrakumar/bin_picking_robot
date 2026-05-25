#!/usr/bin/env python3
# This code is referred from ChatGPT

import json
import random
import threading
import time
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
    from interfaces.srv import ToggleDoor, PressEmergency, ResetEmergency
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

        self.toggle_client = self.node.create_client(ToggleDoor, "toggle_door")
        self.press_client = self.node.create_client(PressEmergency, "press_emergency")
        self.reset_client = self.node.create_client(ResetEmergency, "reset_emergency")

        self._wait_for_service(self.toggle_client, "toggle_door")
        self._wait_for_service(self.press_client, "press_emergency")
        self._wait_for_service(self.reset_client, "reset_emergency")

    def _wait_for_service(self, client, name, timeout=5.0):
        if not HAS_ROS:
            return
        if not client.wait_for_service(timeout_sec=timeout):
            print(f"[HMI] Warning: service '{name}' not available")

    def _call_service(self, client, request):
        if not HAS_ROS or client is None:
            return False
        future = client.call_async(request)
        deadline = time.time() + 5.0
        while rclpy.ok() and not future.done() and time.time() < deadline:
            time.sleep(0.01)
        if not future.done():
            return False
        try:
            future.result()
            return True
        except Exception as e:
            print(f"[HMI] Service call failed: {e}")
            return False

    def toggle_door(self):
        if not HAS_ROS:
            return False
        req = ToggleDoor.Request()
        return self._call_service(self.toggle_client, req)

    def press_emergency(self):
        if not HAS_ROS:
            return False
        req = PressEmergency.Request()
        return self._call_service(self.press_client, req)

    def reset_emergency(self):
        if not HAS_ROS:
            return False
        req = ResetEmergency.Request()
        return self._call_service(self.reset_client, req)

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

        elif self.path == "/door/toggle":
            success = False
            if hasattr(self.server, "bridge") and self.server.bridge is not None:
                success = self.server.bridge.toggle_door()
            body = json.dumps({"status": "ok" if success else "error"}).encode()
            self._respond(200 if success else 500, "application/json", body)

        elif self.path == "/emergency/press":
            success = False
            if hasattr(self.server, "bridge") and self.server.bridge is not None:
                success = self.server.bridge.press_emergency()
            body = json.dumps({"status": "ok" if success else "error"}).encode()
            self._respond(200 if success else 500, "application/json", body)

        elif self.path == "/emergency/reset":
            success = False
            if hasattr(self.server, "bridge") and self.server.bridge is not None:
                success = self.server.bridge.reset_emergency()
            body = json.dumps({"status": "ok" if success else "error"}).encode()
            self._respond(200 if success else 500, "application/json", body)

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
    server = HTTPServer(("0.0.0.0", HMI_PORT), HmiHandler)
    server.bridge = bridge
    print(f"[HMI] Serving at http://0.0.0.0:{HMI_PORT}")
    server.serve_forever()


if __name__ == "__main__":
    main()
