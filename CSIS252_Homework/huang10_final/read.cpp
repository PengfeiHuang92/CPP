#include<fstream>
#include<string>
using namespace std;
#include "studentType.h"
#include "listType.h"

void read(listType<studentType>& students)
{
   ifstream infile;
   studentType tmpStudent;
   infile.open("scores");
   infile >> tmpStudent;
   while (!infile.eof() && !students.isFull())
   {
      students.insert(tmpStudent);
      infile >> tmpStudent;
   }
   infile.close();
}

