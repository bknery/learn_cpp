OBJS = parport.o parport_controller.o
CPP = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++11
LFLAGS = -Wall $(DEBUG)
PARPORT_CONTROLLER_PATH = ../rebooter/

parport: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o parport

parport.o: parport.cpp parport.h
	$(CPP) $(CFLAGS) parport.cpp

parport_controller.o: $(PARPORT_CONTROLLER_PATH)parport_controller.c $(PARPORT_CONTROLLER_PATH)parport_controller.h
	$(CPP) $(CFLAGS) $(PARPORT_CONTROLLER_PATH)parport_controller.c -o parport_controller.o

clean:
	rm *.o parport
