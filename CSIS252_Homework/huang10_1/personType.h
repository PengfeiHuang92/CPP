//File: personType.h
//Author: Pengfei Huang
//Date: 04/16/2018
// Description
// This file contains the specification for a personType class

#ifndef _PERSONTYPE_H_
#define _PERSONTYPE_H_
#include <string>
#include "dateType.h"
#include "personType.h"
class personType{
  
  public:
    // method - personType
    // description - construct a new personType object 
    // preconditions - none
    // postconditions - personType object created and set the name to Null, the birthday month to 1, the birthday to 1 and the birthday year to 2000
    // method input - none
    // method output - none
    personType();
    
    // method - personType
    // description - construct a new personType object 
    // preconditions - the name is not null and birthday date is correct the month, day and year are int
    // postconditions - personType object created and initialized the name to n, the birthday to b
    // method input - string name (n) , dateType birthday(b)
    // method output - none   
    personType(string n , dateType b);  
    
    // method - setPerson
    // description - set the person's name with the n(String) and the person's birthday to b(dateType)
    // preconditions - the name is not null and birthday date is correct the month, day and year are int
    // postconditions - set the name to n, the birthday to b
    // method input - string name (n) , dateType birthday(b)
    // method output - none   
    void setPerson(string n ,const dateType& b) ;

    // method - getName
    // description - return the name of the person
    // preconditions - none
    // postconditions - a name will be returned 
    // method input - none
    // method output - name(string)  
    string getName() const;
    
    // method - getBirthday
    // description - return the birthday of the person
    // preconditions - none
    // postconditions - a birthday(dateType) will be returned 
    // method input - none
    // method output - birthday(dateType)  
    dateType getBirthday() const;
    
    // method - poperator==
    // description - compare with two personType return true if they equal
    // preconditions - must be a personType
    // postconditions - a true(1) will be return if the two personType are the same, otherwise false will be return(0)
    // method input - personType
    // method output - bool
    bool operator == (const personType&) const;
    
    // method - poperator!=
    // description - compare with two personType return true if they do not equal
    // preconditions - must be a personType
    // postconditions - a true(1) will be return if the two personType are not the same, otherwise false will be return(0)
    // method input - personType
    // method output - bool
    bool operator !=(const personType&) const;
    
    // method - poperator<
    // description - compare with two personType return true if the personType is less than the other, otherwise false will be return(0)
    // preconditions - must be a personType
    // postconditions - a true(1) will be return if the personType is less than the other, otherwise false will be return(0)
    // method input - personType
    // method output - bool
    bool operator < (const personType&) const;
    
    // method - poperator<=
    // description - compare with two personType return true if the personType is less than or equal to the other, otherwise false will be return(0)
    // preconditions - must be a personType
    // postconditions - a true(1) will be return if the personType is less than or equal to the other, otherwise false will be return(0)
    // method input - personType
    // method output - bool
    bool operator <= (const personType&) const;
    
    // method - poperator>
    // description - compare with two personType return true if the personType is greater than the other, otherwise false will be return(0)
    // preconditions - must be a personType
    // postconditions - a true(1) will be return if the personType is greater than the other, otherwise false will be return(0)
    // method input - personType
    // method output - bool
    bool operator > (const personType&) const;
    
    // method - poperator>=
    // description - compare with two personType return true if the personType is greater than or equal to the other, otherwise false will be return(0)
    // preconditions - must be a personType
    // postconditions - a true(1) will be return if the personType is greater than or equal to the other, otherwise false will be return(0)
    // method input - personType
    // method output - bool
    bool operator >= (const personType&) const;

  private:
    string name; //name of the person
    dateType birthday; // birthday of the person
};

    // method - poperator>>
    // description - read from the istream and creat a personType data was read from istream
    // preconditions - must be a istream and personType
    // postconditions - a personType will be creat base on the istream data
    // method input - istream and personType
    // method output - istream
istream& operator>>(istream&,personType&);  

    // method - poperator<<
    // description - output the ostream from date personType 
    // preconditions - must be a ostream and personType
    // postconditions - a output will be made base on the personType
    // method input - ostream and personType
    // method output - ostream
ostream& operator<<(ostream&,const personType&);


#endif 