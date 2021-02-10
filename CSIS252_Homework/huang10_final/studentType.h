//File: studentType.h
//Author: Pengfei Huang
//Date: 04/24/2018

// Description
// This file contains the specification for a studentType class
#ifndef _STUDENTTYPE_H_
#define _STUDENTTYPE_H_

#include "personType.h"
#include <iostream>
#include <string>
using namespace std;
class studentType : public personType{
public:
  // method - studentType
  // description - construct a new studentType object 
  // preconditions - none
  // postconditions - studentType object created and set the name to Tim, the birthday month to 1, the birthday to 1 and the birthday year to 2000 and the score to 100
  // method input - none
  // method output - none
  studentType();
  
  // method - studentType
  // description - construct a new studentType object 
  // preconditions - the n is string and s is int  
  // postconditions - studentType object created and initialized the name to n, the score to s
  // method input - string name (n) , int score(s)
  // method output - none   
  studentType(string n, int s);
  
  // method - setStudent
  // description - set the student's name with the n(String) and the student's score to s(int)
  // preconditions - the n is string and s is int  
  // postconditions - studentType object created and initialized the name to n and score to s, and birthday to 1/1/2000
  // method input - string name (n) , int score (s)
  // method output - none   
  void setStudent(string n, int s);
  
  // method - setScore
  // description - set student's score to s(int)
  // preconditions - s is int and is not null 
  // postconditions - set student's score to s(int)
  // method input - int score (s)
  // method output - none   
  void setScore(int s);
  
  // method - getScore
  // description - return student's score
  // preconditions - none
  // postconditions - return student's score
  // method input - none
  // method output - student's score int  
  int getScore() const;
    
  // method - poperator==
  // description - compare with two studentType return true if they equal
  // preconditions - must be a studentType
  // postconditions - a true(1) will be return if the two studentType are the same, otherwise false will be return(0)
  // method input - studentType
  // method output - bool
  bool operator == (const studentType&) const;
    
  // method - poperator!=
  // description - compare with two studentType return true if they do not equal
  // preconditions - must be a studentType
  // postconditions - a true(1) will be return if the two studentType are not the same, otherwise false will be return(0)
  // method input - studentType
  // method output - bool
  bool operator !=(const studentType&) const;
    
  // method - poperator<
  // description - compare with two studentType return true if the studentType is less than the other, otherwise false will be return(0)
  // preconditions - must be a studentType
  // postconditions - a true(1) will be return if the studentType is less than the other, otherwise false will be return(0)
  // method input - studentType
  // method output - bool
  bool operator < (const studentType&) const;
    
  // method - poperator<=
  // description - compare with two studentType return true if the studentType is less than or equal to the other, otherwise false will be return(0)
  // preconditions - must be a studentType
  // postconditions - a true(1) will be return if the studentType is less than or equal to the other, otherwise false will be return(0)
  // method input - studentType
  // method output - bool
  bool operator <= (const studentType&) const;
    
  // method - poperator>
  // description - compare with two studentType return true if the studentType is greater than the other, otherwise false will be return(0)
  // preconditions - must be a studentType
  // postconditions - a true(1) will be return if the studentType is greater than the other, otherwise false will be return(0)
  // method input - studentType
  // method output - bool
  bool operator > (const studentType&) const;
    
  // method - poperator>=
  // description - compare with two studentType return true if the studentType is greater than or equal to the other, otherwise false will be return(0)
  // preconditions - must be a studentType
  // postconditions - a true(1) will be return if the studentType is greater than or equal to the other, otherwise false will be return(0)
  // method input - studentType
  // method output - bool
  bool operator >= (const studentType&) const;
private:
  int score; //the score of the student
};
    // method - poperator>>
    // description - read from the istream and creat a studentType data was read from istream
    // preconditions - must be a istream and studentType
    // postconditions - a studentType will be creat base on the istream data
    // method input - istream and studentType
    // method output - istream
istream& operator>>(istream&,studentType&);  

    // method - poperator<<
    // description - output the ostream from date studentType 
    // preconditions - must be a ostream and studentType
    // postconditions - a output will be made base on the studentType
    // method input - ostream and studentType
    // method output - ostream
ostream& operator<<(ostream&,const studentType&);
#endif