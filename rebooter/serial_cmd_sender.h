// Serial Command Sender header
// file: serial_cmd_sender.h
// Author: Bruno Knopki Nery
#ifndef SERIAL_CMD_SENDER_H
#define SERIAL_CMD_SENDER_H

#include <string>
#include <iostream>
#include <fstream>

class SerialCmdSender {
public:
	SerialCmdSender(std::string serial_device);
	~SerialCmdSender();
	int Send(std::string cmd);
private:
	std::string serial_device_;
};

#endif // SERIAL_CMD_SENDER_H
