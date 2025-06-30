FROM ubuntu:22.04

# Install dependencies for MiniLibX and X11
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    make \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    x11-apps \
    xauth \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code
COPY . .

# Build the project
RUN make

# Set environment variables for X11 forwarding
ENV DISPLAY=:0

# Default command
CMD ["./miniRT"]