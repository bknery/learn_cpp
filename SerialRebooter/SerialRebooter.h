// Serial Rebooter header
// file: SerialRebooter.h
// Author: Bruno Knopki Nery
#ifndef SERIAL_REBOOTER_H
#define SERIAL_REBOOTER_H

#include <string>

class SerialRebooter {
public:
	SerialRebooter(std::string init_serial_device,
					int initTotalReboots,
					int init_wait,
					std::string init_reboot_cmd,
					std::string init_prompt);
	~SerialRebooter();
	int Start(void);
	int GetResult(void);
private:
	std::string serial_device_;
	int total_reboots_;
	int wait_;
	std::string reboot_cmd_;
	std::string prompt_;
	int result_;
};

#endif // SERIAL_REBOOTER_H
