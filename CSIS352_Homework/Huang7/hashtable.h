#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include <iostream>
#include <vector>
#include <list>
#include "constants.h"
using namespace std;
template <class T>
class HashTable{
    
public:
    // method - default constructor
    // description - created a HashTable with size and a method pointer
    // preconditions - none
    // postconditions - a HashTable object was created
    // method input - int size and a method pointer
    // method output - none   
    HashTable(int,int (*)(const T&));
    // method - insert
    // description - insert the T into the hashtable
    // preconditions - a hashtable was created and pass a T as a argument
    // postconditions - T object was inserted into the hashtable
    // method input - T boject
    // method output - none 
    void insert(const T&);
    // method - search
    // description - search the T from the hashtable throw exception when the hash value is outside of the table range, throw exception if the object has existed in the table
    // preconditions - a hashtable was created and pass a T as a argument
    // postconditions - return true if the T bojce exist in hashtable, otherwise return false
    // method input - T boject
    // method output - bool  
    bool search(const T&);
   
    // method - collisions
    // description - sreturn how many collisions does the hash tabel have
    // preconditions - a hashtable was created 
    // postconditions - return number of the collisions
    // method input - none
    // method output - int
    int collisions();
    
    // method - dump
    // description - dump out the has tables with collisions
    // preconditions - a hashtable was created 
    // postconditions - the hash table was printed in the screen
    // method input - none
    // method output - none
    void dump();
    
    // method - retrieve
    // description - retrieve the object from the hashtable, throw exception when the hash value is outside of the table range and throw exception when the object was not existed in the table
    // preconditions - a hashtable was created and T object was given as argument
    // postconditions - retrieve the object
    // method input - T object
    // method output - none
    void retrieve(T&);
private:
    struct HashNode{
        list<T> hashItemList;
    };
    int (*hashFunction)(const T&);
    vector<HashNode> hashtable;
};

template <class T>
HashTable<T>::HashTable(int s,int (*f)(const T&)){
    
    hashtable.resize(s);
    hashFunction = f;
}
template <class T>
void HashTable<T>::insert(const T& t){
    int key = hashFunction(t);
    int size = hashtable.size();
    if(key >= size){    
        throw range_error("The hash value is outside the table range");
    }else{
        if(!search(t)){    //checking if the t object has existed in the hashtable
            typename vector<HashNode>::iterator hp;
            hp = hashtable.begin();
            for(int i=0; i <key; i++){
                hp++;
            }
        
            hp->hashItemList.push_back(t);
        }else{
            throw logic_error("No duplicates, the item has existed in the hashtable");
        }
    }
}
template <class T>
bool HashTable<T>::search(const T& t)  {
    bool isThere =false;
    typename vector<HashNode>::iterator hp;
    hp = hashtable.begin();
    while(hp != hashtable.end()){
        typename list<T>::iterator lp;
        lp = hp->hashItemList.begin();
        while(lp != hp->hashItemList.end()){
            if(*lp == t){
                isThere = true;
            } 
            lp++;
        }
            hp++;
    }
    return isThere;
}
template <class T>
void HashTable<T>::dump() {
    cout<< "There were ";
    cout<<collisions();
    cout<<" collisions"<<endl;
    int index= 0;
    typename vector<HashNode>::iterator hp;
    hp = hashtable.begin();
    while(hp != hashtable.end()){
        typename list<T>::iterator lp;
        lp = hp->hashItemList.begin();
        if(index<10){
        	cout<<"hashtable[ "<<index<<"] : ";
        }else{
            cout<<"hashtable["<<index<<"] : ";
        }
        if(lp == hp->hashItemList.end()){
            cout<< "{empty}";
        }else{
            while(lp != hp->hashItemList.end()){
                cout<<*lp<<" ";
                lp++;
            }
        }
        cout<<endl;
        index++;
        hp++;
    }
}
template <class T>
int HashTable<T>::collisions(){
    int collisionsCounter = 0;
    typename vector<HashNode>::iterator hp;
    hp = hashtable.begin();
    while(hp !=hashtable.end()){
        if(hp->hashItemList.size()>1){
        collisionsCounter += hp->hashItemList.size() -1;
        }
        hp++;
    }
    
    return collisionsCounter;
}
template <class T>
void HashTable<T>::retrieve(T& t){
    int key = hashFunction(t);
    int size = hashtable.size();
    if(key >= size){ 
        throw range_error("The hash value is outside the table range");
    }else{
        typename vector<HashNode>::iterator hp;
        hp = hashtable.begin();
    
        for(int i =0; i<key; i++){
            hp++;
        }
        if(search(t)){    //if  the object is exist in the  hashtable
            typename list<T>::iterator lp;
            lp = hp->hashItemList.begin();
            while(lp != hp->hashItemList.end()){
                if(*lp == t){
                    t = *lp;
                    lp =  hp->hashItemList.end();
                } else{
                    lp++;
                }
            
            }
            
        }else{
            throw logic_error( "The item is not in the hash table");
        }
    }
}
#endif
    
