#include <iostream>
#include <fstream>
#include "dateType.h"
#include "personType.h"
#include "studentType.h"
#include "listType.h"
using namespace std;

int main(){
  listType<studentType> students;
  
  read(students);
  cout<<students;
//  output(students);
  return 0;
}