// Dice class
// file: dice.cpp
// Author: Bruno Knopki Nery
#include "dice.h"
#include <cstdlib>
#include <ctime>

struct Dice_hl::Dice {
	int sideUp;
};

int Dice_hl::initialize(int side){
	dice_ptr = new Dice;
	if((side > 0) && (side < 7)){
		dice_ptr->sideUp = side;
		return 0;
	} else {
		// Error
		dice_ptr->sideUp = 1;
		return -1;
	}
}

void Dice_hl::draw(void){
	std::srand(std::time(NULL)); // use current time as seed
	dice_ptr->sideUp = std::rand() % 6 + 1; // random number between 1 and 6
}

int Dice_hl::getSideUp(void){
	return dice_ptr->sideUp;
}

void Dice_hl::cleanup(void){
	delete dice_ptr;
}
