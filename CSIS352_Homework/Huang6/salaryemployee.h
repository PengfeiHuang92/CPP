#ifndef _SALARYEMPLOYEE_H_
#define _SALARYEMPLOYEE_H_

#include <iostream>
#include <string>
#include "employee.h"
#include "date.h"
class SalaryEmployee:public Employee{
public:
    // method - default constructor
    // description - created the SalaryEmployee object with n(name), d(birthday), eid(employeeId),s(ssn) salary(salary)
    // preconditions - none
    // postconditions - a SalaryEmployee object was created
    // method input - string name n, date birthday d, int employeeId eid, string ssn s and int salary
    // method output - none  
    SalaryEmployee(string n, Date d, int eid, string s,string ide, int sa);
    // method - setSalary
    // description - set the salary by the argument
    // preconditions - int salary and a SalaryEmployee object was created
    // postconditions - the salary was set by the argument 
    // method input - int salary
    // method output - none
    void setSalary(int);
    // method - getSalary
    // description - get the salary of the SalaryEmployee
    // preconditions - none
    // postconditions - the salary was returned 
    // method input - none
    // method output - int 
    int getSalary();
   	virtual int getHour(){return 0;};
    
    virtual double getWage(){return 0;};
private:
   int salary;    //the salary of the SalaryEmployee
};

#endif
