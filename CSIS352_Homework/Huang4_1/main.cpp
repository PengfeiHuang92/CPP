#include <iostream>
using namespace std;
#include "sortedList.h"
using namespace sortedListSpace;

sortedList<int> func(sortedList<int> anotherlist)
{
   return anotherlist;
}

void output(const sortedList<int>& list)
{
   for (int i=0; i<list.length(); i++)
      cout << list[i] << ' '; // operator[] can throw out_of_range exception
   cout << endl;
}

void visit(int& num)
{
   cout << num << '/';
}

void increment(int& num)
{
   num++;
}

int main()
{
   sortedList<int> list1; // you do not specify a size with a linked structure
   sortedList<int> list2; // default is ASCENDING
   sortedList<int> list3(ASCENDING);
   sortedList<int> list4(DESCENDING);
   if (list3.isEmptyList())
      cout << "list3 is empty\n";
   else
      cout << "list3 is NOT empty\n";
   list3.insertItem(3);

   list3.insertItem(5);

   list3.insertItem(2);
   list3.insertItem(6);
   list3.insertItem(1);
 
   if (list3.isEmptyList())
      cout << "list3 is empty\n";
   else
      cout << "list3 is NOT empty\n";
   cout << "list3: ";
 
   for (int i=0; i<list3.length(); i++)
      cout << list3.valueAt(i) << ' ';  // valueAt can throw out_of_range exception
   cout << endl;
}
