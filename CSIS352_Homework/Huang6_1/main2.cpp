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


int main()
{
   Employees tmp;
   Date d(2,2,1021);
   HourlyEmployee h("aa",d,154,"555-55-5555",5,20);
   Employee e("Tim",d,154,"555-55-3333");
   SalaryEmployee s("S",d,120,"555-55-4444",500);
   cout<<e.getSSN()<<endl;
   cout<<h.getHour()<<endl;
   cout<<s.getSalary()<<endl;
   Employee *ep;
//    HourlyEmployee *hp;
//    SalaryEmployee *sp;
   ep = &e;
    tmp.push_back(ep);
   ep = &h;
   
   tmp.push_back(ep);
   ep = &s;
   tmp.push_back(ep);
   
   cout<<tmp.getEmployee(0)->getSSN()<<endl;
   cout<<tmp.getEmployee(1)->getHour()<<endl;
   cout<<tmp.getEmployee(1)->getWage()<<endl;
   cout<<tmp.getEmployee(2)->getSalary()<<endl;
}
