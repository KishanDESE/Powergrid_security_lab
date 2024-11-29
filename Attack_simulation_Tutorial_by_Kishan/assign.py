from scapy.all import *

# Use the Ethernet layer explicitly
ether = Ether()

# Create IP and TCP packets
ip = IP(src="23.111.142.226", dst="10.114.56.157")
tcp = TCP(dport=4000, flags='S', seq=275)

# Combine Ethernet, IP, and TCP layers
packet = ether/ip/tcp

# Send the packet on a specific interface, like eth0
sendp(packet, iface="enp158s0")

