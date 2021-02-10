#ifndef _HOURLYEMPLOYEE_H_
#define _HOURLYEMPLOYEE_H_

#include <iostream>
#include <string>
#include "employee.h"
#include "date.h"
class HourlyEmployee:public Employee{
public:
    // method - default constructor
    // description - created the HourlyEmployee object with name n, birthday d employee id eid, ssn s, hour h, and wage w
    // preconditions - none
    // postconditions - a HourlyEmployee object was created
    // method input -  name n, birthday d employee id eid, ssn s, hour h, and wage w
    // method output - none   
    HourlyEmployee(string n, Date d, int eid,string s, int h, double w);
    // method - setHour
    // description - set the hour by the argument
    // preconditions - int hour and a HourlyEmployee object was created
    // postconditions - the hour was set by the argument 
    // method input - int hour 
    // method output - none 
    void setHour(int);
    // method - getHour
    // description - gets the hour of the HourlyEmployee object
    // preconditions - HourlyEmployee object was created
    // postconditions - the hour of the HourlyEmployee object was returned
    // method input - none 
    // method output - int 
    int getHour();
    // method - setWage
    // description - set the wage by the argument
    // preconditions - int wage and a HourlyEmployee object was created
    // postconditions - the wage was set by the argument 
    // method input - double wage 
    // method output - none 
    void setWage(double);
    // method - getWage
    // description - gets the wage of the HourlyEmployee object
    // preconditions - HourlyEmployee object was created
    // postconditions - the wage of the HourlyEmployee object was returned
    // method input - none 
    // method output - int 
    double getWage();

    virtual int getSalary(){return 0;};
    
private:
   int hour;    //working hours
   double wage;   //payrate
   
};
#endif

