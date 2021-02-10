// File:    array.h
// Author:  Pengfei Huang

//Description:
//This file contains the specification for a Array and DateException
#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>  
using namespace std;

namespace ArrayNameSpace{


//Array class	
template <class T>
class Array{

	public:
		// method - Array constructor without argument
		// description - to give the Array size = 0 but does not give the location of Array
		// preconditions - none
		// postconditions - a Array was created with size = 0
		// method input - none
		// method output - none    
	    explicit Array();
        // method - Array constructor takes one int argument
		// description - to give the Array size of int
		// preconditions - int start
		// postconditions - a Array was created with size of int
		// method input - int size
		// method output - none  
		Array(int);    
        // method - Array constructor takes two int arguments
		// description - to give the Array startIndex of int and endIndex of int
		// preconditions - int startIndex and int endIndex
		// postconditions - a Array was created with startIndex and endIndex
		// method input - int startIndex, int endIndex
		// method output - none 
		Array(int, int);    
        // method - Array destructor
		// description - delete the template pointer 
		// preconditions - none
		// postconditions - the template pointer was deleted
		// method input - none
		// method output - none 
		~Array();   
        // method - Array copy constructor
		// description - created a copy of Array 
		// preconditions - a Array 
		// postconditions - the Array was copied
		// method input - a Array
		// method output - none 
		Array (const Array&);
        // method - operator =
		// description - overloading the sign operator 
		// preconditions - A Array
		// postconditions -overloading the sign operator
		// method input - a Array
		// method output - a Array 
		const Array& operator = (const Array&);    // operator =
        // method - indexing operator (pass by value)
		// description - overloading the indexing operator
		// preconditions - int index of the array
		// postconditions - overloading the indexing operator
		// method input - a Array
		// method output - a address of the array based on the index
		T& operator[](int index);
        // method - indexing operator (pass by reference)
		// description - overloading the indexing operator
		// preconditions - int index of the array
		// postconditions - overloading the indexing operator
		// method input - a Array
		// method output - a address of the array based on the index
        const T& operator[](int index) const;
        // method - Reverse
		// description - reverse the array and return it without changing it 
		// preconditions - a array was created
		// postconditions - a array was returned after reverse the order
		// method input - none
		// method output - a Array 
        Array<T> Reverse() const;
        // method - Descending
		// description - set the order of the Array to Descending
		// preconditions - a array was created
		// postconditions - a Array order have been changed to Descending
		// method input - none
		// method output - a Array 
        Array<T> Descending();
        // method - Descending
		// description - set the order of the Array to Ascending
		// preconditions - a array was created
		// postconditions - a Array order have been changed to Ascending
		// method input - none
		// method output - a Array 
        Array<T> Ascending();
        // method - getStartIndex
		// description - return the startIndex of the Array 
		// preconditions - a array was created
		// postconditions - a startIndex was returned
		// method input - none
		// method output - startIndex
		int getStartIndex() const;
        // method - Size
		// description - return the size of the Array 
		// preconditions - a array was created
		// postconditions - the size of the array was returned
		// method input - none
		// method output - size of the Array
		int Size() const;
        // method - Resize
		// description - the size of the Array was changed based on the argument
		// preconditions - a array was created and a correct size was given as argument
		// postconditions - the size of the array was changed
		// method input - new size of the Array
		// method output - none
		void Resize(int);
        // method - setStartIndex
		// description - setting the startIndex based on the argument
		// preconditions - a array was created and a correct startIndex was given as argument
		// postconditions - the startIndex of the array was changed
		// method input - new startIndex of the Array
		// method output - none
		void setStartIndex(int);
        
        //overloading the relational operator
        bool operator==(const Array&);
        bool operator!=(const Array&);
        bool operator<(const Array&);
        bool operator<=(const Array&);
        bool operator>(const Array&);
        bool operator>=(const Array&);
        
	private:
		int startIndex;     //startIndex of the Array
		int size;	//size of the Array
		T *theArray;	 //the pointer of the Array
};

template <class T>
Array<T> Array<T>::Ascending() {
    T tmp1;  //tmp item for swapping
    Array<T> tmpArray = *this;
     for(int i = tmpArray.Size(); i >=0; i--){
         for(int j = tmpArray.Size()-1; j  > tmpArray.Size()-i ; j --){
             if(tmpArray.theArray[j] < tmpArray.theArray[j-1]){
                 tmp1 = tmpArray.theArray[j];
                 tmpArray.theArray[j] = tmpArray.theArray[j-1];
                 tmpArray.theArray[j-1] = tmp1;
             }
         }
     }
   
    return tmpArray;
}
template <class T>
Array<T> Array<T>::Descending() {
    T tmp1;  //tmp item for swapping
    Array<T> tmpArray = *this;
    
     for(int i = tmpArray.Size(); i >=0; i--){
         for(int j = tmpArray.Size()-1; j  > tmpArray.Size()-i ; j --){
             if(tmpArray.theArray[j] > tmpArray.theArray[j-1]){
                 tmp1 = tmpArray.theArray[j];
                 tmpArray.theArray[j] = tmpArray.theArray[j-1];
                 tmpArray.theArray[j-1] = tmp1;
             }
         }
     }
   
    return tmpArray;
}


template <class T>
Array<T> Array<T>::Reverse() const{
 	Array<T> tmpArray =*this;       	
	for (int i=0; i<size;i++)
		tmpArray.theArray[i] = theArray[size-1-i];  //size-1-i since the array end with size 6 but index was 5
 	return tmpArray;
 }
template <class T>
bool Array<T>::operator>=(const Array& array){
    return !(*this < array ) ;
}
template <class T>
bool Array<T>::operator>(const Array& array){
    return ! (*this <= array) ;
}
template <class T>
bool Array<T>::operator<=(const Array& array){
    return *this < array || *this == array ;
}

template <class T>
bool Array<T>::operator<(const Array& array){
    bool tmp = false;
    int count = 0;
    for(int i = 0; i<size;i++){
    	if(theArray[i]<array[array.startIndex+i]){
    	    tmp = true;      
	}else{
	    count++;  //counting how many items do not less than the other array
	}
    }
    if(array.size > size && count == size){ //checking if those two arrays contain the same items by the array.size is greater than size. such as apple < apples
	tmp = true;
    }
 
    return tmp;
}

template <class T>
bool Array<T>::operator==(const Array& array){
    bool tmp = true;
    if(size == array.size){
        for(int i = 0; i<size;i++){
            if(theArray[i]!=array[array.startIndex+i])
                tmp = false;
        }
    }else{
        tmp = false;
    }
    return tmp;
    
}
template <class T>
bool Array<T>::operator!=(const Array& array){
    return !(*this == array);
}
template <class T>
void Array<T>::setStartIndex(int s){
	startIndex = s;
}

template <class T>
void Array<T>::Resize(int s){
	if(s>=0){    //the size must be greater than 0
		T *tmpArray = new T[s];
		for(int i = 0; i < size ; i++){
			tmpArray[i] = theArray[i];
		}
		delete [] theArray;
		theArray = NULL;
		theArray = tmpArray;
		size = s;

        }else{
	    throw out_of_range("out_of_range: index out of range");
	}
}
template <class T>
T& Array<T>::operator[](int index){    //overloading the [] operator
	//cerr<<"overloading the [] operator "<<endl;
	if(index < size + startIndex && index >= startIndex){

		return theArray[index-startIndex];
	}else{
		
		throw out_of_range("out_of_range: index out of range");
	}
}
template <class T>
const T& Array<T>::operator[](int index) const{    //overloading the [] operator
	//cerr<<"overloading the [] operator (const)"<<endl;   
	
	if(index < size + startIndex && index >= startIndex){
		return theArray[index-startIndex];
	}else{			
		throw out_of_range("out_of_range: index out of range");
	}
}
template <class T>
Array<T>::~Array(){     //destructor
	delete [] theArray;
	theArray = NULL;
}

template <class T>
Array<T>::Array(const Array<T>& array){   //copy constructor
	theArray = new T[array.size];
	startIndex = array.startIndex;
	size = array.size;
	for(int i = 0; i < array.Size(); i++)
	    theArray [i] = array.theArray[i];
}

template <class T>
const Array<T>& Array<T>::operator = (const Array<T>& array){    //operator =

	if(&array != this){
	    delete [] theArray;
	    theArray  = new T[array.size];
	    startIndex = array.startIndex;
	    size = array.size;
	    for (int i = 0; i < array.Size(); i++){
		theArray[i] = array.theArray[i];
	    }
	}
	return *this;
}
template <class T>      //constructor without argument
Array<T>::Array(){
	size =0;
	startIndex = 0;
	theArray = new T[size];
	
}
template <class T>
Array<T>::Array(int arraySize ){  //constructor with one int
	theArray = new T[arraySize];
	startIndex = 0;
	size =  arraySize;
}


template <class T>
Array<T>::Array(int start, int end){  //constructor with two ints
	startIndex = start;
	size =  end - start +1;
	theArray = new T[size];
}

template <class T>
int Array<T>::getStartIndex() const{
	return startIndex;
}
template <class T>
int Array<T>::Size() const{
	return size;
}
}

#endif
