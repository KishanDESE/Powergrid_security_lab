
## Script Details

The script performs the following actions:

1. Updates and upgrades the system packages.
2. Installs necessary packages (`vim`, `gcc`, `net-tools`, `make`, `dhcpcd5`).
3. Checks the installed version of `git`.
4. Clones the `libiec61850` repository, builds, and installs it.
5. Enables and starts the `dhcpcd` service.
6. Configures a static IP address for `eth0`.
7. Restarts the `dhcpcd` service to apply the new configuration.
