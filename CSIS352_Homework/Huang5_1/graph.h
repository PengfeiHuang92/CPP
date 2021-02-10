#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

enum mapFormat {DIRECTED,WEIGHTED};



template <class T>
class Graph
{
    public:
	//constructor
    Graph();
	Graph(mapFormat);
	Graph(mapFormat,mapFormat);
	bool isEmpty();
    bool isFull();
    void insertVertex(T);
    void insertEdge(T,T,int);
    private:
	//why the struct can not be outside of the Graph class
	struct ListNode{
		T nodeName ;
		int weight ;
	};
	struct GraphNode{
		T vertexItem;
		list<ListNode> adjacencylist;
	};

	int size;
	bool isDirected;
	bool isWeighted;
	
	vector<GraphNode> vertices;
    
};
template <class T>
void Graph<T>::insertEdge(T from, T to, int weight){
    ListNode tmpListNode;     //listNode
    tmpListNode.nodeName = to;
    tmpListNode.weight = weight;
    
    typename vector<GraphNode>::iterator p;      //pl is the iterator of vertices
    p = vertices.begin();
    while (p != vertices.end()){
      if(p->vertexItem == from){
        
          bool isthere = false;
          typename list<ListNode>::iterator pl;  //pl is the iterator of adjacencylist
          pl = p->adjacencylist.begin();
          while (pl != p->adjacencylist.end()){
                if(pl->nodeName == to){
                    isthere =true;
                }
                pl++;
          }
          if(isthere == false){   //checking if the T is exist in the list 
          p->adjacencylist.push_front(tmpListNode);
          }else{
              throw logic_error("duplicate edge in insertEdge");
        }
    }
    p++;
    }
    
    
}
template <class T>
void Graph<T>::insertVertex(T tempType){
 	
    bool isthere = false;
    typename vector<GraphNode>::iterator p;
    p = vertices.begin();
    while (p != vertices.end()){
      if(p->vertexItem == tempType){
          isthere =true;
         
    }
    p++;
   
    }
    if(isthere == false){
     GraphNode tmpNode;
    tmpNode.vertexItem = tempType;
    vertices.push_back(tmpNode);
    size++;
    
    }else{
        throw logic_error("duplicate vertex in insertVertex");
    }
   
}
template <class T>
bool Graph<T>::isFull(){
	return (size == 100);
}
template <class T>
bool Graph<T>::isEmpty(){
	return (size == 0);
}
template <class T>
Graph<T>::Graph(){
	size = 0;
	isDirected = false;
	isWeighted = false;
 
}
template <class T>
Graph<T>::Graph(mapFormat f){
	size = 0;
 
	switch(f){
        case DIRECTED: isDirected =true; break;
        case WEIGHTED: isWeighted = true; break;
        default:
            isDirected = false;
	    isWeighted = false;
    }
}
template <class T>
Graph<T>::Graph(mapFormat f1,mapFormat f2){
	size = 0;
   
	switch(f1){
        case DIRECTED: isDirected =true; break;
        case WEIGHTED: isWeighted = true; break;
        default:
            isDirected = false;
	    isWeighted = false;
    }
    switch(f2){
        case DIRECTED: isDirected =true; break;
        case WEIGHTED: isWeighted = true; break;
        default:
            isDirected = false;
	    isWeighted = false;
    }
}
#endif
