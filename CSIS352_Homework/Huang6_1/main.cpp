#include <iostream>
#include "person.h"
#include "employee.h"
#include "hourlyemployee.h"
#include "salaryemployee.h"
#include "employees.h"
#include "date.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
using namespace DateNameSpace;


// function prototypes

bool read(char* filename,Employees&);

int main(int argc,char *argv[])
{
   ifstream ifs;
   ofstream ofs;
   
   Employees empList;
   bool success=true;
   if (argc != 3)
   {
      cerr << "usage: " << argv[0] << " <inputfile> <outputfile>\n";
      success=false;
   }
   else
   {
      success = read(argv[1],empList);
       //cout<<empList.getEmployee(0)->getName()<<endl;
      cout<<"HEllo"<<endl;
      cout<<empList.getEmployee(0)->getName()<<endl;
       cout<<empList.getEmployee(0)->getSalary()<<endl;
   }
   return 0;
}
