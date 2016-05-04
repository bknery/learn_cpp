OBJS = hello_world.o
CPP = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

SRC_PATH = ./src

hello_world: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o hello_world

hello_world.o: $(SRC_PATH)/hello_world.cpp
	$(CPP) $(CFLAGS) $(SRC_PATH)/hello_world.cpp

clean:
	rm *.o hello_world
