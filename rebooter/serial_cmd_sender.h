// Serial Command Sender header
// file: serial_cmd_sender.h
// Author: Bruno Knopki Nery
#ifndef SERIAL_CMD_SENDER_H
#define SERIAL_CMD_SENDER_H

#include <string>

class SerialCmdSender {
public:
	SerialCmdSender(std::string init_serial_device);
	~SerialCmdSender();
	int Send(std::string cmd);
private:
	std::string serial_device_;
	std::ofstream serial_wr;
};

#endif // SERIAL_CMD_SENDER_H
