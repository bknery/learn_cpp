// Serial Rebooter command line
// file: SerialRebooterCmd.cpp
// Author: Bruno Knopki Nery
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
		std::cout << std:endl;

		// create object
		SerialRebooter rebooter(std::string(argv[1]), 
								std::stoi(argv[2]), 
								std::stoi(argv[3]), 
								std::string(argv[4]);
								std::string(argv[5]));

		// start the rebooter
		rebooter.Start();
	}
	return 0;
}

static void print_help(void){
	std::cout << "Usage: SerialRebooterCmd <serial_device> <num_reboots> <wait_time_s> <reboot_cmd> <prompt>" << std::endl;
	std::cout << "Example: SerialRebooterCmd /dev/ttyS0 100 30 reboot u-boot$" << std::endl;
}
