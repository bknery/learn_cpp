// Dice class
// file: dice.cpp
// Author: Bruno Knopki Nery
#include "dice.h"
#include <cstdlib>

Dice::Dice(int initSide){
	if((initSide > 0) && (initSide < 7)){
		sideUp = initSide;
	} else {
		sideUp = 1;
	}
}

void Dice::draw(void){
	//std::srand(std::time(0)); // use current time as seed
	sideUp = std::rand() % 6 + 1; // random number between 1 and 6
}

int Dice::getSideUp(void){
	return sideUp;
}

Dice::~Dice(){
	sideUp = 1;
}
