## Direct installations --------------------> Make sure you have internet connection for initial instalation

//Installation of required apps

sudo apt-get install vim
sudo apt-get install gcc
sudo apt-get install net-tools
sudo git --version
sudo apt-get install make
sudo apt-get upgrade

//Installation of libiec61850

git clone https://github.com/mz-automation/libiec61850.git
cd libiec61850/
make

//should end with libiec61850.a

sudo make install
cd ..

//Making static IP address for SSH

sudo apt install dhcpcd5
sudo systemctl enable dhcpcd
sudo systemctl start dhcpcd

sudo nano /etc/dhcpcd.conf

//Write at end of opened file
interface eth0
static ip_address=10.90.90.3/24
static routers=10.90.90.1


//Restart dhcpcd
sudo systemctl restart dhcpcd

//Remove internet connection
sudo reboot

## Script Details

Instructions for using this script :
1. git clone https://github.com/KishanDESE/Powergrid_security_lab.git
2. cd Powergrid_security_lab/Installation_scripts
3. chmod +x power_grid_setup.sh
4. sudo ./power_grid_setup.sh



The script performs the following actions:

1. Updates and upgrades the system packages.
2. Installs necessary packages (`vim`, `gcc`, `net-tools`, `make`, `dhcpcd5`).
3. Checks the installed version of `git`.
4. Clones the `libiec61850` repository, builds, and installs it.
5. Enables and starts the `dhcpcd` service.
6. Configures a static IP address for `eth0`.
7. Restarts the `dhcpcd` service to apply the new configuration.
