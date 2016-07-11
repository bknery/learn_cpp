// URI-EL class
// file: uriel.cpp
// Author: Bruno Knopki Nery
#include "uriel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

Uriel::Uriel(std::string uriel_device) : uriel_device_(uriel_device) {} 

int Uriel::On(int port) {

	// open URIEL port for writing
	std::cout << "Opening URIEL Device...";
	std::ofstream uriel_hl (uriel_device_);

	// check if uriel was correctly open
	if (uriel_hl.is_open()) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << std::endl << "ERROR opening URIEL device." << std::endl;
		return -1;
	}
	// turn URIEL on
	for (unsigned int i = 0; i < sizeof(uriel_on_cmd_); i++) {
		uriel_hl.put(uriel_on_cmd_[i]);
	}

	// close URIEL device
	uriel_hl.close();
	return 0;
}

int Uriel::Off(int port) {

	// open URIEL port for writing
	std::cout << "Opening URIEL Device...";
	std::ofstream uriel_hl (uriel_device_);

	// check if uriel was correctly open
	if (uriel_hl.is_open()) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << std::endl << "ERROR opening URIEL device." << std::endl;
		return -1;
	}
	// turn URIEL off
	for (unsigned int i = 0; i < sizeof(uriel_off_cmd_); i++) {
		uriel_hl.put(uriel_off_cmd_[i]);
	}

	// close URIEL device
	uriel_hl.close();
	return 0;
}
