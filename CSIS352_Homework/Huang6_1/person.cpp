//FIle:  person.cpp
//Author: Pengfei Huang

//Description
// This file contains the implementation for a person class
#include <iostream>
#include <string>
#include "person.h"
#include "date.h"
using namespace std;
using namespace DateNameSpace;
Person::Person(string n, Date d):name(n),birthday(d){
    
}
void Person::setName(string n){
    name = n;
}
string Person::getName(){
    return name;
}
void Person::setBirthday(Date d){
    birthday = d;
}
Date Person::getBirthday(){
    return birthday;
}
