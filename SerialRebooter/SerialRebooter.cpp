// Serial Rebooter class
// file: SerialRebooter.cpp
// Author: Bruno Knopki Nery
#include "SerialRebooter.h"
#include <cstdlib>

SerialRebooter::SerialRebooter(std::string initSerialDevice, int initTotalReboots, int initWait, std::string initPrompt){
	serialDevice = initSerialDevice;
	totalReboots = initTotalReboots;
	wait = initWait;
	prompt = initPrompt;
}

void SerialRebooter::start(void){

	std::cout << "Configure equipment under test and press any key to start the test:" << std::endl;
	std::in >> key;
	std::out << "Test starting..." << std::endl;


}

int Dice::getSideUp(void){
	return sideUp;
}

Dice::~Dice(){
	sideUp = 1;
}
