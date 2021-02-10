//FIle:  employee.cpp
//Author: Pengfei Huang

//Description
// This file contains the implementation for a employee class
#include "employee.h"
using namespace DateNameSpace;
Employee::Employee(string n, Date d, int eid,string s,string ide):Person(n,d),employeeId(eid),ssn(s),identifier(ide){
    
}
void Employee::setEmployeeId(int id){
    employeeId = id;
}
int Employee::getEmployeeId(){
    return employeeId;
}
void Employee::setSSN(string s){
    ssn =s;
}
string Employee::getSSN(){
    return ssn;
}
void Employee::setIdentifier(string ide){
    identifier =ide;
}
string Employee::getIndentifier(){
    return identifier;
}
