# Commands

#reboot u-boot with reset cmd
sudo ./SerialRebooterCmd /dev/ttyS0 10 4 cmd reset "dmboot: Board reset count"

#reboot u-boot with URI-EL
sudo ./SerialRebooterCmd /dev/ttyS0 10 4 uri /dev/ttyACM0 6 2000 "dmboot: Board reset count"
