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
		    
	        explicit Array();
		Array(int);    //constructor with one int
		Array(int, int);    //constructor takes two ints
		~Array();    //destructor
		Array (const Array&);    //copy constructor
		const Array& operator = (const Array&);    // operator =
		T& operator[](int index);
        	const T& operator[](int index) const;
		int getStartIndex() const;
		int Size() const;
		void Resize(int);
		void setStartIndex(int);
	private:
		int startIndex;
		int size;	
		T *theArray;	
};
template <class T>
void Array<T>::setStartIndex(int s){
	
	
	for(int i=size+s; i < startIndex; i--){
		
	}
	startIndex = s;
	size = size +s;
}
template <class T>
void Array<T>::Resize(int s){
	if(s>=0){
	    if(size < s){
	        for (int i = size; i < s ; i++ )
			theArray[i]=0;	
	    }
	size =s;

        }else{
	    throw out_of_range("out_of_range: index out of range");
	}
}
template <class T>
T& Array<T>::operator[](int index){    //overloading the [] operator
	//cerr<<"overloading the [] operator "<<endl;
	if(index < size && index >= startIndex){

		return theArray[index-startIndex];
	}else{
	
		throw out_of_range("out_of_range: index out of range");
	}
}
template <class T>
const T& Array<T>::operator[](int index) const{    //overloading the [] operator
	//cerr<<"overloading the [] operator (const)"<<endl;

	if(index < size && index >=startIndex){
		return theArray[index-startIndex];
	}else{

		throw out_of_range("out_of_range: index out of range");
	}
}
template <class T>
Array<T>::~Array(){     //destructor

	//cerr<<"destructor"<<endl;
	delete [] theArray;
	theArray = NULL;
	
}

template <class T>
Array<T>::Array(const Array<T>& array){   //copy constructor
	//cerr<<"copy constructor"<<endl;

	
	theArray = new T[array.size];
	startIndex = array.startIndex;
	
	size = array.size;
	for(int i = 0; i < array.Size(); i++){
		theArray [i] = array.theArray[i];
	
	}

}

template <class T>
const Array<T>& Array<T>::operator = (const Array<T>& array){    //operator =
	//cerr<<"operator ="<<endl;
	if(&array != this){

		delete [] theArray;
		theArray  = new T[array.size];
		startIndex = array.startIndex;
	
		size = array.size;
		for (int i = array.startIndex; i < array.Size(); i++){
			theArray[i] = array.theArray[i];
		}
	
	}

	return *this;
}//end of operator =
template <class T>      //constructor without argument
Array<T>::Array(){
	//cerr<<"constructor "<<endl;
	size =0;
	startIndex = 0;
	theArray = new T[size];
	
	
	
	
}
template <class T>
Array<T>::Array(int arraySize ){  //constructor with one int
	//cerr<<"constructor with one int "<<endl;
	theArray = new T[arraySize];
	startIndex = 0;
	
	size =  arraySize;
	
}


template <class T>
Array<T>::Array(int start, int end){  //constructor with two ints
	//cerr<<"constructor with two ints "<<endl;
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
