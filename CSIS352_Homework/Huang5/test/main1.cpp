#include <iostream>
using namespace std;
#include "graph.h"
//using namespace GraphNameSpace;

int main()
{
   cout << "***************************************************************************\n";
   cout << "main1.cpp                          UNWEIGHTED UNDIRECTED\n";
   Graph<char> g1;
   char A='A', B='B', C='C', D='D';
   g1.insertVertex(A);
   g1.insertVertex(B);
   g1.insertVertex(C);
   g1.insertVertex(D);
   g1.insertEdge(A,B);
   g1.insertEdge(A,C);
   g1.insertEdge(A,D);
   g1.insertEdge(B,C);
   g1.insertEdge(B,D);
   g1.insertEdge(C,D);
   g1.dump();
   g1.deleteEdge(D,A);
   cout << "--- deleted edge (D,A) ---\n";
   g1.dump();

   return 0;
}


