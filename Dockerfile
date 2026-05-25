FROM osrf/ros:humble-desktop

ENV DEBIAN_FRONTEND=noninteractive

# Install build tools and ROS Python dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    python3-colcon-common-extensions \
    python3-rosdep \
    && rm -rf /var/lib/apt/lists/*

# Create workspace
WORKDIR /root/ros2_ws

# Copy repository into container
COPY . ./

# Build the ROS workspace
RUN . /opt/ros/humble/setup.sh && \
    rosdep update && \
    rosdep install --from-paths src --ignore-src -y --skip-keys ament_python && \
    colcon build --symlink-install

# HMI resource files must be exposed
EXPOSE 8090 8080 8081

# Default entrypoint loads the ROS environment and starts the system
COPY docker-entrypoint.sh /usr/local/bin/docker-entrypoint.sh
RUN chmod +x /usr/local/bin/docker-entrypoint.sh
ENTRYPOINT ["/usr/local/bin/docker-entrypoint.sh"]
CMD [""]
