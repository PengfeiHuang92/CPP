//File:  sort.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #5
//Date:  2/25/2018

// Function: sort
// Description: Tsort an array of ints descendingly
// Input:  a int list and the number of the numbers in the list
// Output: <none>
// Preconditions: number must contain at leat one value, the n must be greater than 0
// Postconditions: sort an array of ints descendingly
void sort(int numbers[], int n)
{
   int temp; //the temporary number
   int large;// the large number
   for (int i=0; i<n-1; i++)  // put n-1 ints in their correct spot
   {
      large=i;
      for (int j=i+1; j<n; j++)  // loop to find the largest
         if (numbers[j] > numbers[large])
            large=j;
      temp = numbers[i];         // put largeest in proper position
      numbers[i] = numbers[large];
      numbers[large] = temp;
   }
  
}