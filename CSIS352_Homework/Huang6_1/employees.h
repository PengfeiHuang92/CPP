#ifndef _Employees_H_
#define _Employees_H_
#include <iostream>
#include <list>
#include "employee.h"
class Employees{
	public:
   
	    Employees();
	    void push_back(Employee*);
	    Employee* getEmployee(int);
	    
	private:
	    list<Employee*> group;
};



#endif
