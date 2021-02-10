#include <iostream>
#include <fstream>
#include "timeType.h"
#include "dateType.h"
using namespace std;

int main(){
  /***
  timeType time;
  time.setTime(12,0);
  time.print();
  time.setTime(23,2);
  time.print();
  time.setTime(0,11);
  time.print();
  time.setTime(11,59);
  time.print();
  time.setTime(13,15);
  time.print();
  ***/
  ifstream f;
  f.open("dateType");
  dateType date;
  f>>date;
  cout<< date<<endl;
  
  date.setDate(5,25,2017);
  cout<< date<<endl;
  ifstream f2;
  f2.open("timeType");
  timeType time1;
  f2>>time1;
  cout<<time1<<endl;
  //testing the time
  int h,m;
  cout<<"Enter hour: "<<endl;
  cin>>h;
  cout<<"Enter min:"<<endl;
  cin>>m;
  
  timeType time2(h,m);
  cout<<"Is the time is == : "<<endl;
  if (time1 == time2){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  cout<<"Is the time is != : "<<endl;
  if (time1 != time2){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  cout<<"Is the time is <= : "<<endl;
  if (time1 <= time2){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  cout<<"Is the time is >= : "<<endl;
  if (time1 >= time2){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  cout<<"Is the time is < : "<<endl;
  if (time1 < time2){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  cout<<"Is the time is > : "<<endl;
  if (time1 > time2){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
 
  
  //  testing the date
  int month,year,day;
  cout<<"Enther the month: ";
  cin>>month;
  cout<<"day: ";
  
  cin>>day;
  cout<<"year: ";
  cin>>year;
  dateType date1(month,day,year);

  cout<<date1<<endl;
  cout<<"Is the date is == than date1?: "<<endl;
  if (date == date1){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  cout<<"Is the date is <= than date1?: "<<endl;
  if (date <= date1){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  cout<<"Is the date is < than date1?: "<<endl;
  if (date < date1){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  cout<<"Is the date is != than date1?: "<<endl;
  if (date != date1)
    cout<<"True"<<endl;
  else
    cout<<"Fasle"<<endl;
  cout<<"Is the date is >= than date1?: "<<endl;
  if (date >= date1){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  cout<<"Is the date is > than date1?: "<<endl;
  if (date > date1){
    cout<<"True"<<endl;
  }else
    cout<<"Fasle"<<endl;
  return 0;



}