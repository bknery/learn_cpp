OBJS = SerialRebooterCmd.o SerialRebooter.o
CPP = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++11
LFLAGS = -Wall $(DEBUG)

SerialRebooterCmd: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o SerialRebooterCmd

SerialRebooterCmd.o: SerialRebooterCmd.cpp SerialRebooterCmd.h
	$(CPP) $(CFLAGS) SerialRebooterCmd.cpp

SerialRebooter.o: SerialRebooter.cpp SerialRebooter.h
	$(CPP) $(CFLAGS) SerialRebooter.cpp

clean:
	rm *.o SerialRebooterCmd
