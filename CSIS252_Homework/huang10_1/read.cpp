#include <fstream>
#include <string>
using namespace std;
#include "studentType.h"
#include "listType.h"

void read(listType<studentType>& students)
{
   ifstream infile;
   studentTye st;
   infile.open("scores");
   infile >> st;
   while (!infile.eof() && !people.isFull())
   {
      students.insert(st);
      infile >> st;
   }
   infile.close();
}

