// URI-EL header
// file: uriel.h
// Author: Bruno Knopki Nery
#ifndef URIEL_H
#define URIEL_H

#include <string>

class Uriel {
public:
	Uriel(std::string init_uriel_device);
	~Uriel();
	int On(void);
	int Off(void);
private:
	std::string uriel_device_;
	std::ofstream serial_wr;
};

#endif // URIEL_H
