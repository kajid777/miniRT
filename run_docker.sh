#!/bin/bash

# Enable X11 forwarding on macOS
xhost +localhost

# Run the Docker container with X11 forwarding
docker-compose up --build

# Clean up X11 permissions after running
xhost -localhost