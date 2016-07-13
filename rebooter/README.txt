# Commands

#reboot u-boot with reset cmd
sudo ./auto_rebooter /dev/ttyS0 10 4 cmd reset "dmboot: Board reset count"

#reboot u-boot with URI-EL
sudo ./auto_rebooter /dev/ttyS0 10 4 uri /dev/ttyACM0 6 2000 "dmboot: Board reset count"

#reboot u-boot with PARPORT
sudo ./auto_rebooter /dev/ttyS0 10 4 parport /dev/parport0 2000 "dmboot: Board reset count"
