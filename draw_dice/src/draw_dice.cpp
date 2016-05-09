// Draw a dice
// file: draw_dice.cpp
// Author: Bruno Knopki Nery
#include "dice.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]){
	int n = 1;
	std::srand(std::time(0)); // use current time as seed
	if(argc == 1){
		std::cout << "1 dice" << std::endl;
		std::cout << "For more dices use: draw_dice <num_dices>" << std::endl;
	} else {
		n = std::stoi(argv[1]);
		std::cout << n << " dices" << std::endl;
	}

	std::vector<Dice> dices;
	for(int i = 0; i < n; i++){ // initialize vector with dices
		dices.push_back(Dice(i));
		std::cout << "dice " << i << " has " << dices[i].getSideUp() << " up" << std::endl;
	}
	std::cout << "Throwing " << n << " dices...\n";
	for(int i = 0; i < n; i++){
		dices[i].draw();
		std::cout << "dice " << i << " side up: " << dices[i].getSideUp() << std::endl;
	}
}
