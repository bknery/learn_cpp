OBJS = main_file.o print_hello.o
CPP = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

SRC_PATH = ./src

two_files: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o two_files

main_file.o: $(SRC_PATH)/main_file.cpp $(SRC_PATH)/print_hello.h
	$(CPP) $(CFLAGS) $(SRC_PATH)/main_file.cpp

print_hello.o: $(SRC_PATH)/print_hello.cpp $(SRC_PATH)/print_hello.h
	$(CPP) $(CFLAGS) $(SRC_PATH)/print_hello.cpp

clean:
	rm *.o two_files
