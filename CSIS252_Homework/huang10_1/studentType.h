//File: studentType.h
//Author: Pengfei Huang
//Date: 04/20/2018
// Description
// This file contains the specification for a studentType class
#ifndef _STUDENTTYPE_H_
#define _STUDENTTYPE_H_
#include <string>
#include "personType.h"
class studentType : public personType
{
  public:
    studentType();
    studentType(string name ,int score );
    void setStudent(string name , int score);
    void setScore(int s);
    int getScore() const;
  private:
    int score;
}

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