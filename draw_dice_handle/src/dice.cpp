// Dice class
// file: dice.cpp
// Author: Bruno Knopki Nery
#include "dice.h"
#include <cstdlib>
#include <ctime>

int Dice::init(int side){
	if((side > 0) && (side < 7)){
		sideUp = side;
		return 0;
	} else {
		// Error
		return -1;
	}
}

void Dice::draw(void){
	std::srand(std::time(0)); // use current time as seed
	sideUp = std::rand() % 6 + 1; // random number between 1 and 6
}

int Dice::getSideUp(void){
	return sideUp;
}
