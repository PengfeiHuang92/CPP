#File:   makefile
#Author: Pengfei Huang

#Description
#This makefile will make the Array class

CC=g++
OBJECTS=main.o
EXE=prog3
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
main.o: 	main.cpp array.h
			$(CC) $(CFLAGS) -c main.cpp

clean:
		rm -rf prog3 *~ $(OBJECTS) $(EXE)

