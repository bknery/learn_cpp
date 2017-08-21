OBJS = thread_example.o
CPP = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++11
LFLAGS = -Wall $(DEBUG)

thread_example: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o thread_example -lpthread

thread_example.o: thread_example.cc
	$(CPP) $(CFLAGS) thread_example.cc

clean:
	rm *.o thread_example
