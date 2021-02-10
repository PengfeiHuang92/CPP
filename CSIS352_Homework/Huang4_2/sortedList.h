// File:    sortedList.h
// Author:  Pengfei Huang

//Description:
//This file contains the specification for a sortedList
#ifndef _FRACTION_H_
#define _FRACTION_H_


namespace sortedListSpace{
enum outputFormat {ASCENDING,DESCENDING};
template <class T>
struct nodeType
{
	T info;
	nodeType<T> *link;
};

template <class T>
class sortedList{
    public:
	//default constructor
       explicit sortedList();
	//constructor with outputFormat
        sortedList(const outputFormat);
	//copy constructor
	sortedList(const sortedList<T>&);
	//destructor
	~sortedList();
	//isEmptyList
	bool isEmptyList();
	//insertItem
	void insertItem(T);
	//length
	int length() const;
	//valueAt
	const T& valueAt(int) const;
    //inList
    bool inList(int);
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
    //operator =
    const sortedList<T>& operator=(const sortedList<T>&);
    private:
	int size;
	outputFormat sortOrder;
	nodeType<T> *listTop; //pointer to the list
 	void copyList(const sortedList<T>& otherList);
      //Function to make a copy of otherList.
      //Postcondition: A copy of otherList is created and
      //               assigned to this list
	void deleteList();
      //Function to delete the List.
     
}; 	

    template <class T>
    const sortedList<T>& sortedList<T>::operator=(const sortedList<T>&  otherList){
        
        
    }
    template <class T>
    bool sortedList<T>::inList(int item){
        bool tmp = false;
        nodeType<T> *newNode;
        newNode = new nodeType<T>;
        newNode = listTop;
        for(int i =0 ; i < size ; i++){
			if(newNode->info == item){
                tmp =true;
            }
            newNode = newNode->link;
            
		}
        return tmp;
    }
	template <class T>
	const T& sortedList<T>::valueAt(int index) const{
	
		nodeType<T> *newNode;
		newNode = new nodeType<T>;
		newNode = listTop;
		for(int i =0 ; i < index ; i++){
			newNode = newNode->link;
		}
		return newNode->info;
	}
template <class T>
T& sortedList<T>::operator[](int index){    //overloading the [] operator
	//cerr<<"overloading the [] operator "<<endl;
    nodeType<T> *tmp;
    tmp = listTop;
	if(index < size  && index >= 0){
        for(int i = 0; i < index; i++){
           tmp = tmp->link;
        }
		return tmp->info;
	}else{
		
		throw out_of_range("out_of_range: index out of range");
	}
}
template <class T>
const T& sortedList<T>::operator[](int index) const{    //overloading the [] operator
	//cerr<<"overloading the [] operator (const)"<<endl;   
	
	nodeType<T> *tmp;
    tmp = listTop;
	if(index < size  && index >= 0){
        for(int i = 0; i < index; i++){
           tmp = tmp->link;
        }
		return tmp->info;
	}else{
		
		throw out_of_range("out_of_range: index out of range");
	}
}
	template <class T>
	int sortedList<T>::length() const{
		return size;	
	}
	
	//default constructor
	template <class T>
        sortedList<T>::sortedList(){
		listTop = NULL;
		sortOrder = ASCENDING;
		size =0;
	}
	
	//constructor with outputFormat
	template <class T>
        sortedList<T>::sortedList(const outputFormat f){
		listTop = NULL;
		sortOrder = f;
		size =0;
	}
	
	//copy constructor
	template <class T>
	sortedList<T>::sortedList(const sortedList<T>& otherList){
		listTop = NULL;
		size =0;
		copyList(otherList);
	}
	
	//copyList
	template <class T>
	void sortedList<T>::copyList(const sortedList<T>& otherList){
		nodeType<T> *newNode, *current, *nextList;

		if(listTop != NULL){
			deleteList();
		}
		if(otherList.listTop == NULL){
			listTop = NULL;
			sortOrder = otherList.sortOrder;	
		}else{
			sortOrder = otherList.sortOrder;
		//copy the top item fron the otherlist and put it into listTop
			current = otherList.listTop;
			listTop = new nodeType<T>;
			listTop->info = current->info;
			listTop->link = NULL;
			nextList = listTop;
			current = current->link;
			size =1;
			//copy the remaining item form otherlist
			while(current != NULL){
				newNode = new nodeType<T>;
				newNode->info = current->info;
				newNode->link = NULL;
				nextList->link = newNode;
				nextList = newNode;
				current = current ->link;
				size++;
			}
		
		}

	}
	
	
	//delete List
	template <class T>
	void sortedList<T>::deleteList(){
		nodeType<T> *tmpLink;
		while(listTop != NULL){ //while there are elements in the list
			tmpLink = listTop;   //set tmpLink to point to the current node
			listTop = listTop->link;  //advance listTop to the next node
			delete tmpLink;    ////deallocate memory occupied by tmpLink
		}
		
	}
	//destructor
	template <class T>
	sortedList<T>::~sortedList(){
		size =0;
		deleteList();
	}
	//isEmptyList
	template <class T>
	bool sortedList<T>::isEmptyList(){
		return (listTop == NULL);
	}
	//insertItem
	template <class T>
	void sortedList<T>::insertItem(T item){
   
		
		nodeType<T> *newNode,*nextList,*current;
		newNode = new nodeType<T>;
        newNode->info = item;
        current = listTop;
        switch(sortOrder){
            case ASCENDING:
                if(listTop == NULL){
                    listTop = newNode;
                    newNode->link = NULL;
                }else{
                    if( listTop->link == NULL && listTop->info >= newNode->info){
                        newNode->link = listTop;
                        listTop = newNode;
                        
                    }else if(listTop->link == NULL && listTop->info < newNode->info){
                        newNode->link = NULL;
                        listTop->link = newNode;
                        
                    }else{
                        nextList = current->link;
                        if(listTop->info > newNode->info){
                            newNode->link = listTop;
                            listTop = newNode;
                        }else{
                        
                            while(nextList != NULL && nextList->info < newNode->info){
                                nextList = nextList->link;
                                current =current->link;
                            }
                    
                        newNode->link = nextList;
                        current->link = newNode;
                
                    
                        }
                    }
                    
                    
                }break;
            case DESCENDING:
                if(listTop == NULL){
                    listTop = newNode;
                    newNode->link = NULL;
                }else{
                    if( listTop->link == NULL && listTop->info <= newNode->info){
                        newNode->link = listTop;
                        listTop = newNode;
                        
                    }else if(listTop->link == NULL && listTop->info > newNode->info){
                        newNode->link = NULL;
                        listTop->link = newNode;
                        
                    }else{
                        nextList = current->link;
                        if(listTop->info < newNode->info){
                            newNode->link = listTop;
                            listTop = newNode;
                        }else{
                        
                            while(nextList != NULL && nextList->info > newNode->info){
                                nextList = nextList->link;
                                current =current->link;
                            }
                    
                        newNode->link = nextList;
                        current->link = newNode;
                
                    
                        }
                    }
                    
                    
                }break;
       
    
        }
         size++;
    }
		
        
        
            

        
		
	
	
	
	
}

#endif


