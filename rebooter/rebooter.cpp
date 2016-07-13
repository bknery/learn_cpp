// Serial Rebooter class
// file: rebooter.cpp
// Author: Bruno Knopki Nery
#include "rebooter.h"
#include "serial_checker.h"
#include "serial_cmd_sender.h"
#include "uriel.h"
#include "parport_controller.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

Rebooter::Rebooter(std::string serial_device,
					int total_reboots,
					int wait,
					std::string reboot_cmd,
					std::string find_pattern) 
	: serial_device_(serial_device),
	total_reboots_(total_reboots),
	wait_(wait),
	reboot_cmd_(reboot_cmd),
	find_pattern_(find_pattern) {

	reboot_device_ = SERIAL_CMD;
	uriel_device_ = "/dev/ttyACM0"; // dummy device
	uriel_port_ = 6;
	off_time_ms_ = 1000;
	result_ = 0;

	std::cout << "Serial rebooter with commands through serial port..." << std::endl;
}

Rebooter::Rebooter(std::string serial_device,
								int total_reboots,
								int wait,
								std::string uriel_device,
								int uriel_port,
								int off_time_ms,
								std::string find_pattern)
	: serial_device_(serial_device),
	total_reboots_(total_reboots),
	wait_(wait),
	uriel_device_(uriel_device),
	uriel_port_(uriel_port),
	off_time_ms_(off_time_ms),
	find_pattern_(find_pattern) {
	
	reboot_device_ = URI_EL;
	parport_device_ = "/dev/parport0"; // dummy device
	reboot_cmd_ = "reboot"; // dummy cmd
	result_ = 0;
	std::cout << "Serial rebooter with URI-EL..." << std::endl;
}
Rebooter::Rebooter(std::string serial_device,
								int total_reboots,
								int wait,
								std::string parport_device,
								int off_time_ms,
								std::string find_pattern)
	: serial_device_(serial_device),
	total_reboots_(total_reboots),
	wait_(wait),
	parport_device_(parport_device),
	off_time_ms_(off_time_ms),
	find_pattern_(find_pattern) {
	
	reboot_device_ = PARPORT;
	uriel_device_ = "/dev/ttyACM0"; // dummy device
	uriel_port_ = 6; // dummy port
	reboot_cmd_ = "reboot"; // dummy cmd
	result_ = 0;
	std::cout << "Serial rebooter with PARPORT..." << std::endl;
}
Rebooter::~Rebooter() {
	std::cout << "Closing serial rebooter..." << std::endl;
}

int Rebooter::Start(void){

	char key;
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

		// Open serial and check pattern
		// Stays here until pattern is found
		serial_checker.InitCheckPattern();
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
		std::cout << "URI-EL device: " << uriel_device_ << std::endl;
		std::cout << "URI-EL port: " << uriel_port_ << std::endl;
		std::cout << "OFF time ms: " << off_time_ms_ << std::endl;
		std::cout << "Pattern to find: " << find_pattern_ << std::endl;
	} else if (reboot_device_ == PARPORT) {
		std::cout << "Serial sevice: " << serial_device_ << std::endl;
		std::cout << "Total reboots: " << total_reboots_ << std::endl;
		std::cout << "Wait: " << wait_ << std::endl;
		std::cout << "Reboot device: PARPORT" << std::endl;
		std::cout << "PARPORT device: " << parport_device_ << std::endl;
		std::cout << "OFF time ms: " << off_time_ms_ << std::endl;
		std::cout << "Pattern to find: " << find_pattern_ << std::endl;
	}
}

int Rebooter::reboot(void) {
	if (reboot_device_ == SERIAL_CMD) {
		// create serial sender obj and open serial port for writing
		SerialCmdSender serial_cmd_sender (serial_device_);
		
		// send reboot command and close serial 
		serial_cmd_sender.Send(reboot_cmd_);

	} else if (reboot_device_ == URI_EL) {

		// Create URI-EL obj
		Uriel uriel(uriel_device_);

		std::cout << "Turning URI-EL off..." << std::endl;
		if (uriel.Off(uriel_port_) < 0) {
			std::cout << "Error turning URIEL off." << std::endl;
			return -1;
		}
		// wait off time
		std::cout << "Wait " << off_time_ms_ << " ms." << std::endl;
		std::this_thread::sleep_for (std::chrono::milliseconds(off_time_ms_));

		std::cout << "Turning URI-EL on..." << std::endl;
		// turn on again
		if (uriel.On(uriel_port_) < 0) {
			std::cout << "Error turning URIEL on." << std::endl;
			return -1;
		}
	} else if (reboot_device_ == PARPORT) {

		std::cout << "Turning PARPORT off..." << std::endl;
		if (parport_off(parport_device_.c_str()) < 0) {
			std::cout << "Error turning PARPORT off." << std::endl;
			return -1;
		}
		// wait off time
		std::cout << "Wait " << off_time_ms_ << " ms." << std::endl;
		std::this_thread::sleep_for (std::chrono::milliseconds(off_time_ms_));

		std::cout << "Turning PARPORT on..." << std::endl;
		// turn on again
		if (parport_on(parport_device_.c_str()) < 0) {
			std::cout << "Error turning URIEL on." << std::endl;
			return -1;
		}
	}
	return 0;
}
