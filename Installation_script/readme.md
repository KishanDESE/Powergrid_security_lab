
## Script Details

Instructions for using this script :
1. wget https://github.com/KishanDESE/Powergrid_security_lab/blob/8cb835c25e31cd645ca12ef02c40cf8a0123a177/Installation_script/power_grid_setup.sh
2. chmod +x setup.sh
3. sudo ./setup.sh



The script performs the following actions:

1. Updates and upgrades the system packages.
2. Installs necessary packages (`vim`, `gcc`, `net-tools`, `make`, `dhcpcd5`).
3. Checks the installed version of `git`.
4. Clones the `libiec61850` repository, builds, and installs it.
5. Enables and starts the `dhcpcd` service.
6. Configures a static IP address for `eth0`.
7. Restarts the `dhcpcd` service to apply the new configuration.
