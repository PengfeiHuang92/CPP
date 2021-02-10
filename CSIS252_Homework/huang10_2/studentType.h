//File: personType.h
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
  studentType();
  studentType(string n, int s);
  void setStudent(string n, int s);
  void setScore(int s);
  int getScore() const;
    
  // method - poperator==
  // description - compare with two personType return true if they equal
  // preconditions - must be a personType
  // postconditions - a true(1) will be return if the two personType are the same, otherwise false will be return(0)
  // method input - personType
  // method output - bool
  bool operator == (const studentType&) const;
    
  // method - poperator!=
  // description - compare with two personType return true if they do not equal
  // preconditions - must be a personType
  // postconditions - a true(1) will be return if the two personType are not the same, otherwise false will be return(0)
  // method input - personType
  // method output - bool
  bool operator !=(const studentType&) const;
    
  // method - poperator<
  // description - compare with two personType return true if the personType is less than the other, otherwise false will be return(0)
  // preconditions - must be a personType
  // postconditions - a true(1) will be return if the personType is less than the other, otherwise false will be return(0)
  // method input - personType
  // method output - bool
  bool operator < (const studentType&) const;
    
  // method - poperator<=
  // description - compare with two personType return true if the personType is less than or equal to the other, otherwise false will be return(0)
  // preconditions - must be a personType
  // postconditions - a true(1) will be return if the personType is less than or equal to the other, otherwise false will be return(0)
  // method input - personType
  // method output - bool
  bool operator <= (const studentType&) const;
    
  // method - poperator>
  // description - compare with two personType return true if the personType is greater than the other, otherwise false will be return(0)
  // preconditions - must be a personType
  // postconditions - a true(1) will be return if the personType is greater than the other, otherwise false will be return(0)
  // method input - personType
  // method output - bool
  bool operator > (const studentType&) const;
    
  // method - poperator>=
  // description - compare with two personType return true if the personType is greater than or equal to the other, otherwise false will be return(0)
  // preconditions - must be a personType
  // postconditions - a true(1) will be return if the personType is greater than or equal to the other, otherwise false will be return(0)
  // method input - personType
  // method output - bool
  bool operator >= (const studentType&) const;
private:
  int score;
};
    // method - poperator>>
    // description - read from the istream and creat a personType data was read from istream
    // preconditions - must be a istream and personType
    // postconditions - a personType will be creat base on the istream data
    // method input - istream and personType
    // method output - istream
istream& operator>>(istream&,studentType&);  

    // method - poperator<<
    // description - output the ostream from date personType 
    // preconditions - must be a ostream and personType
    // postconditions - a output will be made base on the personType
    // method input - ostream and personType
    // method output - ostream
ostream& operator<<(ostream&,const studentType&);
#endif