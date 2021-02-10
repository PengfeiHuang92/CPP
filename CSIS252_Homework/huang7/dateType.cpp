#include "dateType.h"
#include <iostream>
#include <string>
using namespace std;

dateType::dateType(){
  setDate(1,1,2000);
}

dateType::dateType(int m, int d, int y){
  
  setDate(m,d,y);
}

void dateType::setDate(int m, int d, int y){
  month = m;
  day = d;
  year = y;
}

int dateType::getYear() const{
  return year;
}

int dateType::getMonth() const{
  return month;
  
}
int dateType::getDay() const{
  return day;
}
void dateType::print() const{
  string arrayMonth[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  cout<<arrayMonth[getMonth()-1]<<" "<<getDay()<<","<<getYear()<<endl;
}