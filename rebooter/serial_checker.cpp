// Serial Rebooter class
// file: serial_checker.cpp
// Author: Bruno Knopki Nery
#include "serial_checker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

SerialChecker::SerialChecker (std::string serial_device,
								bool log_serial,
								std::string find_pattern)
	: serial_device_(serial_device),
	log_serial_(log_serial),
	find_pattern_(find_pattern) {

	result_ = 0;

	std::cout << "Opening Serial checker..." << std::endl;
}

SerialChecker::~SerialChecker() {
	std::cout << "Closing serial checker..." << std::endl;
}

int SerialChecker::Config(void) {

	const std::string stty_cmd ("stty");
	const std::string stty_options (" ispeed 115200 ospeed 115200 clocal cread -crtscts cs8 ignpar -cstopb -echo -ixon");
	std::string stty_full_cmd;

	//build configuration command
	stty_full_cmd = stty_cmd + " -F " + serial_device_ + stty_options;

	std::cout << "Configuring Serial Device..." << std::endl;
	std::cout << "OS CMD: " << stty_full_cmd << std::endl;

	// configure serial port
	system(stty_full_cmd.c_str());

	return 0;
}

int SerialChecker::InitCheckPattern(void) {

	char line_buf[1024];

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

		if (log_serial_ == true){
			// print line to std output
			std::cout << "SERIAL IN: " << line_str << std::endl;
		}

		// look for pattern
		if (line_str.find(find_pattern_) != std::string::npos) {
			std::cout << "Pattern: " << find_pattern_ << " : found." << std::endl;
			found_pattern = true;
		}
	}
	serial_rd.close();
	return 0;
}
