#include <iostream>
using namespace std;
#include "graph.h"
//using namespace GraphNameSpace;

int main()
{
   cout << "***************************************************************************\n";
   cout << "main3.cpp                            UNWEIGHTED DIRECTED\n";
   Graph<char> g3(DIRECTED);
   char A='A', B='B', C='C', D='D';
   g3.insertVertex(A);
   g3.insertVertex(B);
   g3.insertVertex(C);
   g3.insertVertex(D);
   g3.insertEdge(A,B);
   g3.insertEdge(A,C);
   g3.insertEdge(A,D);
   g3.insertEdge(B,C);
   g3.insertEdge(B,D);
   g3.insertEdge(C,D);
   g3.insertEdge(D,A);
   g3.dump();
   g3.deleteVertex(C);
   cout << "--- deleted vertex C ---\n";
   g3.dump();

   return 0;
}


