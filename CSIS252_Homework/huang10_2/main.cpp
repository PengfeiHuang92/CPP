#include <iostream>
#include <fstream>
#include "timeType.h"
#include "dateType.h"
#include "personType.h"
#include "studentType.h"
using namespace std;

int main(){
  
  
   ifstream infile;
   studentType students;
//    int count = 0;
   infile.open("scores");
   infile >> students;
   studentType students1("Tim",100);

   
   /***
   while (!infile.eof() && count<arraysize)
   {
      employees[count] = employee;
      count++;
      infile >> employee;
   }
   ***/
   infile.close();
 
   cout << students;
}