#include <iostream>
#include "baseConvert.h"

using namespace std;

int main(){

// Note: there is not an object of the baseConvert class declared.
// How is this accomplished?  The methods are static

   cout << "38 decimal is " << baseConvert::Dec2Bin(38) << " in binary\n";
   cout << "100110 binary is " << baseConvert::Bin2Dec(100110) << " in decimal\n";
   cout<<endl;
   cout << "39 decimal is " << baseConvert::Dec2Bin(39) << "in binary\n";
   cout << "100111 binary is " << baseConvert::Bin2Dec(100111) << " in decimal\n";
   cout<<endl;
   cout << "40 decimal is " << baseConvert::Dec2Bin(40) << "in binary\n";
   cout << "101000 binary is " << baseConvert::Bin2Dec(101000) << " in decimal\n";
   return 0;

}
