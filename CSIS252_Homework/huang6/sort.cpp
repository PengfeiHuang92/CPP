//File:  sort.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #6
//Date:  3/18/2018
// Function: sort
// Description: sort an array of ints descendingly and also change the order of the name array
// Input:  a int scores array, a string names array and the number of the numbers in the list
// Output: the scores array and names array
// Preconditions: number and names must contain at leat one value, the n must be greater than 0
// Postconditions: sort the numbers array by descendingly and change the order of the  names array at the same time

#include <string>
using namespace std;
void sort(int numbers[], string names[], int n )
{
   int temp; //the temporary number
   int large;// the large number
   string tmps; //the temporary name string
   for (int i=0; i<n-1; i++)  // put n-1 ints in their correct spot
   {
      large=i;
      for (int j=i+1; j<n; j++)  // loop to find the largest
         if (numbers[j] > numbers[large])
            large=j;
      temp = numbers[i];         // put largeest in proper position
      numbers[i] = numbers[large];
      numbers[large] = temp;
   
      tmps = names[i];         // put the name with largeest in proper position
      names[i] = names[large];
      names[large] = tmps;

     
  }
  
}