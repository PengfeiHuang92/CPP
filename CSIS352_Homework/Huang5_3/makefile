#File:   makefile
#Author: Pengfei Huang

#Description
#This makefile will make the graph class

CC=g++
OBJECTS=main.o city.o
EXE=prog5
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
city.o:		city.cpp city.h
			$(CC) $(CFLAGS) -c city.cpp
main.o: 	main.cpp city.h graph.h
			$(CC) $(CFLAGS) -c main.cpp
clean:
		rm -rf prog5 *~ $(OBJECTS) $(EXE)

