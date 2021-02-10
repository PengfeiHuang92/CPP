//FIle:  employees.cpp
//Author: Pengfei Huang

//Description
// This file contains the implementation for a employees class
#include "employees.h"
#include "employee.h"
using namespace std;
Employees::Employees(){
	group.clear();
}
void Employees::push_back( Employee* emp){
	group.push_back(emp);
    
}
Employee* Employees::getEmployee(int i){
   typename list<Employee*>::iterator p;

   p=group.begin();  
   
   for(int j=0; j<i;j++)
        p++;
  
   return *p;
   
}
