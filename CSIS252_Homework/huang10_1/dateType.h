//File: dateType.h
//Author: Pengfei Huang
//Date: 03/26/2018

// Description
// This file contains the specification for a dateType class

#ifndef _DATETYPE_H_
#define _DATETYPE_H_
#include <iostream>
using namespace std;
//preconditions: the date is correct
class dateType{
  public:
    // method - dateType
    // description - construct a new timeType object 
    // preconditions - none
    // postconditions - dateType object created and set the date month to 1, the day to 1 and the year to 2000
    // method input - none
    // method output - none
    dateType();

    // method - dateType
    // description - construct a new timeType object 
    // preconditions - date is correct the month, day and year are int
    // postconditions - dateType created and initialized the month to month, the day to the day and the year to year
    // method input - int month, int day and int year
    // method output - none   
    dateType(int month, int day, int year);

    // method - setDate
    // description - set the date month, day and year
    // preconditions - date is correct the month, day and year are int
    // postconditions - initialized the month to month, the day to the day and the year to year
    // method input - int month, int day and int year
    // method output - none     
    void setDate(int month, int day, int year);

    // method - getYear
    // description - get the year of the date
    // preconditions - date object has been initialized
    // postconditions - return the year of the date
    // method input - none
    // method output - year of the date : int  
    int getYear() const;
    
    // method - getMonth
    // description - get the month of the date
    // preconditions - date object has been initialized
    // postconditions - return the month of the date
    // method input - none
    // method output - month of the date : int  
    int getMonth() const;
    
    // method - getDay
    // description - get the day of the date
    // preconditions - date object has been initialized
    // postconditions - return the day of the date
    // method input - none
    // method output - day of the date : int 
    int getDay() const;

    // method - print
    // description - print the date in the right format: month day, year
    // preconditions - date object has been initialized
    // postconditions - the date is showing in the screen with the right format
    // method input - none
    // method output - none
    void print() const;
    
    // method - poperator==
    // description - compare with two dateType return true if they equal
    // preconditions - must be a dateType
    // postconditions - a true(1) will be return if the two dateType are the same, otherwise false will be return(0)
    // method input - dateType
    // method output - bool
    bool operator==(const dateType&) const;
    
    // method - poperator!=
    // description - compare with two dateType return true if they do not equal
    // preconditions - must be a dateType
    // postconditions - a true(1) will be return if the two dateType are not the same, otherwise false will be return(0)
    // method input - dateType
    // method output - bool
    bool operator!=(const dateType&) const;
    
    // method - poperator<
    // description - compare with two dateType return true if the dateType is less than the other, otherwise false will be return(0)
    // preconditions - must be a dateType
    // postconditions - a true(1) will be return if the dateType is less than the other, otherwise false will be return(0)
    // method input - dateType
    // method output - bool
    bool operator<(const dateType&) const;
    
    // method - poperator<=
    // description - compare with two dateType return true if the dateType is less than or equal to the other, otherwise false will be return(0)
    // preconditions - must be a dateType
    // postconditions - a true(1) will be return if the dateType is less than or equal to the other, otherwise false will be return(0)
    // method input - dateType
    // method output - bool
    bool operator<=(const dateType&) const;
    
    // method - poperator>=
    // description - compare with two dateType return true if the dateType is greater than or equal to the other, otherwise false will be return(0)
    // preconditions - must be a dateType
    // postconditions - a true(1) will be return if the dateType is greater than or equal to the other, otherwise false will be return(0)
    // method input - dateType
    // method output - bool
    bool operator>=(const dateType&) const;
    
    // method - poperator>
    // description - compare with two dateType return true if the dateType is greater than the other, otherwise false will be return(0)
    // preconditions - must be a dateType
    // postconditions - a true(1) will be return if the dateType is greater than the other, otherwise false will be return(0)
    // method input - dateType
    // method output - bool
    bool operator>(const dateType&) const;

  private:
    int year; //year of the date
    int month; // month of the date
    int day; // day of the date
  
  
};
    // method - poperator>>
    // description - read from the istream and creat a dateType with the data was read from istream
    // preconditions - must be a istream and dateType
    // postconditions - a dateType will be creat base on the istream data
    // method input - istream and dateType
    // method output - istream
istream& operator>>(istream&,dateType&);  

    // method - poperator<<
    // description - output the ostream from date dateType 
    // preconditions - must be a ostream and dateType
    // postconditions - a output will be made base on the dateType
    // method input - ostream and dateType
    // method output - ostream
ostream& operator<<(ostream&,const dateType&);

#endif