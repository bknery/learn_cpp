// Serial Rebooter command line
// file: SerialRebooterCmd.cpp
// Author: Bruno Knopki Nery
#include "SerialRebooterCmd.h"
#include "SerialRebooter.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]){


	if(argc < 5){
		print_help();
	} else if(std::string(argv[1]) == "--help") {
		print_help();
	} else {
		for (int i = 0; i < argc; i++) // print complete command
			std::cout << argv[i] << " ";
		std::cout << std::endl;

		if (std::string(argv[4]) == "cmd") {
			//reboot with a serial command
			// create object
			// example command:
			// SerialRebooterCmd /dev/ttyS0 10 4 cmd reset "dmboot: Board reset count"
			SerialRebooter rebooter(std::string(argv[1]), 
								std::stoi(argv[2]), 
								std::stoi(argv[3]), 
								std::string(argv[5]),
								std::string(argv[6]));

			// start the rebooter
			rebooter.Start();
		} else if (std::string(argv[4]) == "uri") {
			// reboot with URI-EL
			// create object
			// example command:
			// SerialRebooterCmd /dev/ttyS0 10 4 uri /dev/ttyACM0 6 1000 "dmboot: Board reset count"
			SerialRebooter rebooter(std::string(argv[1]), 
								std::stoi(argv[2]), 
								std::stoi(argv[3]), 
								std::string(argv[5]),
								std::stoi(argv[6]), 
								std::stoi(argv[7]), 
								std::string(argv[8]));

			// start the rebooter
			rebooter.Start();

		} else {
			print_help();
		}

	}
	return 0;
}

void print_help(void){
	std::cout << "Usage: SerialRebooterCmd <serial_device> <num_reboots> <wait_time_s> cmd <reboot_cmd> <find_pattern>" << std::endl;
	std::cout << "Usage: SerialRebooterCmd <serial_device> <num_reboots> <wait_time_s> uri <uri_device> <uri_port> <uri_off_time_ms> <find_pattern>" << std::endl;
	std::cout << "Example: SerialRebooterCmd /dev/ttyS0 100 4 cmd reboot u-boot$" << std::endl;
	std::cout << "Example: SerialRebooterCmd /dev/ttyS0 100 4 uri /dev/ttyACM0 6 1000 u-boot$" << std::endl;
}
