#File:   makefile
#Author: Pengfei Huang

#Description
#This makefile will make the hashtable classes

CC=g++
OBJECTS=main.o symbol.o hashfunctions.o
EXE=prog7
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
symbol.o: 	symbol.cpp symbol.h
		$(CC) $(CFLAGS) -c symbol.cpp
hashfunctions.o: 	hashfunctions.cpp
		$(CC) $(CFLAGS) -c hashfunctions.cpp
main.o: 	main.cpp symbol.h hashtable.h 
		$(CC) $(CFLAGS) -c main.cpp
clean:
		rm -rf prog7 *~ $(OBJECTS) $(EXE)

