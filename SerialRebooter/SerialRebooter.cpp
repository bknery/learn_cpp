// Serial Rebooter class
// file: SerialRebooter.cpp
// Author: Bruno Knopki Nery
#include "SerialRebooter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

SerialRebooter::SerialRebooter(std::string init_serial_device,
								int init_total_reboots,
								int init_wait,
								std::string init_reboot_cmd,
								std::string init_find_pattern) {
	serial_device_ = init_serial_device;
	total_reboots_ = init_total_reboots;
	wait_ = init_wait;
	reboot_cmd_ = init_reboot_cmd;
	find_pattern_ = init_find_pattern;
	result_ = 0;

	std::cout << "Constructing serial rebooter object..." << std::endl;
}

SerialRebooter::~SerialRebooter() {
	std::cout << "Closing serial rebooter..." << std::endl;
}

int SerialRebooter::Start(void){

	char key;
	const std::string stty_cmd ("stty");
	const std::string stty_options (" ispeed 115200 ospeed 115200 clocal cread -crtscts cs8 ignpar -cstopb -echo -ixon");
	std::string stty_full_cmd;
	char line_buf[256];

	//build configuration command
	stty_full_cmd = stty_cmd + " -F " + serial_device_ + stty_options;

	std::cout << "Configure equipment under test and press 'S' to start the test:" << std::endl;
	std::cin >> key;
	std::cout << "Test starting..." << std::endl;

	std::cout << "Configuring Serial Device..." << std::endl;
	std::cout << "OS CMD: " << stty_full_cmd << std::endl;

	print_config();

	// configure serial port
	system(stty_full_cmd.c_str());


	// repeat for the total_reboots number of interactios
	for (int i = 0; i < total_reboots_ ; i++) {

		// open serial port for writing
		std::cout << "Opening Serial Device for writing...";
		std::ofstream serial_wr (serial_device_);

		// check if serial was correctly open
		if (serial_wr.is_open()) {
			std::cout << "OK" << std::endl;
		} else {
			std::cout << std::endl << "ERROR opening serial port for writing." << std::endl;
			return -1;
		}
		// send reboot command
		serial_wr.write(reboot_cmd_.c_str(), reboot_cmd_.length());
		serial_wr.write("\n", 1);
		std::cout << "ITERACTION: " << i << std::endl;
		std::cout << "SERIAL CMD: " << reboot_cmd_ << std::endl;

		// close serial for writing
		serial_wr.close();

		// read serial
		// open serial port for reading
		std::cout << "Opening Serial Device for reading...";
		std::ifstream serial_rd (serial_device_);

		// check if serial was correctly open
		if (serial_rd.is_open()) {
			std::cout << "OK" << std::endl;
		} else {
			std::cout << std::endl << "ERROR opening serial port for reading." << std::endl;
			return -1;
		}

		bool found_pattern = false;

		while (found_pattern == false) {
			// get line
			serial_rd.getline(line_buf, sizeof(line_buf));

			// convert to string
			std::string line_str (line_buf);

			// print line to std output
			std::cout << "SERIAL IN: " << line_str << std::endl;

			// look for pattern
			if (line_str.find(find_pattern_) != std::string::npos) {
				std::cout << "Pattern found." << std::endl;
				std::cout << "Sleep for " << wait_ << " seconds." << std::endl;
				std::this_thread::sleep_for (std::chrono::seconds(wait_));
				found_pattern = true;
			}
		}
		serial_rd.close();
	}
	std::cout << std::endl;
	std::cout << "######## SUCCESS! " << total_reboots_ << " reboots executed ########" << std::endl;
	print_config();
	return result_;
}

int SerialRebooter::GetResult(void){
	return result_;
}

void SerialRebooter::print_config(void){
	
	std::cout << "Serial sevice: " << serial_device_ << std::endl;
	std::cout << "Total reboots: " << total_reboots_ << std::endl;
	std::cout << "Wait: " << wait_ << std::endl;
	std::cout << "Reboot cmd: " << reboot_cmd_ << std::endl;
	std::cout << "Pattern to find: " << find_pattern_ << std::endl;
}
