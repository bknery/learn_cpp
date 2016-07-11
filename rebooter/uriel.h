// URI-EL header
// file: uriel.h
// Author: Bruno Knopki Nery
#ifndef URIEL_H
#define URIEL_H

#include <string>

class Uriel {
public:
	Uriel(std::string uriel_device);
	int On(int port);
	int Off(int port);
private:
	std::string uriel_device_;
	const char uriel_on_cmd_[5] = {'#', 0x01, 0x06, 0x01, '*'};
	const char uriel_off_cmd_[5] = {'#', 0x01, 0x06, 0x00, '*'};
};

#endif // URIEL_H
