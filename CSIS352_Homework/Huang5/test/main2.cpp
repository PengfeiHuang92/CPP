#include <iostream>
using namespace std;
#include "graph.h"
//using namespace GraphNameSpace;

int main()
{
   cout << "***************************************************************************\n";
   cout << "main2.cpp                            WEIGHTED UNDIRECTED\n";
   Graph<char> g2(WEIGHTED);
   char A='A', B='B', C='C', D='D';
   g2.insertVertex(A);
   g2.insertVertex(B);
   g2.insertVertex(C);
   g2.insertVertex(D);
   g2.insertEdge(A,B,10);
   g2.insertEdge(A,C,20);
   g2.insertEdge(A,D,30);
   g2.insertEdge(B,C,40);
   g2.insertEdge(B,D,50);
   g2.insertEdge(C,D,60);
   g2.dump();

   return 0;
}


