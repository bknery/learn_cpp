// Parallel port controller
// file: parport_controller.c
// Author: Bruno Knopki Nery
#include "parport_controller.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/ppdev.h>
#include <sys/ioctl.h>

int parport_on(const char *parport_device) {

	int fd;
	unsigned char on_data = 0xff;
	

    fd = open (parport_device, O_RDWR);
    if (fd == -1) {
        printf("ERROR opening parallel port device\n");
        return -1;
    }

	if(ioctl (fd, PPCLAIM)) {
        printf("ERROR claiming parallel port device\n");
        close(fd);
        return -1;
    }
	
	if (ioctl(fd, PPWDATA, &on_data) < 0) {
        printf("ERROR writing to parallel port\n");
        close(fd);
        return -1;
	}

    close(fd);
	return 0;
}

int parport_off(const char *parport_device) {

	int fd;
	unsigned char off_data = 0x00;
	

    fd = open (parport_device, O_RDWR);
    if (fd == -1) {
        printf("ERROR opening parallel port device\n");
        return -1;
    }

	if(ioctl (fd, PPCLAIM)) {
        printf("ERROR claiming parallel port device\n");
        close(fd);
        return -1;
    }
	
	if (ioctl(fd, PPWDATA, &off_data) < 0) {
        printf("ERROR writing to parallel port\n");
        close(fd);
        return -1;
	}

    close(fd);
	return 0;
}
