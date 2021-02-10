//File: timeType.h
//Author: Pengfei Huang
//Date: 03/26/2018

// Description
// This file contains the specification for a timeType class

#ifndef _TIMETYPE_H_
#define _TIMETYPE_H_
#include <iostream>
using namespace std;
//preconditions: time is correct
class timeType{
  public:
    // method - timeType
    // description - construct a new timeType object 
    // preconditions - none
    // postconditions - timeType object created and the argument default by 0  
    // method input - none
    // method output - none
    timeType();
    
    // method - timeType
    // description - construct a new timeType object
    // preconditions - time is correct ,int hours and int minutes
    // postconditions - timeType object created with the hours and minutes
    // method input - int hours and int minutes
    // method output - none
    timeType(int hours, int minutes);
    
    // method - setTime
    // description - sets the time of the timeType object
    // preconditions - timeType object has been initialized and hours is int and munutes is int
    // postconditions - timeType object time set 
    // method input - hour of the time : int and minutes of the time : int
    // method output - none
    void setTime(int hours, int minutes);
    
    // method - getHours
    // description - returns the hours of the timeType object
    // preconditions - timeType object has been initialized
    // postconditions - timeType object hours is returned 
    // method input - none
    // method output - hours of the timeType : int
    int getHours() const;
    
    // method - getMinutes
    // description - returnnones the minutes of the timeType object
    // preconditions - timeType object has been initialized
    // postconditions - timeType object minutes is returned 
    // method input - none
    // method output - minutes of the timeType : int
    int getMinutes() const;
    
    // method - print
    // description - print out the timeType in the format
    // preconditions - timeType object has been initialized
    // postconditions - the timeType is showing in the screen with the correct format
    // method input - none
    // method output - none 
    void print() const;
    
    // method - poperator==
    // description - compare with two timeType, return true if the timeType is equal to the other, otherwise false will be return(0)
    // preconditions - must be a timeType
    // postconditions - a true(1) will be return if the timeType is equal to the other, otherwise false will be return(0)
    // method input - timeType
    // method output - bool
    bool operator==(const timeType&) const;
    
    // method - poperator!=
    // description - compare with two timeType, return true if the timeType is not equal to the other, otherwise false will be return(0)
    // preconditions - must be a timeType
    // postconditions - a true(1) will be return if the timeType is not equal to the other, otherwise false will be return(0)
    // method input - timeType
    // method output - bool
    bool operator!=(const timeType&) const;
    
    // method - poperator<
    // description - compare with two timeType, return true if the timeType is greater than the other, otherwise false will be return(0)
    // preconditions - must be a timeType
    // postconditions - a true(1) will be return if the timeType is greater than  the other, otherwise false will be return(0)
    // method input - timeType
    // method output - bool
    bool operator<(const timeType&) const;
    
    // method - poperator<=
    // description - compare with two timeType, return true if the timeType is greater than or equal to the other, otherwise false will be return(0)
    // preconditions - must be a timeType
    // postconditions - a true(1) will be return if the timeType is greater than or equal to the other, otherwise false will be return(0)
    // method input - timeType
    // method output - bool
    bool operator<=(const timeType&) const;
    
    // method - poperator>=
    // description - compare with two timeType, return true if the timeType is less than or equal to the other, otherwise false will be return(0)
    // preconditions - must be a timeType
    // postconditions - a true(1) will be return if the timeType is less than or equal to the other, otherwise false will be return(0)
    // method input - timeType
    // method output - bool
    bool operator>=(const timeType&) const;
    
    // method - poperator>
    // description - compare with two timeType, return true if the timeType is less than  the other, otherwise false will be return(0)
    // preconditions - must be a timeType
    // postconditions - a true(1) will be return if the timeType is less than  the other, otherwise false will be return(0)
    // method input - timeType
    // method output - bool
    bool operator>(const timeType&) const;
  private:
    
    int hours; // the hours of the time
    int minutes; // the minutes of the time
  
  
};
    // method - poperator>>
    // description - read from the istream and creat a timeType with the data was read from istream
    // preconditions - must be a istream and timeType
    // postconditions - a timeType will be creat base on the istream data
    // method input - istream and timeType
    // method output - istream
istream& operator>>(istream&,timeType&);  

    // method - poperator<<
    // description - output the ostream from date timeType 
    // preconditions - must be a ostream and timeType
    // postconditions - a output will be made base on the timeType
    // method input - ostream and timeType
    // method output - ostream
ostream& operator<<(ostream&,const timeType&);
#endif