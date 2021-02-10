#include <iostream>
#include "timeType.h"
#include "dateType.h"
using namespace std;

int main(){
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
  
  dateType date;
  date.print();
  date.setDate(5,25,2017);
  date.print();
  return 0;
}