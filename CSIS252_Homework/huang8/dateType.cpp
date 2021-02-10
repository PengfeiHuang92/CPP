#include "dateType.h"
#include <string>
#include <iostream>
using namespace std;

istream& operator>>(istream& i,dateType& date){
   int day;
   int month;
   int year;
   char slash;
   i>> month;
   i >> slash;
   i>> day;
   i >> slash;
   i>> year;
   date.setDate(month,day,year);
   return i;
}
ostream& operator<<(ostream& out, const dateType& date){
  string arrayMonth[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  out<<arrayMonth[date.getMonth()-1]<<" "<<date.getDay()<<","<<date.getYear()<<endl;
  return out;
}

bool dateType::operator==(const dateType& d) const{
   bool result;
   if(getDay() == d.getDay() and getMonth() == d.getMonth() and getYear() == d.getYear())
     result = true;
   else
     result = false;
   return result;
}
bool dateType::operator<(const dateType& d) const{
  bool result;
  if(getYear()<d.getYear())
    result = true;
  else if (getYear() == d.getYear()){
    if(getMonth() < d.getMonth())
      result = true;
    else if(getMonth() == d.getMonth() and getDay()< d.getDay())
      result = true;
    else
      result =false;
  }
  else
    result = false;
  return result;
}
bool dateType::operator!=(const dateType& d) const{
  return !(*this==d);
}
bool dateType::operator<=(const dateType& d) const{
  return *this<d || *this==d;
}
bool dateType::operator>=(const dateType& d) const{
  return !(*this<d);
}
bool dateType::operator>(const dateType& d) const{
   return !(*this<=d);
}
dateType::dateType(){
  setDate(1,1,2000);
}

dateType::dateType(int m, int d, int y){
  setDate(m,d,y);
}


void dateType::setDate(int m, int d, int y){
  if(m<13 && m>0 && d>0 && y>0){
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
      if(d<32){
	month = m;
	day = d;
	year = y;
      }else{
	cerr<<"invalid date "<<m<<"/"<<d<<"/"<<y<<endl;
	month = 1;
	day = 1;
	year = 2000;
      }
    }else if(m==4 || m==6 || m==9 || m==11){
      if(d<31){
	month = m;
	day = d;
	year = y;
      }else{
	cerr<<"invalid date "<<m<<"/"<<d<<"/"<<y<<endl;
	month = 1;
	day = 1;
	year = 2000;
      }
    }else if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)){
      if(d<30){
	month = m;
	day = d;
	year = y;
      }else{
	cerr<<"invalid date "<<m<<"/"<<d<<"/"<<y<<endl;
	month = 1;
	day = 1;
	year = 2000;
      }
    }else{
      if(d<29){
	month = m;
	day = d;
	year = y;
      }else{
	cerr<<"invalid date "<<m<<"/"<<d<<"/"<<y<<endl;
	month = 1;
	day = 1;
	year = 2000;
      }
    }
  }else{
    cerr<<"invalid date "<<m<<"/"<<d<<"/"<<y<<endl;
    month = 1;
    day = 1;
    year = 2000;
  }
  
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

/***
void dateType::print() const{
  string arrayMonth[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  cout<<arrayMonth[getMonth()-1]<<" "<<getDay()<<","<<getYear()<<endl;
}
***/