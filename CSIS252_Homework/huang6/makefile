OBJECTS=main.o sort.o read.o getGrade.o getAvg.o getMed.o getScore.o outputScores.o getStandardDeviation.o outputSummary.o
CC=g++
EXE=prog6
CFLAGS=-Wall
LFLAGS=
$(EXE):         $(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:         main.cpp constants.h
		$(CC) $(CFLAGS) -c main.cpp
		
outputScores.o:     outputScores.cpp
		$(CC) $(CFLAGS) -c outputScores.cpp
		
sort.o:         sort.cpp
		$(CC) $(CFLAGS) -c sort.cpp

read.o:         read.cpp constants.h
		$(CC) $(CFLAGS) -c read.cpp

getGrade.o:     getGrade.cpp constants.h
		$(CC) $(CFLAGS) -c getGrade.cpp

getAvg.o:       getAvg.cpp
		$(CC) $(CFLAGS) -c getAvg.cpp

output.o:       output.cpp
		$(CC) $(CFLAGS) -c output.cpp

getMed.o:       getMed.cpp
		$(CC) $(CFLAGS) -c getMed.cpp

getScore.o:     getScore.cpp
		$(CC) $(CFLAGS) -c getScore.cpp



outputSummary.o:    outputSummary.cpp
		$(CC) $(CFLAGS) -c outputSummary.cpp

getStandardDeviation.o:	getStandardDeviation.cpp
		$(CC) $(CFLAGS) -c getStandardDeviation.cpp

# This cleans out the directory before handing it in
clean:
		rm -rf $(OBJECTS) $(EXE) *~
