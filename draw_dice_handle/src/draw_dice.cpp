// Draw a dice
// file: draw_dice.cpp
// Author: Bruno Knopki Nery
#include "dice.h"
#include <iostream>

int main(){
	Dice_hl dice;
	dice.initialize(1);
	std::cout << "Your new dice has " << dice.getSideUp() << " up" << std::endl;
	std::cout << "Drawing...\n";
	dice.draw();
	std::cout << "Side up: " << dice.getSideUp() << std::endl;
	dice.cleanup();
}
