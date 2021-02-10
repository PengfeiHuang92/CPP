#include <fstream>
#include <iostream>
#include "employees.h"
#include "employee.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
// Function: write
// Description: write to the file 
// Input:  char* filename and Employees
// Output:bool if the file was read successly
// Preconditions:
// Postconditions: 
void write( Employees& emp)
{
   cout<<"begin of write"<<endl;
   ofstream ofs1;
   ofstream ofs2;
   string header;
   Date::Arithmetic(Years);
   Date today;
   ofs1.open("payroll");
   if (ofs1.fail())
   {
      cerr << "error opening outputfile payroll"<< endl;

   }else{ 
       header ="Name                     Id     Gross Pay   Hour   Wage \n--------------------------------------------------------\n" ;
       ofs1<<header;
       
      for(int i=0; i<emp.listSize(); i++){
          if(emp.getEmployee(i)->getIndentifier() == "H"){
            string name= emp.getEmployee(i)->getName();
            int id= emp.getEmployee(i)->getEmployeeId();
            int hour= emp.getEmployee(i)->getHour();
            double wage= emp.getEmployee(i)->getWage();
            double grossPay = hour * wage;
            
            
            ofs1<<setw(25)<<left<<name;
            ofs1<<setw(7)<<left<<to_string(id);
            ofs1<<setw(12)<<left<<setprecision(4)<<grossPay;
            ofs1<<setw(7)<<left<<to_string(hour);
            ofs1<<setw(7)<<left<<setprecision(4)<<wage<<"\n";
          }else{
            string name= emp.getEmployee(i)->getName();
            int id= emp.getEmployee(i)->getEmployeeId();
            int salary= emp.getEmployee(i)->getSalary();
            ofs1<<setw(25)<<left<<name;
            ofs1<<setw(7)<<left<<to_string(id);
            ofs1<<setw(12)<<left<<salary<<"\n";
            
        }
    }

      ofs1.close();
   }
 
   ofs2.open("employees");
   if (ofs2.fail())
   {
      cerr << "error opening outputfile employees" << endl;

   }
   else{   header ="Name                     Social Security Number   Birthday      Age \n ------------------------------------------------------------------ \n" ;
       ofs2 <<header;
       
       for(int i=0; i<emp.listSize(); i++){
           string name= emp.getEmployee(i)->getName();
           string ssn=emp.getEmployee(i)->getSSN();
           Date birthday = emp.getEmployee(i)->getBirthday();
           ofs2<<setw(25)<<left<<name;
           ofs2<<setw(25)<<left<<ssn;
           ofs2<<setw(14)<<left<<birthday;
           ofs2<<setw(5)<<left<<today-birthday<<"\n";
    }

      ofs2.close();
   }
   cout<<"end of write"<<endl;
}
