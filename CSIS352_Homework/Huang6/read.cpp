//File:  read.cpp
//Name:  Pengfei Huang
//Class: CSIS 352
//Program: assignment #6
//Date:  4/24/2019
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include "date.h"
#include "employees.h"
#include "hourlyemployee.h"
#include "salaryemployee.h"
// Function: read
// Description: read the file and stored it into the Employees
// Input:  char* filename and Employees
// Output:bool if the file was read successly
// Preconditions:
// Postconditions: 
using namespace std;
using namespace DateNameSpace;
bool read(char* filename, Employees& empList)
{  cout<<"begin of read"<<endl;
   bool success=true;
   ifstream ifs;
   ifs.open(filename);
   if (ifs.fail())
   {
      cerr << "error opening inputfile: '" 
           << filename << "' doesn't exist?\n";
      success=false;
   }
   else
   {
       
       string name;
       getline(ifs,name);
       while(!ifs.eof()){
    
           Date birthday;
           ifs>>birthday;
           ifs.ignore(80,'\n'); //make point to the next line
           string ssn;
           getline(ifs,ssn);         
           string id;
           getline(ifs,id);
           string i;
           getline(ifs,i);
           if(i=="H"){              
               string hour;
               string wage;
               getline(ifs,hour);
               getline(ifs,wage);
               Employee* ep;
               HourlyEmployee* hp;
               hp = new HourlyEmployee(name,birthday,stoi(id),ssn,i,stoi(hour),stod(wage));
               ep = hp;
               empList.push_back(ep);
           }else if(i == "S"){               
               string salary;
               getline(ifs,salary);
               Employee* ep;
               SalaryEmployee* sp;
               sp = new SalaryEmployee(name,birthday,stoi(id),ssn,i,stoi(salary));
               ep = sp;
               empList.push_back(ep);
           }
       
         
           //ifs.ignore(80,'\n');  //in case the file end with le \n
           getline(ifs,name);
    }
       
       
       

      ifs.close();
   }
  cout<<"end of read"<<endl;
   return success;
}
