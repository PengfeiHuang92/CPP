OBJECTS=main.o timeType.o dateType.o
CC=g++
EXE=prog7
CFLAGS=-Wall
LFLAGS=
$(EXE):         $(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:         main.cpp timeType.h
		$(CC) $(CFLAGS) -c main.cpp
		
timeType.o:     timeType.cpp timeType.h
		$(CC) $(CFLAGS) -c timeType.cpp

dateType.o:     dateType.cpp dateType.h
		$(CC) $(CFLAGS) -c dateType.cpp

# This cleans out the directory before handing it in
clean:
		rm -rf $(OBJECTS) $(EXE) *~
