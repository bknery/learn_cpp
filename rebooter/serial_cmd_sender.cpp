// Serial Command Sender class
// file: serial_cmd_sender.cpp
// Author: Bruno Knopki Nery
#include "serial_cmd_sender.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

SerialCmdSender::SerialCmdSender(std::string init_serial_device,
								std::string init_reboot_cmd) {
	serial_device_ = init_serial_device;
	reboot_cmd_ = init_reboot_cmd;

	// open serial port for writing
	std::cout << "Opening Serial Device for writing...";
	std::ofstream serial_wr (serial_device_);
}

SerialCmdSender::~SerialCmdSender() {
	std::cout << "Closing serial..." << std::endl;
	// close serial for writing
	serial_wr.close();
}


int SerialCmdSender::Send(std::string cmd) {

	// check if serial was correctly open
	if (serial_wr.is_open() == false) {
		std::cout << std::endl << "ERROR: serial port not open for writing." << std::endl;
		return -1;
	}
	// send command
	serial_wr.write(cmd.c_str(), cmd.length());
	serial_wr.write("\n", 1);
	std::cout << "SERIAL CMD: " << cmd << std::endl;

	return 0;
}
