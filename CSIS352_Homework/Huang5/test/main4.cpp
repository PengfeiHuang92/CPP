#include <iostream>
using namespace std;
#include "graph.h"
//using namespace GraphNameSpace;

int main()
{
   cout << "***************************************************************************\n";
   cout << "main4.cpp                              WEIGHTED DIRECTED\n";
   Graph<char> g4(DIRECTED,WEIGHTED);
   char A='A', B='B', C='C', D='D';
   g4.insertVertex(A);
   g4.insertVertex(B);
   g4.insertVertex(C);
   g4.insertVertex(D);
   g4.insertEdge(A,B,10);
   g4.insertEdge(A,C,20);
   g4.insertEdge(A,D,30);
   g4.insertEdge(B,C,40);
   g4.insertEdge(B,D,50);
   g4.insertEdge(C,D,60);
   g4.insertEdge(D,A,70);
   g4.dump();

   return 0;
}


