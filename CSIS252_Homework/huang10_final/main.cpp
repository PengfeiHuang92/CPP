#include <iostream>
#include <fstream>
#include "timeType.h"
#include "dateType.h"
#include "personType.h"
#include "studentType.h"
#include "listType.h"
using namespace std;
void read(listType<studentType>&);
void output(const listType<studentType>&);

int main()
{
   listType<studentType> students;
   read(students);
   output(students);
   return 0;
}
