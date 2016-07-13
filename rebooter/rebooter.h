// Serial Rebooter header
// file: rebooter.h
// Author: Bruno Knopki Nery
#ifndef REBOOTER_H
#define REBOOTER_H

#include <string>

class Rebooter {
public:
	Rebooter(std::string serial_device,
				int total_reboots,
				int wait,
				std::string reboot_cmd,
				std::string find_pattern);
	Rebooter(std::string serial_device,
				int total_reboots,
				int wait,
				std::string uriel_device,
				int uriel_port,
				int off_time_ms,
				std::string find_pattern);
	Rebooter(std::string serial_device,
				int total_reboots,
				int wait,
				std::string parport_device,
				int off_time_ms,
				std::string find_pattern);
	~Rebooter();
	int Start(void);
	int GetResult(void);
	void print_config(void);
	enum RebootDevice { SERIAL_CMD, URI_EL, PARPORT};
private:
	std::string serial_device_;
	int total_reboots_;
	int wait_;
	Rebooter::RebootDevice reboot_device_;
	std::string reboot_cmd_;
	std::string uriel_device_;
	std::string parport_device_;
	int uriel_port_;
	int off_time_ms_;
	std::string find_pattern_;
	int result_;
	int reboot(void);
};

#endif // REBOOTER_H
