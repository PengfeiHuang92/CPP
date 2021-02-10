OBJECTS=main.o baseConvert.o
CC=g++
EXE=prog11
CFLAGS=-Wall
LFLAGS=
$(EXE):         $(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:         main.cpp stackType.h queueType.h
		$(CC) $(CFLAGS) -c main.cpp
		

baseConvert.o:  baseConvert.cpp stackType.h queueType.h
		$(CC) $(CFLAGS) -c baseConvert.cpp

# This cleans out the directory before handing it in
clean:
		rm -rf $(OBJECTS)  $(EXE) *~
