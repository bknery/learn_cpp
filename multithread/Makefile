OBJS = multithread.o simple_thread.o
CPP = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pthread -std=c++11
LFLAGS = -Wall $(DEBUG) -pthread

multithread: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o multithread

multithread.o: multithread.cpp
	$(CPP) $(CFLAGS) multithread.cpp

simple_thread.o: simple_thread.cpp simple_thread.h
	$(CPP) $(CFLAGS) simple_thread.cpp

clean:
	rm *.o multithread
