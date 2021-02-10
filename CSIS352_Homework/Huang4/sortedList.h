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
       
        // method - default constructor
        // description - created the sortedList with default value
        // preconditions - none
        // postconditions - a sortedList was created with listTop to NULL, size to 0, and sortOreder to ASCENDING
        // method input - none
        // method output - none   
        explicit sortedList();

        // method - constructor with outputFormat
        // description - created the sortedList with given outputFormat 
        // preconditions - none
        // postconditions - a sortedList was created with listTop to NULL, size to 0, and sortOreder to the argument
        // method input - outputFormat
        // method output - none   
        sortedList(const outputFormat);
        
        // method - copy constructor
        // description - created the sortedList based on the  given sortedList 
        // preconditions - sortedList was given
        // postconditions - a copy of the sortedList was created 
        // method input - sortedList
        // method output - none   
        sortedList(const sortedList<T>&);
        // method - destructor
        // description - deleted the sortedList object
        // preconditions - none
        // postconditions - the sortedList was deleted 
        // method input - none
        // method output - none 
        ~sortedList();
        // method - isEmptyList
        // description - return true if the sortedList does not contain anything else return true
        // preconditions - a sortedList was created
        // postconditions - a bool value was retured
        // method input - none
        // method output - bool value 
        bool isEmptyList();
        // method - insertItem
        // description - insert an item type T into the sortedList
        // preconditions - a sortedList was created
        // postconditions - a bool value is retured
        // method input - T type
        // method output - none
        void insertItem(T);
        
        // method - length
        // description - return the size of the sortedList
        // preconditions - a sortedList was created
        // postconditions - the sortedList size is returned
        // method input - none
        // method output - int size
        int length() const;
        // method - valueAt
        // description - return the value at given index
        // preconditions - a sortedList was created, throw exception if idnex is invaild
        // postconditions - return the item based on the index
        // method input - int index
        // method output - T item
        const T& valueAt(int) const;
        // method - inList
        // description - return true if the item T is in the list else return false
        // preconditions - a sortedList was created
        // postconditions - a bool value was retured
        // method input - T item
        // method output - bool value
        bool inList(T);
        // method - indexing operator (pass by value)
        // description - overloading the indexing operator
        // preconditions - int index of the sortedList
        // postconditions - overloading the indexing operator
        // method input - a sortedList
        // method output - a address of the sortedList based on the index
        //T& operator[](int index);
        // method - indexing operator (pass by reference)
        // description - overloading the indexing operator
        // preconditions - int index of the sortedList
        // postconditions - overloading the indexing operator
        // method input - a sortedList
        // method output - a address of the sortedList based on the index
        const T& operator[](int index) const;
        // method -operator =
        const sortedList<T>& operator=(const sortedList<T>&);
        // method - deleteItem
        // description - deleted the item from the sortedList, throw exception if item does not in the sortedList
        // preconditions - item T type
        // postconditions - a item was deleted from the sortedList or exception was throw
        // method input - item T type
        // method output - none
        void deleteItem(const T&);
        // method - deleteAll
        // description - deleted all the item from the sortedList, throw exception if item does not in the sortedList
        // preconditions - item T type
        // postconditions - all the same items was deleted from the sortedList or exception was throw
        // method input - item T type
        // method output - none
        void deleteAll(const T&);
        // method - traverse
        // description - traverse the items based on the method pointer
        // preconditions - an void pointer method
        // postconditions - traversed the items based on the method pointer
        // method input - a void method takes T type as argument
        // method output - none
        void traverse(void (*) (T&));
        //merge- merge
        // description - merge the sortedList into this
        // preconditions - other sortedList is given
        // postconditions - other sortedList have been merged into this
        // method input - sortedList<T>
        // method output - none
        void merge(const sortedList<T>&);
        // method - removeDuplicates
        // description - removed all the Duplicates item from the sortedList, throw exception if item does not in the sortedList
        // preconditions - item T type
        // postconditions - all the Duplicates items was remove from the sortedList or exception was throw
        // method input - none
        // method output - none
        void removeDuplicates();
        // method - setOrder
        // description - set the order based on the argument
        // preconditions - outputFormat
        // postconditions -sortedList have been set to new outputFormat
        // method input - outputFormat
        // method output - none
        void setOrder(outputFormat);
        // method - destroyList
        // description - delete all the items from the sortedList
        // preconditions - a sortedList was created
        // postconditions -all the items have been deleted
        // method input - none
        // method output - none
        void destroyList();
    private:
        int size;     //size of the sortedList
        outputFormat sortOrder;    //output order
        nodeType<T> *listTop; //pointer to the list
        // method - copyList
        // description - function to make a copy of otherList
        // preconditions - outputFormat
        // postconditions -A copy of otherList is created and assigned to this list
        // method input - sortedList<T>
        // method output - none
        
        void copyList(const sortedList<T>&);
        // method - deleteList
        // description - function to delete the sortedList
        // preconditions - a sortedList was created
        // postconditions - the sortedList was deleted
        // method input - none
        // method output - none
        void deleteList();
        // method - reverse
        // description - function to reverse the sortedList
        // preconditions - a sortedList was created
        // postconditions - the sortedList was reversed
        // method input - none
        // method output - none
        void reverse();
    
     
}; 	

    template <class T>
    void sortedList<T>::destroyList(){
     
        deleteList();
    }
    template <class T>
    void sortedList<T>::setOrder(outputFormat f){
        if(sortOrder != f){
            reverse();
            sortOrder = f;
        }
    }
    template <class T>
    void sortedList<T>::reverse(){
        nodeType<T> *current,*next,*afterNext;
        
        current = listTop;
        next = current->link;
        afterNext = next->link;
         listTop->link = NULL; //set the list node link to null
        if(current != NULL && next != NULL){
           while(afterNext != NULL){
                next->link = current;
                current = next;
                next = afterNext;
                afterNext = afterNext->link;
                
        }
            next->link = current;
            listTop=next;
            listTop = next;
        }
       
        
    }
    template <class T>
    void sortedList<T>::removeDuplicates(){
          nodeType<T> *current, *newNode;
     
          newNode = new nodeType<T>;
      
          current = listTop;
          listTop = newNode;
          newNode->info = current->info;
          current = current->link;  //point the current pointer to next nodeType
          size =1;   //reset the size to 1 since the new sortedList only contain one info which is current->info
          while(current != NULL){
    
              if(inList(current->info) == false){
                  newNode->link = current;
                  newNode = newNode->link;
                  size++;
            }
       
            current = current->link;
        }
       
        newNode->link = NULL;    //set the last item's link to NULL
   
    }
    template <class T>
    void sortedList<T>::merge(const sortedList<T>& otherList){
	nodeType<T> *tmp;
	
	tmp = otherList.listTop;
        while(tmp != NULL){
		//this->insertItem(tmp->info);
	    //insertItem(tmp->info);	
            (*this).insertItem(tmp->info);
		
            tmp = tmp->link;
  
        }
    
        
    }
    template <class T>
    void sortedList<T>::traverse(void (*f)(T&))
    {
	nodeType<T> *tmpNode;
	tmpNode = listTop;
	
    for (int i=0; i<size; i++){
        f(tmpNode->info);
        tmpNode = tmpNode->link;
    }
    }
       
    template <class T>
    void sortedList<T>::deleteAll(const T& item ){
       
        int count=0;
        nodeType<T> *lastNode,*current;
     
        lastNode = new nodeType<T>;
        current = listTop;
        lastNode = listTop;

		while(current->link!=NULL){
            if(current->info == item){
                lastNode->link = current->link;
                current->link = lastNode;
                size--;
                count++;
            }
                lastNode = current;
                current = current->link;
      
		}
		if(count == 0 ){
                throw logic_error("deleteAll failed, item not in list");
             
        }
	
    }

    template <class T>
    void sortedList<T>::deleteItem(const T& item  ){
        bool tmp=true;
        nodeType<T> *lastNode,*current;
        current = new nodeType<T>;
        lastNode = new nodeType<T>;
        current = listTop;
        lastNode = listTop;
       while(tmp){
            if(current==NULL){
                throw logic_error("deleteItem failed, item not in list");
                tmp=false;
            }else if(current->info == item){
                if(current == listTop){
                    current = listTop->link;
                    lastNode = listTop->link;
                    listTop = listTop->link;
                }else{
                    lastNode->link = current->link;
                }
                size--;
                tmp=false;
            }else{
                lastNode = current;
                current = current->link;
            }
           
            
		}
	
    }
    template <class T>
    const sortedList<T>& sortedList<T>::operator=(const sortedList<T>&  otherList){
        if (this != &otherList) //avoid self-copy
        {
        listTop = NULL;
		size =0;
        copyList(otherList);
        }//end else

        return *this; 
        
    }
    template <class T>
    bool sortedList<T>::inList( T item){
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
        if(index > size)
            throw out_of_range("out_of_range: index out of range");
		nodeType<T> *newNode;
		newNode = new nodeType<T>;
		newNode = listTop;
		for(int i =0 ; i < index ; i++){
			newNode = newNode->link;
		}
		return newNode->info;
	}
/***
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
***/
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
            case ASCENDING:    //when  ASCENDING
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
            case DESCENDING:  //when  DESCENDING
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


