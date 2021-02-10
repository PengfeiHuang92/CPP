//File:  main.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #3
//Date:  1/31/2018

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Program DEscription:
// Array processing. Get the numbers from user. calculate the numbers and return it.

const int sentinel = 0;  // set the sentinel 0
const int arraySize = 20; // set the constant array size 20

int main(){
  int numbersArray[arraySize]; //the array contain the input from the keyboardd
  int positiveArray[arraySize];// the array contain all the positive numbers input from the keyboard
  int negativeArray[arraySize];// the array contain all the negative numbers input from the keyboard
  int evenArray[arraySize];  // the array contain all the even numbers from positiveArray
  int oddArray[arraySize];  // the array contain all the odd numbers from positiveArray
  int absArray[arraySize]; // the absArray contain all the absolute number fron negativeArray
  int pCount=0;   //the counter of positiveArray
  int nCount=0;   //the counter of negativeArray
  int evenCount=0;  //counter for evenArray
  int oddCount=0; // counter for oddArray
  int evenSum = 0; // the sum of the evenArray
  int oddSum = 0; //the sum of the oddArray
  double avgEven=0.00; // the average of the even positive numbers in the positiveArray
  double avgOdd=0.00; // the average of the odd positive numbers in the positiveArray
  int num;  //the single number from the keyboard
  int count=0; //the counter for the array
  cout << fixed << showpoint << setprecision(2); //formating the output with two decimal places
  //Prompt the user and read the input
  cout<<"Enter the numbers: ";
  cin>>num;
  while (num != sentinel && count <= arraySize){  //when the input is 0 or the array's size greater than 20, it stops go inside of the while loop
    numbersArray[count] = num;
    count++;
    cin>>num;
  }


// 1
  //putting the numbers into positiveArray and negativeArray
  for(int i = 0; i < count; i++){
    if(numbersArray[i] >0){
      positiveArray[pCount] = numbersArray[i];
      pCount++;
    }else if(numbersArray[i] < 0){
      negativeArray[nCount] = numbersArray[i];      
      nCount++;
    }
  }
// 2
  //print out the negativeArray
  cerr<<"The negative array is:   ";
  for(int i =0; i < nCount;i++){
    cout<<negativeArray[i]<<" ";
  }
  cout<<endl;

// 3
  int tmpNumber;
  int absCount=nCount-1; 
  //get the absArray from negatuveArray
  for(int i =0; i < nCount;i++){
    tmpNumber = abs(negativeArray[i]); //change the number to absolute value 
    absArray[absCount]=tmpNumber;
    absCount--;
  }
  //print out the absArray
  cout<<"Absolute value of negative array in the reverse order:   ";
  for(int i =0; i < nCount; i++){
    cout<<absArray[i]<<" ";
  }
  cout<<endl;

//4
  //get the evenArray and oddArray
  for(int i =0; i < pCount; i++){
    if(positiveArray[i]%2 ==0){
      evenArray[evenCount] = positiveArray[i];
      evenCount++;
    }else{
      oddArray[oddCount] = positiveArray[i];
      oddCount++;      
    }
  }
  //print evenArray and oddArray
  cout<<"The even positive ints:  ";
  for(int i =0; i < evenCount; i++){
    cout<<evenArray[i]<<" ";
  }
  cout<<endl;
  
  cout<<"The odd positive ints:  ";
  for(int i =0; i < oddCount; i++){
    cout<<oddArray[i]<<" ";
  }
  cout<<endl;

// 5
  //get the sum of the even number from evenArray
  for(int i = 0 ; i < evenCount; i++){
    evenSum += evenArray[i];
  }
  // get the average from evenArray
  avgEven = static_cast<double>(evenSum)/evenCount;
  cout<<"The avg of the even positive array is : "<< avgEven<<endl;
  
// 6   
  //get the sum of the odd number from oddArray
  for(int i = 0 ; i < oddCount; i++){
    oddSum += oddArray[i];
  }
  
  //get the average from oddArray
  avgOdd =static_cast<double>(oddSum)/oddCount;
  cout<<"The avg of the odd positive array is : "<< avgOdd<<endl;

// 7
  
  int tmpEvenPosition; //the position will be return
  int tmpEvenNumber; // the number which is the first number in the even positive array that is less than or equal to the average of the even positive array
  for(int i =0; i < evenCount ; i++){
    if(evenArray[i]<= avgEven){
      tmpEvenNumber = evenArray[i];
      tmpEvenPosition = i;
      i += evenCount; // get out of the for loop
    }
  }
  cout<<tmpEvenNumber<< " is the first number (Staring at the begining) in the even positive array that is less than or equal to the average of the even positive array. "<<endl;
  cout<<"The position of " << tmpEvenNumber <<" is: "<<tmpEvenPosition<<endl;

// 8
  int tmpOddPosition; //the position will be return
  int tmpOddNumber; //the first number (Staring at the end) in the odd positive array that is less than or equal to the average of the odd positive array.
  for(int i =oddCount-1; i >=0 ; i--){
    if(oddArray[i]<= avgOdd){
      tmpOddNumber = oddArray[i];
      tmpOddPosition = i;
      i -=oddCount;   // get out of the for loop
    }
  }
  cout<<tmpOddNumber<< " is the first number (Staring at the end) in the odd positive array that is less than or equal to the average of the odd positive array. "<<endl;
  cout<<"The position of " << tmpOddNumber <<" is: "<<tmpOddPosition<<endl;
  return 0;
}
