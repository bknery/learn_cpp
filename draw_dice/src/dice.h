// Dice interface
// file: dice.h
// Author: Bruno Knopki Nery
#ifndef DICE_H
#define DICE_H

struct Dice {
	int sideUp;
	int init(int side);
	void draw(void);
	int getSideUp(void);
};

#endif // DICE_H
