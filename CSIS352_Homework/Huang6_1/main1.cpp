#include <iostream>
#include "person.h"
#include "employee.h"
#include "hourlyemployee.h"
#include "salaryemployee.h"
//#include "employees.h"
#include "date.h"
#include <iostream>
#include <fstream>
#include <string>
#include "list"
using namespace std;
using namespace DateNameSpace;
// function prototypes
bool write(char* filename, int& x, int& y);
bool read(char* filename);

int main(int argc,char *argv[])
{
   ifstream ifs;
   ofstream ofs;
   
   int x,y;
   bool success=true;
   if (argc != 3)
   {
      cerr << "usage: " << argv[0] << " <inputfile> <outputfile>\n";
      success=false;
   }
   else
   {
      success = read(argv[1]);
      if (success)
      {
         success = write(argv[2],x,y);
      }
   }
   return 0;
}


bool write(char* filename, int& x, int& y)
{
   bool success=true;
   ofstream ofs;
   ofs.open(filename);
   if (ofs.fail())
   {
      cerr << "error opening outputfile " << filename << endl;
      success=false;
   }
   else
   {
      ofs << "the sum of " << x << " and " << y
          << " is " << x+y << endl;
      ofs.close();
   }
   return success;
}
