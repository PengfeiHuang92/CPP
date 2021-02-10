#ifndef H_listType
#define H_listType

#include <iostream>
#include <cassert>

using namespace std;

// NOTE: This is code from the textbook.  According to our standards, the
//       documentation is not complete.

template<class elemType>
class listType
{
public:
    bool isEmpty() const;
      //Function to determine whether the list is empty
      //Postcondition: Returns true if the list is empty;
      //               otherwise, returns false.
    bool isFull() const;
      //Function to determine whether the list is full
      //Postcondition: Returns true if the list is full; 
      //               otherwise, returns false.
    int listSize() const;
      //Function to determine the number of elements in the list
      //Postcondition: Returns the value of length.
    int maxListSize() const;
      //Function to determine the maximum size of the list
      //Postcondition: Returns the value of maxSize.
    void print() const;
      //Function to output the elements of the list
      //Postcondition: Elements of the list are output on the 
      //               standard output device.
    bool isItemAtEqual(int location, const elemType& item) const;
      //Function to determine whether item is the same as
      //the item in the list at the position specified 
      //by location
      //Postcondition: Returns true if the list[location] 
      //               is the same as item; otherwise, 
      //               returns false.
    void insertAt(int location, const elemType& insertItem);
      //Function to insert insertItem in the list at the 
      //position specified by location. 
      //Postcondition: Starting at location, the elements 
      //               of the list are shifted down, 
      //               list[location] = insertItem;, and
      //               length++;    
      //       If the list is full or location is out of
      //       range, an appropriate message is displayed.
    void insertEnd(const elemType& insertItem);
      //Function to insert an item at the end of the list 
      //The parameter insertItem specifies the item to be 
      //inserted.
      //Postcondition: list[length] = insertItem; and length++;
      //               If the list is full, an appropriate 
      //               message is displayed.
    void removeAt(int location);
      //Function to remove the item from the list at the 
      //position specified by location 
      //Postcondition: The list element at list[location] is 
      //               removed and length is decremented by 1.
      //       If location is out of range, an appropriate message
      //       is displayed.
    
    void retrieveAt(int location, elemType& retItem) const;
      //Function to retrieve the element from the list at the  
      //position specified by location 
      //Postcondition: retItem = list[location] 
      //      If location is out of range, an appropriate 
      //      message is displayed.
    
    void replaceAt(int location, const elemType& repItem);
      //Function to replace the elements in the list at the 
      //position specified by location. The item to be replaced 
      //is specified by the parameter repItem.
      //Postcondition: list[location] = repItem 
      //      If location is out of range, an appropriate 
      //      message is displayed.
    void clearList();
      //Function to remove all the elements from the list 
      //After this operation, the size of the list is zero.
      //Postcondition: length = 0;
    int seqSearch(const elemType& item) const;
      //Function to search the list for a given item. 
      //Postcondition: If the item is found, returns the location
      //               in the array where the item is found; 
      //               otherwise, returns -1.
    void insert(const elemType& insertItem);
      //Function to insert the item specified by the parameter 
      //insertItem at the end of the list. However, first the
      //list is searched to see whether the item to be inserted
      //is already in the list. 
      //Postcondition: list[length] = insertItem and length++
      //     If the item is already in the list or the list
      //     is full, an appropriate message is displayed.
    void remove(const elemType& removeItem);
       //Function to remove an item from the list. The parameter
      //removeItem specifies the item to be removed.
      //Postcondition: If removeItem is found in the list,
      //      it is removed from the list and length is 
      //      decremented by one.
    listType(int size = 100);
       //constructor
      //Creates an array of the size specified by the 
      //parameter size. The default array size is 100.
      //Postcondition: The list points to the array, length = 0,
      //               and maxSize = size
    listType (const listType< elemType >& otherList);
       //copy constructor
    ~listType();
      //destructor
      //Deallocate the memory occupied by the array.
    const listType<elemType>& 
                  operator=(const listType<elemType>&);
       //Overloads the assignment operator

protected:
    elemType *list;  //array to hold the list elements
    int length;   //variable to store the length of the list
    int maxSize;  //variable to store the maximum 
                  //size of the list
};

template <class elemType>
bool listType<elemType>::isEmpty() const
{
	return (length == 0);
}

template <class elemType>
bool listType<elemType>::isFull() const
{
	return (length == maxSize);
}

template <class elemType>
int listType<elemType>::listSize() const
{
	return length;
}

template <class elemType>
int listType<elemType>::maxListSize() const
{
	return maxSize;
}

template <class elemType>
void listType<elemType>::print() const
{
	int i;

	for (i = 0; i < length; i++)
		cout << list[i] << endl;
}

template <class elemType>
bool listType<elemType>::isItemAtEqual
                   (int location, const elemType& item)  const
{
	return(list[location] == item);
}

template <class elemType>
void listType<elemType>::insertAt
                   (int location, const elemType& insertItem)
{
	int  i;

	if (location < 0 || location >= maxSize)
		cout << "The position of the item to be inserted "
			 << "is out of range." << endl;
	else
		if (length >= maxSize)  //list is full
			cout << "Cannot insert in a full list" << endl;
		else
		{
			for (i = length; i > location; i--)
				list[i] = list[i - 1];	//move the elements down

			list[location] = insertItem;	//insert the item at the 
 										//specified position

			length++;	//increment the length
		}
} //end insertAt


template <class elemType>
void listType<elemType>::insertEnd(const elemType& insertItem)
{
        if (length >= maxSize)  //the list is full
                cout << "Cannot insert in a full list." << endl;
        else
        {
                list[length] = insertItem;      //insert the item at the end
                length++;       //increment length
        }
} //end insertEnd

template <class elemType>
void listType<elemType>::removeAt(int location)
{
	int i;

	if (location < 0 || location >= length)
    	cout << "The location of the item to be removed "
			 << "is out of range." << endl;
	else
	{
   		for (i = location; i < length - 1; i++)
	 		list[i] = list[i+1];

		length--;
	}
} //end removeAt

template <class elemType>
void listType<elemType>::retrieveAt
                     (int location, elemType& retItem) const
{
        if (location < 0 || location >= length)
        cout << "The location of the item to be retrieved is "
                         << "out of range." << endl;
        else
                retItem = list[location];
} // retrieveAt

template <class elemType>
void listType<elemType>::replaceAt
                    (int location, const elemType& repItem)
{
        if (location < 0 || location >= length)
        cout << "The location of the item to be replaced is "
                         << "out of range." << endl;
        else
                list[location] = repItem;
} //end replaceAt

template <class elemType>
void listType<elemType>::clearList()
{
	length = 0;
} // end clearList

template <class elemType>
int listType<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;

	for (loc = 0; loc < length; loc++)
	   if ( list[loc] == item)
	   {
		  found = true;
		  break;
	   }

	if (found)
		return loc;
	else
		return -1;
} //end seqSearch

template <class elemType>
void listType<elemType>::insert(const elemType& insertItem)
{
    int loc;

    if (length == 0)     //list is empty
        list[length++] = insertItem; //insert the item and
                                     //increment the length
    else
        if (length == maxSize)
            cout << "Cannot insert in a full list." << endl;
        else
        {
            loc = seqSearch(insertItem);

            if (loc == -1)   //the item to be inserted
                             //does not exist in the list
                list[length++] = insertItem;
            else
                cout << "the item to be inserted is already "
                     << "in the list. No duplicates are "
                     << "allowed." << endl;
        }
} //end insert

template <class elemType>
void listType<elemType>::remove(const elemType& removeItem)
{
	int loc;

	if (length == 0)
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);

		if (loc != -1)
			removeAt(loc);
		else
			cout << "The tem to be deleted is not in the list."
				 << endl;
	}

} //end remove

template <class elemType>
listType<elemType>::listType(int size)
{
	if (size < 0)
	{
		cout << "The array size must be positive. Creating "
 			 << "an array of size 100. " << endl;

 	   maxSize = 100;
 	}
 	else
 	   maxSize = size;

	length = 0;

	list = new elemType[maxSize];
	assert(list != NULL);
}

template <class elemType>
listType<elemType>::~listType()
{
	delete [] list;
}


	//copy constructor
template <class elemType>
listType<elemType>::listType
                   (const listType<elemType>& otherList)
{
    int j;

    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];  //create the array
    assert(list != NULL);   //terminate if unable to allocate
                            //memory space

    for (j = 0; j < length; j++)  //copy otherList
        list [j] = otherList.list[j];
}//end copy constructor

template <class elemType>
const listType<elemType>& listType<elemType>::operator=
			(const listType<elemType>& otherList)
{
	if (this != &otherList)	//avoid self-assignment
	{				   
	   delete [] list;				   
	   maxSize = otherList.maxSize;		   
       length = otherList.length;			   
	  
       list = new elemType[maxSize];		   
	   assert(list != NULL);			   

       for (int i = 0; i < length; i++)	   
	   	    list[i] = otherList.list[i];	   
	}

    return *this;					   	   
}

#endif
