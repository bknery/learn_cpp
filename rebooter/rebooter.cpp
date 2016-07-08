// Serial Rebooter class
// file: rebooter.cpp
// Author: Bruno Knopki Nery
#include "rebooter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

Rebooter::Rebooter(std::string init_serial_device,
								int init_total_reboots,
								int init_wait,
								std::string init_reboot_cmd,
								std::string init_find_pattern) {
	serial_device_ = init_serial_device;
	total_reboots_ = init_total_reboots;
	wait_ = init_wait;
	reboot_device_ = SERIAL_CMD;
	reboot_cmd_ = init_reboot_cmd;
	find_pattern_ = init_find_pattern;
	uri_device_ = "/dev/ttyACM0"; // dummy device
	uri_port_ = 6;
	off_time_ms_ = 1000;
	result_ = 0;

	std::cout << "Serial rebooter with commands through serial port..." << std::endl;
}

Rebooter::Rebooter(std::string init_serial_device,
								int init_total_reboots,
								int init_wait,
								std::string init_uri_device,
								int init_uri_port,
								int init_off_time_ms,
								std::string init_find_pattern) {
	serial_device_ = init_serial_device;
	total_reboots_ = init_total_reboots;
	wait_ = init_wait;
	reboot_device_ = URI_EL;
	reboot_cmd_ = "reboot"; // dummy cmd
	find_pattern_ = init_find_pattern;
	uri_device_ = init_uri_device;
	uri_port_ = init_uri_port;
	off_time_ms_ = init_off_time_ms;
	result_ = 0;

	std::cout << "Serial rebooter with URI-EL..." << std::endl;
}
Rebooter::~Rebooter() {
	std::cout << "Closing serial rebooter..." << std::endl;
}

int Rebooter::Start(void){

	std::cout << "Configure equipment under test and press 'S' to start the test:" << std::endl;
	std::cin >> key;
	std::cout << "Test starting..." << std::endl;

	print_config();

	// Create Serial Checker object
	SerialChecker serial_checker (serial_device_, true, find_pattern_);

	// Config Serial Port
	serial_checker.Config();

	// repeat for the total_reboots number of interactios
	for (int i = 0; i < total_reboots_ ; i++) {

		std::cout << "ITERACTION: " << i << std::endl;
		// reboot with serial command or with URI-EL
		if (reboot() < 0) {
			std::cout << "ERROR rebooting!" << std::endl;
			return -1;
		}
	

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

int Rebooter::GetResult(void){
	return result_;
}

void Rebooter::print_config(void){
	if (reboot_device_ == SERIAL_CMD) {
		std::cout << "Serial sevice: " << serial_device_ << std::endl;
		std::cout << "Total reboots: " << total_reboots_ << std::endl;
		std::cout << "Wait: " << wait_ << std::endl;
		std::cout << "Reboot device: Serial command" << std::endl;
		std::cout << "Reboot cmd: " << reboot_cmd_ << std::endl;
		std::cout << "Pattern to find: " << find_pattern_ << std::endl;
	} else if (reboot_device_ == URI_EL) {
		std::cout << "Serial sevice: " << serial_device_ << std::endl;
		std::cout << "Total reboots: " << total_reboots_ << std::endl;
		std::cout << "Wait: " << wait_ << std::endl;
		std::cout << "Reboot device: URI-EL" << std::endl;
		std::cout << "URI-EL device: " << uri_device_ << std::endl;
		std::cout << "URI-EL port: " << uri_port_ << std::endl;
		std::cout << "OFF time ms: " << off_time_ms_ << std::endl;
		std::cout << "Pattern to find: " << find_pattern_ << std::endl;
	}
}

int Rebooter::reboot(void) {
	if (reboot_device_ == SERIAL_CMD) {
		// create serial sender obj and open serial port for writing
		SerialCmdSender serial_cmd_sender (serial_device_);
		
		// send reboot command and close serial 
		serial_cmd_sender (reboot_cmd_);

	} else if (reboot_device_ == URI_EL) {
		std::cout << "Turning URI-EL off..." << std::endl;
		if (turn_uriel_off() < 0) {
			std::cout << "Error turning URIEL off." << std::endl;
			return -1;
		}
		// wait off time
		std::cout << "Wait " << off_time_ms_ << " ms." << std::endl;
		std::this_thread::sleep_for (std::chrono::milliseconds(off_time_ms_));

		std::cout << "Turning URI-EL on..." << std::endl;
		// turn on again
		if (turn_uriel_on() < 0) {
			std::cout << "Error turning URIEL on." << std::endl;
			return -1;
		}

	}
	return 0;
}

int Rebooter::turn_uriel_on(void) {

	// open URIEL port for writing
	std::cout << "Opening URIEL Device...";
	std::ofstream uriel (uri_device_);

	// check if uriel was correctly open
	if (uriel.is_open()) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << std::endl << "ERROR opening URIEL device." << std::endl;
		return -1;
	}
	// turn URIEL on
	for (unsigned int i = 0; i < sizeof(uri_on_cmd_); i++) {
		uriel.put(uri_on_cmd_[i]);
	}

	// close URIEL device
	uriel.close();
	return 0;
}

int Rebooter::turn_uriel_off(void) {

	// open URIEL port for writing
	std::cout << "Opening URIEL Device...";
	std::ofstream uriel (uri_device_);

	// check if uriel was correctly open
	if (uriel.is_open()) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << std::endl << "ERROR opening URIEL device." << std::endl;
		return -1;
	}
	// turn URIEL off
	for (unsigned int i = 0; i < sizeof(uri_off_cmd_); i++) {
		uriel.put(uri_off_cmd_[i]);
	}

	// close URIEL device
	uriel.close();
	return 0;
}
