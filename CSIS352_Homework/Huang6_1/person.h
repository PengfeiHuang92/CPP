#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
#include <string>
#include "date.h"
using namespace DateNameSpace;
using namespace std;

class Person{
	public:
        // method - default constructor
        // description - created the Perosn object with name n and birthday d
        // preconditions - none
        // postconditions - a Person object was created
        // method input - string name n and date birthday d
        // method output - none   
	    Person(string n, Date d);
        // method - setName
        // description - set the name by the argument
        // preconditions - string name and a Person object was created
        // postconditions - the name was set by the argument 
        // method input - string name n 
        // method output - none   
	    void setName(string);
        // method - getName
        // description - gets the name of the person object
        // preconditions - Person object was created
        // postconditions - the name of the person object was returned
        // method input - none 
        // method output - string 
	    string getName();
        // method - setBirthday
        // description - set the birthday by the argument
        // preconditions - Date birthday and a Person object was created
        // postconditions - the birthday was set by the argument 
        // method input - Date birthday d
        // method output - none 
	    void setBirthday(Date);
        // method - getBirthday
        // description - gets the birthday of the person object
        // preconditions - Person object was created
        // postconditions - the birthday of the person object was returned
        // method input - none 
        // method output - Date birthday 
	    Date getBirthday();
	  
	private:
	    string name;    //name of the person
	    Date birthday;    //birthday of the perosn
};



#endif
