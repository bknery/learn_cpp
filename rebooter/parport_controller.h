// Parport Controller header
// file: parport_controller.h
// Author: Bruno Knopki Nery
#ifndef PARPORT_CONTROLLER_H
#define PARPORT_CONTROLLER_H

int parport_on(const char *parport_device);
int parport_off(const char *parport_device);

#endif // PARPORT_CONTROLLER_H
