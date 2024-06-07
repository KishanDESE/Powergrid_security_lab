#!/bin/bash

# Update and upgrade the system
apt-get update
apt-get upgrade -y

# Install necessary packages
apt-get install -y vim gcc net-tools make dhcpcd5

# Check git version
git --version

# Clone and install libiec61850
git clone https://github.com/mz-automation/libiec61850.git
cd libiec61850/
make
make install
cd ..

# Enable and start dhcpcd service
sudo systemctl enable dhcpcd
sudo systemctl start dhcpcd

# Prompt user for IP address and gateway
read -p "Enter static IP address (e.g., 10.90.90.5/24): " static_ip
read -p "Enter gateway address (e.g., 10.90.90.1): " gateway

# Configure static IP
cat <<EOT >> /etc/dhcpcd.conf

interface eth0
static ip_address=$static_ip
static routers=$gateway

EOT

# Restart dhcpcd service to apply changes
sudo systemctl restart dhcpcd

echo "Setup completed. Static IP configured."
