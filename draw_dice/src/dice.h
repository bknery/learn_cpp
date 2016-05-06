// Dice interface
// file: dice.h
// Author: Bruno Knopki Nery
#ifndef DICE_H
#define DICE_H

class Dice {
private:
	int sideUp;
public:
	int init(int side);
	void draw(void);
	int getSideUp(void);
};

#endif // DICE_H
