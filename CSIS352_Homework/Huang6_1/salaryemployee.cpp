//FIle:  hourlyemployee.cpp
//Author: Pengfei Huang

//Description
// This file contains the implementation for a hourlyemployee class
#include "salaryemployee.h"
SalaryEmployee::SalaryEmployee(string n, Date d, int eid,string s,int sa):Employee(n,d,eid,s),salary(sa){
    
}

void SalaryEmployee::setSalary(int s){
    salary = s;
}
int SalaryEmployee::getSalary(){
    return salary;
}
