#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "studentType.h"
#include "listType.h"
void output(const listType<studentType>& students)
{
   studentType tmpStudent;
   ofstream o;
   o.open("results");
   o<<setw(15)<<left<<"NAME"<<setw(10)<<right<<"SCORE"<<endl;
   for (int i=0; i<students.listSize(); i++)
   {
      students.retrieveAt(i,tmpStudent);
      o << tmpStudent << endl;
   }
   o.close();
}
