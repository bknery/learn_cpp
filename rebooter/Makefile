OBJS = rebooter_cmd.o rebooter.o serial_checker.o serial_cmd_sender.o uriel.o parport_controller.o
CPP = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++11
LFLAGS = -Wall $(DEBUG)

auto_rebooter: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o auto_rebooter

rebooter_cmd.o: rebooter_cmd.cpp rebooter_cmd.h
	$(CPP) $(CFLAGS) rebooter_cmd.cpp

rebooter.o: rebooter.cpp rebooter.h
	$(CPP) $(CFLAGS) rebooter.cpp

serial_checker.o: serial_checker.cpp serial_checker.h
	$(CPP) $(CFLAGS) serial_checker.cpp

serial_cmd_sender.o: serial_cmd_sender.cpp serial_cmd_sender.h
	$(CPP) $(CFLAGS) serial_cmd_sender.cpp

uriel.o: uriel.cpp uriel.h
	$(CPP) $(CFLAGS) uriel.cpp
	
parport_controller.o: parport_controller.c parport_controller.h
	$(CPP) $(CFLAGS) parport_controller.c

clean:
	rm *.o auto_rebooter
