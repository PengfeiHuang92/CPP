//FIle:  hourlyemployee.cpp
//Author: Pengfei Huang

//Description
// This file contains the implementation for a hourlyemployee class
#include "hourlyemployee.h"
using namespace DateNameSpace;
HourlyEmployee::HourlyEmployee(string n, Date d, int eid,string s, int h, double w):Employee(n,d,eid,s),hour(h),wage(w){
    
}
void HourlyEmployee::setHour(int h){
    hour = h;
}
 int HourlyEmployee::getHour(){
    return hour;
}
void HourlyEmployee::setWage(double w){
    wage = w;
}
double HourlyEmployee::getWage(){
    return wage;
}
