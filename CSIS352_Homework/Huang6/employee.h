#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream>
#include <string>
#include "person.h"
#include "date.h"
class Employee : public Person{
public:
    // method - default constructor
    // description - created the Employee object with n(name), d(birthday), eid(employeeId),s(ssn)
    // preconditions - none
    // postconditions - a Employee object was created
    // method input - string name n, date birthday d, int employeeId eid and string ssn s
    // method output - none   
    Employee(string n, Date d, int eid,string s,string identifier);
    // method - setEmployeeId
    // description - set the Employee id by the argument
    // preconditions - int eid and a Employee object was created
    // postconditions - the employeeId was set by the argument 
    // method input - int employeeId
    // method output - none
    void setEmployeeId(int);
    // method - getEmployeeId
    // description - gets the employeeId of the Employee object
    // preconditions - Employee object was created
    // postconditions - the employeeId of the Employee object was returned
    // method input - none 
    // method output - int 
    int getEmployeeId();
    // method - setSSN
    // description - set the Employee ssn by the argument
    // preconditions - string ssn and a Employee object was created
    // postconditions - the ssn was set by the argument 
    // method input - string ssn
    // method output - none
    void setSSN(string);
    // method - getSSN
    // description - gets the ssn of the Employee object
    // preconditions - Employee object was created
    // postconditions - the ssn of the Employee object was returned
    // method input - none 
    // method output - string 
    string getSSN();
    // method - setSSN
    // description - set the Employee identifier by the argument
    // preconditions - string identifier and a Employee object was created
    // postconditions - the identifier was set by the argument 
    // method input - string identifier
    // method output - none
    void setIdentifier(string);
    // method - getIndentifier
    // description - gets the identifier of the Employee object
    // preconditions - Employee object was created
    // postconditions - the identifier of the Employee object was returned
    // method input - none 
    // method output - string 
    string getIndentifier();
	virtual int getHour(){return 0;};
//  virtual int getHour() const = 0;
    virtual int getSalary(){return 0;};
    virtual double getWage(){return 0;};
private:
   int employeeId;    //Employee id 
   string ssn;     //social security number
   string identifier;
};

#endif
