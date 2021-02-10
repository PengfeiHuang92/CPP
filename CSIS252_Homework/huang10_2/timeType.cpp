#include "timeType.h"
#include <iostream>
#include <string>
using namespace std;
istream& operator>>(istream& i,timeType& time){
  int tmpMin,tmpHours;
  char tmpChar;
  string tmpStr;
  i>>tmpHours;
  i>>tmpChar;
  i>>tmpMin;
  i>>tmpStr;
  if(tmpStr=="p.m." and tmpHours !=12)
    tmpHours= tmpHours+12;
  if(tmpStr =="a.m." and tmpHours == 12)
    tmpHours =0;
  time.setTime(tmpHours,tmpMin);
  return i;
} 
ostream& operator<<(ostream& out,const timeType& time){
  
  if (time.getHours() ==0){
    if (time.getMinutes() < 10) //checking if a zero is needed befor the minutes
      out<<"12:0"<<time.getMinutes()<<" a.m."<<endl;
    else
      out<<"12:"<<time.getMinutes()<<" a.m."<<endl;
  }
  else if (time.getHours() <12){ // if the hours is less than 12
    if (time.getMinutes() < 10) //checking if a zero is needed befor the minutes
      out<<time.getHours()<<":0"<<time.getMinutes()<<" a.m."<<endl;
    else
      out<<time.getHours()<<":"<<time.getMinutes()<<" a.m."<<endl;
  }
  else if (time.getHours() ==12){// if tishe hours is equal to 12
    if (time.getMinutes() < 10)//checking if a zero is needed befor the minutes
      out<<time.getHours()<<":0"<<time.getMinutes()<<" p.m."<<endl;
    else
      out<<time.getHours()<<":"<<time.getMinutes()<<" p.m."<<endl;
  }
  else{ // if the hours is greater than 12
    if (time.getMinutes() < 10)//checking if a zero is needed befor the minutes
      out<<time.getHours()-12<<":0"<<time.getMinutes()<<" p.m."<<endl;
    else
      out<<time.getHours()-12<<":"<<time.getMinutes()<<" p.m."<<endl;
  }
  return out;
}
bool timeType::operator==(const timeType& t) const{
  bool result;
  if(getHours() == t.getHours() and getMinutes() == t.getMinutes())
    result = true;
  else
    result = false;
  return result;
}
bool timeType::operator<(const timeType& t) const{
  bool result;
  if(getHours() < t.getHours())
    result = true;
  else if(getHours() == t.getHours()){
    if(getMinutes() < t.getMinutes())
      result = true;
    else
      result = false;
  }else
    result = false;
  return result;
}
bool timeType::operator!=(const timeType& t) const{
  return !(*this==t);
}
bool timeType::operator<=(const timeType& t) const{ 
  return *this<t || *this==t;
  }

bool timeType::operator>(const timeType& t) const{ // has checked
  return !(*this<=t);
}
bool timeType::operator>=(const timeType& t) const{
  return !(*this<t);
}
timeType::timeType(){
  
  setTime(0,0);
  
}
timeType::timeType(int h, int m){
 
  setTime(h,m);

}

void timeType::setTime(int h, int m){
  if(h>=0 and m>= 0 and h<=23 and m<=59){
    hours = h;
  minutes = m;
  }else{
    cerr<<"invalid time "<<h<<":"<<m<<endl;
    hours =0;
    minutes=0;
  }
  
}

int timeType::getHours() const{
  
  return hours;
}

int timeType::getMinutes() const{
  return minutes;
}
