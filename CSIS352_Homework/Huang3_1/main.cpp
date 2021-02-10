#include <iostream>
#include "array.h"
using namespace std;
using namespace ArrayNameSpace;
const int startindex=-3;
const int endindex=2;

void func1(Array<int> n)   // pass by value, actual parameter not changed
{
   for (int i=startindex; i<=endindex; i++)
      n[i] = i;
}

void func2(Array<int>& n)  // pass by reference
{
   for (int i=startindex; i<=endindex; i++)
      n[i] = i;
}

void output(const Array<int>& n)  // const reference
{
   for (int i=n.getStartIndex(); i<n.getStartIndex()+n.Size(); i++)
      cout << "n[" << i << "] = " << n[i] << endl;
}

Array<int> func3(Array<int> n)  // returns an Array
{
   return n;
}

int main()
{
   Array<int> numbers(startindex,endindex); // indices -3 to 2
   for (int i=startindex; i<=endindex; i++) // initialize
      numbers[i] = i*10;
   for (int i=startindex; i<=endindex; i++) // dump the array
      cout << "numbers[" << i << "] = " << numbers[i] << endl;
   cout << "-------------\n";

//   numbers = 20;  // compiler error
   func1(numbers);    // numbers should be the same
   output(numbers);
   cout << "-------------\n";
   func2(numbers);    // numbers contents should change
   output(numbers);
   cout << "-------------\n";

   Array<int> numbers2;  // the array has no locations, but starting index 0
   try
   {
      numbers2[0] = 88;
   }
   catch (out_of_range error)
   {
      cout << error.what() << endl;
   }
   numbers2.Resize(10); // indices 0 through 9
   numbers2[0] = 88;
   output(numbers2);
   cout << "-------------\n";

   numbers2 = numbers;
   numbers2.setStartIndex(10); // indices 10 through 15
   output(numbers2);
   cout << "-------------\n";
}
