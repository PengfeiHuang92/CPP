#include "timeType.h"
#include <iostream>
using namespace std;

timeType::timeType(){
  
  setTime(0,0);
  
}
timeType::timeType(int h, int m){
 
  setTime(h,m);

}

void timeType::setTime(int h, int m){
  
  hours = h;
  minutes = m;
}

int timeType::getHours() const{
  
  return hours;
}

int timeType::getMinutes() const{
  return minutes;
}

void timeType::print() const{
  if (getHours() ==0){
    if (getMinutes() < 10) //checking if a zero is needed befor the minutes
      cout<<"12:0"<<getMinutes()<<" a.m."<<endl;
    else
      cout<<"12:"<<getMinutes()<<" a.m."<<endl;
  }
  else if (getHours() <12){ // if the hours is less than 12
    if (getMinutes() < 10) //checking if a zero is needed befor the minutes
      cout<<getHours()<<":0"<<getMinutes()<<" a.m."<<endl;
    else
      cout<<getHours()<<":"<<getMinutes()<<" a.m."<<endl;
  }
  else if (getHours() ==12){// if tishe hours is equal to 12
    if (getMinutes() < 10)//checking if a zero is needed befor the minutes
      cout<<getHours()<<":0"<<getMinutes()<<" p.m."<<endl;
    else
      cout<<getHours()<<":"<<getMinutes()<<" p.m."<<endl;
  }
  else{ // if the hours is greater than 12
    if (getMinutes() < 10)//checking if a zero is needed befor the minutes
      cout<<getHours()-12<<":0"<<getMinutes()<<" p.m."<<endl;
    else
      cout<<getHours()-12<<":"<<getMinutes()<<" p.m."<<endl;
  }
}