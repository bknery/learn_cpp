// Serial Rebooter class
// file: SerialRebooter.cpp
// Author: Bruno Knopki Nery
#include "SerialRebooter.h"
#include <iostream>
#include <string>
#include <cstdlib>

SerialRebooter::SerialRebooter(std::string init_serial_device,
								int init_total_reboots,
								int init_wait,
								std::string init_reboot_cmd,
								std::string init_prompt) {
	serial_device_ = init_serial_device;
	total_reboots_ = init_total_reboots;
	wait_ = init_wait;
	reboot_cmd_ = init_reboot_cmd;
	prompt_ = init_prompt;
	result_ = 0;

	std::cout << "Constructing serial rebooter object..." << std::endl;
}

SerialRebooter::~SerialRebooter() {
	std::cout << "Destructing serial rebooter object..." << std::endl;
}

int SerialRebooter::Start(void){

	char key;
	const std::string stty_cmd ("stty");
	const std::string stty_options (" ispeed 115200 ospeed 115200 clocal cread -crtscts cs8 ignpar -cstopb echo -ixon");
	std::string stty_full_cmd;

	//build configuration command
	stty_full_cmd = stty_cmd + " -F " + serial_device_ + stty_options;

	std::cout << "Configure equipment under test and press 'S' to start the test:" << std::endl;
	std::cin >> key;
	std::cout << "Test starting..." << std::endl;

	std::cout << "Configuring Serial Device..." << std::endl;
	std::cout << "OS CMD: " << stty_full_cmd << std::endl;

	// configure serial port
	system(stty_full_cmd.c_str());

	// open serial port
	std::cout << "Opening Serial Device " << serial_device_ << "..." << std::endl;

	// repeat for the total_reboots number of interactios
	for (int i = 0; i < total_reboots_ ; i++) {

		// send reboot command
		std::cout << "OUT: " << reboot_cmd_ << " i = " << i << std::endl;
	}

	return result_;
}

int SerialRebooter::GetResult(void){
	return result_;
}

