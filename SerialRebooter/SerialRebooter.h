// Serial Rebooter header
// file: SerialRebooter.h
// Author: Bruno Knopki Nery
#ifndef SERIAL_REBOOTER_H
#define SERIAL_REBOOTER_H

#include <string>

class SerialRebooter {
public:
	SerialRebooter(std::string init_serial_device,
					int init_total_reboots,
					int init_wait,
					std::string init_reboot_cmd,
					std::string init_find_pattern);
	SerialRebooter(std::string init_serial_device,
					int init_total_reboots,
					int init_wait,
					std::string init_uri_device,
					int init_uri_port,
					int init_off_time_ms,
					std::string init_find_pattern);
	~SerialRebooter();
	int Start(void);
	int GetResult(void);
	void print_config(void);
	enum RebootDevice { SERIAL_CMD, URI_EL};
	const char uri_on_cmd_[5] = {'#', 0x01, 0x06, 0x01, '*'};
	const char uri_off_cmd_[5] = {'#', 0x01, 0x06, 0x00, '*'};
private:
	std::string serial_device_;
	int total_reboots_;
	int wait_;
	SerialRebooter::RebootDevice reboot_device_;
	std::string reboot_cmd_;
	std::string find_pattern_;
	std::string uri_device_;
	int uri_port_;
	int off_time_ms_;
	int result_;
	int reboot(void);
	int turn_uriel_on(void);
	int turn_uriel_off(void);
};

#endif // SERIAL_REBOOTER_H
