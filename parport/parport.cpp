// Turn parallel port on and off with estagiario eletronico
// file: parport.cpp
// Author: Bruno Knopki Nery
#include "parport.h"
#include "../rebooter/parport_controller.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]){

	if(argc < 2) {
		print_help();
	} else if(std::string(argv[1]) == "--help") {
		print_help();
	} else if (std::string(argv[1]) == "on") {
		if (parport_on("/dev/parport0") < 0) {
			std::cout << "ERROR turning parport on." << std::endl;
			return -1;
		}
	} else if (std::string(argv[1]) == "off") {
		if (parport_off("/dev/parport0") < 0) {
			std::cout << "ERROR turning parport on." << std::endl;
			return -1;
		}
	} else {
		print_help();
	}
	return 0;
}

void print_help(void){
	std::cout << "Usage: parport on" << std::endl;
	std::cout << "Usage: parport off" << std::endl;
}
