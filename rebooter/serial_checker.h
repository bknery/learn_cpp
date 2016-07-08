// Serial Rebooter header
// file: serial_checker.h
// Author: Bruno Knopki Nery
#ifndef SERIAL_CHECKER_H
#define SERIAL_CHECKER_H

#include <string>

class SerialChecker {
public:
	SerialChecker(std::string init_serial_device,
					bool init_log_serial,
					std::string init_find_pattern);
	~SerialChecker();
	int Config(void);
	int InitCheckPattern(void);
private:
	std::string serial_device_;
	std::string find_pattern_;
	int result_;
	bool log_serial_,
};

#endif // SERIAL_CHECKER_H
