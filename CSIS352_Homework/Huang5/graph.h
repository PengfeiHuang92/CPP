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
        // method - default constructor
        // description - created the Graph with size , edge 0, undirected and unweighted
        // preconditions - none
        // postconditions - a graph object was created with default values
        // method input - none
        // method output - none   
        Graph();
        // method - default constructor
        // description - created the Graph with size , edge 0, and mapFormat
        // preconditions - none
        // postconditions - a graph object was created with default values and the given mapFormat
        // method input - mapFormat
        // method output - none  
        Graph(mapFormat);
        // method - default constructor
        // description - created the Graph with size , edge 0, and mapFormats
        // preconditions - none
        // postconditions - a graph object was created with default values and the given mapFormats
        // method input - mapFormat
        // method output - none  
        Graph(mapFormat,mapFormat);
        // method - isEmpty
        // description - return true when graph was empty, otherwise return false
        // preconditions - graph object had created
        // postconditions - a bool was return base on the size
        // method input - none
        // method output - bool 
        bool isEmpty() const;
        // method - isFull
        // description - return true when graph was full(size out 100), otherwise return false
        // preconditions - graph object had created
        // postconditions - a bool was return base on the size
        // method input - none
        // method output - bool 
        bool isFull() const;
        // method - insertVertex
        // description - insert the T object to the vector vertices
        // preconditions - graph object had created and vertices was not full
        // postconditions - a vertex was inserted into the vector
        // method input - template T object
        // method output - none
        void insertVertex(const T&);
        // method - insertEdge
        // description - insert the edge between the vertices, if the graph was unweighted, the weight will be set to 0 as default
        // preconditions - graph object had create and edge was not full
        // postconditions - a edge was inserted into the vector
        // method input - template T object (from) ,template T object (to),int weight
        // method output - none    
        void insertEdge(const T&,const T&,int i=0);
        // method - vertexCount
        // description - return the number of the vertices form the graph 
        // preconditions - graph object had created
        // postconditions - the number of the vertices was returned
        // method input - none
        // method output - int  
        int vertexCount() const;
        // method - vertexCount
        // description - return the number of the edge form the graph 
        // preconditions - graph object had created
        // postconditions - the number of the edge was returned
        // method input - none
        // method output - int 
        int edgeCount() const;
        // method - dump
        // description - print out the graph 
        // preconditions - graph object had created
        // postconditions - the graph was printed 
        // method input - none
        // method output - none
        void dump() const;
        // method - edgeWeight
        // description - return the weight between two verties
        // preconditions - graph object had created
        // postconditions - the weight was returned
        // method input - template T object (from) ,template T object (to)
        // method output - int
        int edgeWeight(const T&,const T&);
	    // method - isAdjacentTo
        // description - return true if the two verties has a edge otherwise return false
        // preconditions - graph object had created
        // postconditions - the bool was returned
        // method input - template T object (from) ,template T object (to)
        // method output - bool
        bool isAdjacentTo(const T&,const T&);
	    // method - deleteEdge
        // description - deleted the edge between two verties
        // preconditions - graph object had created
        // postconditions - the edge was deleted
        // method input - template T object (from) ,template T object (to)
        // method output - none
        void deleteEdge(const T&,const T&);
	    // method - deleteVertex
        // description - deleted the vertex
        // preconditions - graph object had created
        // postconditions - the vertex was deleted
        // method input - template T object 
        // method output - none
        void deleteVertex(const T&);
        // method - destroy
        // description - deleted the graph
        // preconditions - graph object had created
        // postconditions - the graph was deleted
        // method input - none
        // method output - none
        void destroy();
    private:
  	    //the struct contains the name of the template T and the weight, the default of weight is 0
        struct ListNode{
            T nodeName ;
            int weight=0 ;
        };
	    //the struct contains the Vertex and the list of edge
        struct GraphNode{
            T vertexItem;
            list<ListNode> adjacencylist;
        };
        
        int size;    //size of the graph
        int edge;    //size of the edge
        bool isDirected;     //is the grap is Directed
        bool isWeighted;    //is the grap is weighted
        
        vector<GraphNode> vertices;	//list of the vertices
	    // method - addEdge
        // description - add the edge between two vertices
        // preconditions - graph object had created and vertices was not full
        // postconditions - a edge was inserted into the vector
        // method input - template T object(from), template T object(to)
        // method output - none
        void addEdge(const T&,const T&,int);
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
            
    
    return tmpweight;
}

template <class T>
void Graph<T>::dump() const{
 
    cout<<"dumping graph:  DIRECTED   WEIGHTED   vertices:"<<size<<"   edges:"<<edge<<endl;
    cout<<"VERTEX           ADJACENT VERTICES"<<endl;
    cout<<"--------------   -------------------------------------------------------------"<<endl;
    
    typename vector<GraphNode>::const_iterator p;      //pl is the iterator of vertices
    p = vertices.begin();
    while (p != vertices.end()){
        cout<<setw(17)<<left<<p->vertexItem;
        typename list<ListNode>::const_iterator pl;  //pl is the iterator of adjacencylist
        pl = p->adjacencylist.begin();
          
        while (pl != p->adjacencylist.end()){
               
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
    
    if(isDirected){
        if(isWeighted){
            addEdge(from,to,weight);
        }else{
            addEdge(from,to,0);
        }
    }else{
        if(isWeighted){
            addEdge(from,to,weight);
            addEdge(to,from,weight);
        }else{
            addEdge(from,to,0);
            addEdge(to,from,0);
        }
    }
}

template <class T>
void Graph<T>::addEdge(const T& from, const T& to, int weight){
    
    
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
                }else if(isDirected){
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
