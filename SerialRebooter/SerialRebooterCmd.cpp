// Draw a dice
// file: draw_dice.cpp
// Author: Bruno Knopki Nery
#include "SerialRebooter.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]){


	if(argc < 5){
		printHelp();
	} else if(std::string(argv[1]) == "--help") {
		printHelp();
	} else {
		for (int i = 0; i < argc; i++) // print complete command
			std::cout << argv[i] << " ";
		std::cout << std:endl;

		// create object
		SerialRebooter rebooter(std::string(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]), std::string(argv[4]));

		// start the rebooter
		rebooter.start();
	}
	return 0;
}

static void printHelp(void){
	std::cout << "Usage: SerialRebooterCmd <serial_device> <num_reboots> <wait_time_s> <prompt>" << std::endl;
	std::cout << "Example: SerialRebooterCmd /dev/ttyS0 100 30 u-boot$" << std::endl;
}
