OBJECTS=main.o timeType.o dateType.o personType.o studentType.o read.o output.o 
CC=g++
EXE=prog10
CFLAGS=-Wall
LFLAGS=
$(EXE):         $(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:         main.cpp timeType.h listType.h
		$(CC) $(CFLAGS) -c main.cpp
		
timeType.o:     timeType.cpp timeType.h
		$(CC) $(CFLAGS) -c timeType.cpp

dateType.o:     dateType.cpp dateType.h
		$(CC) $(CFLAGS) -c dateType.cpp
		
studentType.o:  studentType.cpp studentType.h listType.h
		$(CC) $(CFLAGS) -c studentType.cpp

personType.o:   personType.cpp personType.h listType.h
		$(CC) $(CFLAGS) -c personType.cpp
		
read.o:		read.cpp  studentType.h listType.h
		$(CC) $(CFLAGS) -c read.cpp

output.o:	output.cpp studentType.h listType.h
		$(CC) $(CFLAGS) -c output.cpp
# This cleans out the directory before handing it in
clean:
		rm -rf $(OBJECTS)  $(EXE) *~
