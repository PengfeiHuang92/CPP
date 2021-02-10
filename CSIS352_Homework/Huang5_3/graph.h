#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <iomanip>
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
	bool isEmpty() const;
    bool isFull() const;
    
    void insertVertex(const T&);
    void insertEdge(const T&,const T&,int);
    int vertexCount() const;
    int edgeCount() const;
    void dump();
    //return 0 when the map is unWeighted
    int edgeWeight(const T&,const T&);
    bool isAdjacentTo(const T&,const T&) ;
    void deleteEdge(const T&,const T&);
    void deleteVertex(const T&);
   
    void destroy();
    private:
	//why the struct can not be outside of the Graph class
	struct ListNode{
		T nodeName ;
		int weight=-1 ;
	};
	struct GraphNode{
		T vertexItem;
		list<ListNode> adjacencylist;
	};

	int size;
        int edge;
	bool isDirected;
	bool isWeighted;
	
	vector<GraphNode> vertices;
    
};
template <class T>
void Graph<T>::destroy(){
    vertices.clear();  //clearing all the vertex
    size = 0;    //set the size to 0
    edge = 0;    //set the size to 0
}
    


template <class T>
void Graph<T>::deleteVertex(const T& from){
    bool isthere =false;
    typename vector<GraphNode>::iterator p;
    typename list<ListNode>::iterator pl;
    p = vertices.begin();
    while (p != vertices.end()){
        pl = p->adjacencylist.begin();   
        while (pl != p->adjacencylist.end()){
            if(pl->nodeName == from){
            pl = p->adjacencylist.erase(pl);   //delete the edge when the vertex contain the edge with T
            edge--;
            }else{
                pl++;
            }
        }
          
          
        if(p->vertexItem == from){
            isthere =true;
            pl = p->adjacencylist.begin();
            while(pl != p->adjacencylist.end()){
                pl = p->adjacencylist.erase(pl);    //delete all the edge that T has
                edge--;
            }
          
            p = vertices.erase(p);   //delete the vertex
          
            size--;
        }else{
            p++;
        }
    
}
if(isthere==false){
         throw logic_error("non-existant vertex in deleteVertex");
    }
}
template <class T>
void Graph<T>::deleteEdge(const T& from, const T& to){
    bool isthere =false;
    typename vector<GraphNode>::iterator p;      //pl is the iterator of vertices
    typename list<ListNode>::iterator pl;  //pl is the iterator of adjacencylist
    p = vertices.begin();
    while (p != vertices.end()){
      if(p->vertexItem == from){
           pl = p->adjacencylist.begin();
           while (pl != p->adjacencylist.end()){
                 if(pl->nodeName == to){
                    isthere =true;
                    pl = p->adjacencylist.erase(pl);
                    edge--;
                 }else{
                 pl++;
                 }
          }
    }
       p++;
    }
    if(isthere==false){
         throw logic_error("non-existant vertex in deleteVertex");
    }
}
template <class T>
bool Graph<T>::isAdjacentTo(const T& from, const T& to){
    bool AdjacentTo = false;
    typename vector<GraphNode>::iterator p;      //pl is the iterator of vertices
    p = vertices.begin();
    while (p != vertices.end()){
        if(p->vertexItem == from){
        typename list<ListNode>::iterator pl;  //pl is the iterator of adjacencylist
        pl = p->adjacencylist.begin();
          
        while (pl != p->adjacencylist.end()){
            if(pl->nodeName == to){
              AdjacentTo = true;
            }
            pl++;
        }
        }
      p++;
    }
    return AdjacentTo;
}

template <class T>
int Graph<T>::edgeWeight(const T& from, const T& to)  {
  
    int tmpweight =0;
    if(isWeighted){
        typename vector<GraphNode>::iterator p;      //pl is the iterator of vertices
        p = vertices.begin();
        while (p != vertices.end()){
            if(p->vertexItem == from){
            typename list<ListNode>::iterator pl;  //pl is the iterator of adjacencylist
            pl = p->adjacencylist.begin();
            
            while (pl != p->adjacencylist.end()){
                if(pl->nodeName == to){
                tmpweight=pl->weight;
                }
                pl++;
            }
            }
        p++;
        }
            
    }
    return tmpweight;
}

template <class T>
void Graph<T>::dump(){
  //  dumping graph:  DIRECTED   WEIGHTED   vertices:13   edges:34
    cout<<"dumping graph:  DIRECTED   WEIGHTED   vertices:"<<size<<"   edges:"<<edge<<endl;
    cout<<"VERTEX           ADJACENT VERTICES"<<endl;
    cout<<"--------------   -------------------------------------------------------------"<<endl;
    
    typename vector<GraphNode>::iterator p;      //pl is the iterator of vertices
    p = vertices.begin();
    while (p != vertices.end()){
        cout<<setw(17)<<left<<p->vertexItem;
        typename list<ListNode>::iterator pl;  //pl is the iterator of adjacencylist
        pl = p->adjacencylist.begin();
          
        while (pl != p->adjacencylist.end()){
                //cout<<*pl.vertexItem;
                cout<< pl->nodeName<<"(";
                cout<< pl->weight<<")  ";
                
            pl++;
        }
        cout<<endl;
      p++;
    }
  
    cout<<endl;
    
}
template <class T>
int Graph<T>::edgeCount() const{
    return edge;
}
template <class T>
int Graph<T>::vertexCount() const{
    return size;
}
template <class T>
void Graph<T>::insertEdge(const T& from, const T& to, int weight){
    
    ListNode tmpListNode;     //listNode
    tmpListNode.nodeName = to;
    tmpListNode.weight = weight;
    if(edge <=100){   //checking if the edge is greater than the max size
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
                    p->adjacencylist.push_back(tmpListNode);
                    edge++;
                }else{
                    throw logic_error("duplicate edge in insertEdge");
                }
            }
            p++;
      }
    }else{
        throw logic_error("Edge can not be more than 100 ");
    }
    
}
template <class T>
void Graph<T>::insertVertex(const T& tempType){
 	if(size <=100){    //checking if the size of vertex greater than max size
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
    }else{
        throw logic_error("Vertex can not be more than 100");
    }
   
}
template <class T>
bool Graph<T>::isFull() const{
	return (size == 100);
}
template <class T>
bool Graph<T>::isEmpty() const{
	return (size == 0);
}
template <class T>
Graph<T>::Graph(){
	size = 0;
    edge = 0;
	isDirected = false;
	isWeighted = false;
 
}
template <class T>
Graph<T>::Graph(mapFormat f){
	size = 0;
    edge = 0;
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
    edge = 0;
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
