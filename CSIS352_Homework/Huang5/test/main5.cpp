#include <iostream>
using namespace std;
#include "graph.h"
//using namespace GraphNameSpace;

int main()
{
   cout << "***************************************************************************\n";
   cout << "main5.cpp                          UNWEIGHTED UNDIRECTED\n";
   Graph<char> g1;
   char A='A', B='B', C='C', D='D', E='E';
   g1.insertVertex(A);
   g1.insertVertex(B);
   g1.insertVertex(C);
   g1.insertVertex(D);
   g1.insertEdge(A,B);
   g1.insertEdge(B,C);
   g1.insertEdge(C,D);
   try
   {
      g1.insertEdge(E,A);
      cout << "didn't throw exception for inserting an edge from non existant vertex (UNWEIGHTED UNDIRECTED)\n";
   }
   catch (exception error)
   {
      cout << "1. " << error.what() << endl;
   }
   try
   {
      g1.insertEdge(A,E);
      cout << "didn't throw exception for inserting an edge from non existant vertex (UNWEIGHTED UNDIRECTED)\n";
   }
   catch (exception error)
   {
      cout << "2. " << error.what() << endl;
   }
   try
   {
      g1.deleteVertex(E);
      cout << "didn't throw exception for deleting non existant vertex (UNWEIGHTED UNDIRECTED)\n";
   }
   catch (exception error)
   {
      cout << "3. " << error.what() << endl;
   }
   try
   {
      g1.deleteEdge(B,D);
      cout << "didn't throw exception for deleting non existant edge (UNWEIGHTED UNDIRECTED)\n";
   }
   catch (exception error)
   {
      cout << "4. " << error.what() << endl;
   }
   g1.dump();
   return 0;
}


