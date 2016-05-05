OBJS = draw_dice.o dice.o
CPP = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

SRC_PATH = ./src

draw_dice: $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o draw_dice

draw_dice.o: $(SRC_PATH)/draw_dice.cpp $(SRC_PATH)/dice.h
	$(CPP) $(CFLAGS) $(SRC_PATH)/draw_dice.cpp

dice.o: $(SRC_PATH)/dice.cpp $(SRC_PATH)/dice.h
	$(CPP) $(CFLAGS) $(SRC_PATH)/dice.cpp

clean:
	rm *.o draw_dice
