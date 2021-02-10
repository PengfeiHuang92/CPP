#File:   makefile
#Author: Pengfei Huang

#Description
#This makefile will make the Person, Employee, HourlyEmployee, SalaryEmployee,SalaryEmployee, and Employees classes

CC=g++
OBJECTS=main.o date.o person.o employee.o hourlyemployee.o salaryemployee.o read.o employees.o
EXE=prog6
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
date.o: 	date.cpp date.h
		$(CC) $(CFLAGS) -c date.cpp
person.o: 	person.cpp person.h date.h
		$(CC) $(CFLAGS) -c person.cpp
employee.o: 	employee.cpp employee.h person.h
		$(CC) $(CFLAGS) -c employee.cpp
hourlyemployee.o: 	hourlyemployee.cpp hourlyemployee.h employee.h person.h
		$(CC) $(CFLAGS) -c hourlyemployee.cpp
salaryemployee.o: 	salaryemployee.cpp salaryemployee.h employee.h person.h
		$(CC) $(CFLAGS) -c salaryemployee.cpp	
employees.o: 	employees.cpp employees.h
		$(CC) $(CFLAGS) -c employees.cpp
read.o:		read.cpp 
		$(CC) $(CFLAGS) -c read.cpp
main.o: 	main.cpp date.h person.h employee.h hourlyemployee.h salaryemployee.h #employees.h
		$(CC) $(CFLAGS) -c main.cpp
clean:
		rm -rf prog6 *~ $(OBJECTS) $(EXE)

