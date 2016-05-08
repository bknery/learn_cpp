// Dice interface
// file: dice.h
// Author: Bruno Knopki Nery
#ifndef DICE_H
#define DICE_H

class Dice_hl {
	struct Dice;
	Dice* dice_ptr;
public:
	int initialize(int side);
	void draw(void);
	int getSideUp(void);
	void cleanup(void);
};

#endif // DICE_H
