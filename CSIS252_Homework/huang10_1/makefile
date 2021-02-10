OBJECTS=main.o dateType.o personType.o read.o
CC=g++
EXE=prog10
CFLAGS=-Wall
LFLAGS=
$(EXE):         $(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:         main.cpp listType.h
		$(CC) $(CFLAGS) -c main.cpp

dateType.o:     dateType.cpp dateType.h
		$(CC) $(CFLAGS) -c dateType.cpp

personType.o:   personType.cpp personType.h
		$(CC) $(CFLAGS) -c personType.cpp
	
studentType.o:  studentType.cpp studentType.h listType.h
		$(CC) $(CFLAGS) -c studentType.cpp		
read.o:   	read.cpp listType.h
		$(CC) $(CFLAGS) -c read.cpp
# This cleans out the directory before handing it in
clean:
		rm -rf $(OBJECTS) $(EXE) *~
