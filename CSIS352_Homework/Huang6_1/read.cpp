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
{
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
           //cout<<birthday<<endl;
           ifs.ignore(80,'\n'); //make point to the next line
           string ssn;
           getline(ifs,ssn);
           //cout<<ssn<<endl;
         
           string id;
           getline(ifs,id);
           string i;
           getline(ifs,i);
           Employee* ep;
           if(i=="H"){
              
               string hour;
               string wage;
               getline(ifs,hour);
               getline(ifs,wage);
              
               HourlyEmployee* hp;
               hp = new HourlyEmployee(name,birthday,stoi(id),ssn,stoi(hour),stod(wage));
               ep = hp;
               empList.push_back(ep);
           }
           else if(i == "S"){
               string salary;
               getline(ifs,salary);
               SalaryEmployee* sp;
               sp = new SalaryEmployee(name,birthday,stoi(id),ssn,stoi(salary));
               ep = sp;
               empList.push_back(ep);
           }
           string name;
           ifs.ignore(80,'\n');  //in case the file end with le \n
           getline(ifs,name);
    }
       
       
       
//testing push_back       
//       string name = "Tim";
//       Date birthday(2,2,1999);
//       string ssn = "444-555-5555";
//       int employeeId = 15;
//       int hour = 5;
//       double wage = 20.0;
//       //HourlyEmployee h(name,birthday,employeeId,ssn,hour,wage);
//       Employee* ep;
//       HourlyEmployee* hp;
//       hp = new HourlyEmployee(name,birthday,employeeId,ssn,hour,wage);
//       ep = hp;
//       empList.push_back(ep);
//       int salary = 100;
//       SalaryEmployee s(name,birthday,employeeId,ssn,salary);
//       cout<<s.getSalary()<<endl;
//       ep = &s;
//       empList.push_back(ep);
      ifs.close();
   }
 
   return success;
}
