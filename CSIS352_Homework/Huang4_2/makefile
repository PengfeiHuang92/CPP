#File:   makefile
#Author: Pengfei Huang

#Description
#This makefile will make the sortedList class

CC=g++
OBJECTS=main.o
EXE=prog4
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
main.o: 	main.cpp sortedList.h
			$(CC) $(CFLAGS) -c main.cpp

clean:
		rm -rf prog4 *~ $(OBJECTS) $(EXE)

