#ifndef _Employees_H_
#define _Employees_H_
#include <iostream>
#include <list>
#include "employee.h"
class Employees{
	public:
        // method - default constructor
        // description - created the Employees object 
        // preconditions - none
        // postconditions - a Employees object was created
        // method input - none
        // method output - none 
	    Employees();
        // method - push_back
        // description - insert the new Employee pointer to the list
        // preconditions - Employee pointer and a Person object was created
        // postconditions - the Employee pointer was inserted into the list
        // method input - Employee pointer 
        // method output - none 
	    void push_back(Employee*);
        // method - getEmployee
        // description - return Employee pointer by the id
        // preconditions - Employee pointer and a Person object was created
        // postconditions - the Employee pointer was return
        // method input - int index
        // method output - Employee pointer
	    Employee* getEmployee(int);
	int listSize() const;
	    
	private:
	    list<Employee*> group;    //list of the Employee pointer
};



#endif
