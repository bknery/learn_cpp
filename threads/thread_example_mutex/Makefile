OBJS = mutex_example.o
CPP = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++11
LFLAGS = -Wall $(DEBUG)

mutex_example: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o mutex_example -lpthread

mutex_example.o: mutex_example.cc
	$(CPP) $(CFLAGS) mutex_example.cc

clean:
	rm -rf *.o mutex_example
