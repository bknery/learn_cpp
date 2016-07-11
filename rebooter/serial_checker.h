// Serial Rebooter header
// file: serial_checker.h
// Author: Bruno Knopki Nery
#ifndef SERIAL_CHECKER_H
#define SERIAL_CHECKER_H

#include <string>

class SerialChecker {
public:
	SerialChecker(std::string serial_device,
					bool log_serial,
					std::string find_pattern);
	~SerialChecker();
	int Config(void);
	int InitCheckPattern(void);
private:
	std::string serial_device_;
	std::string find_pattern_;
	int result_;
	bool log_serial_;
};

#endif // SERIAL_CHECKER_H
