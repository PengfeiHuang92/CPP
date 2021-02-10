//File:  getMed.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #6
//Date:  3/18/2018
#include <cmath>
using namespace std;
//precondition:there must be at least one value in the array
// arrays are automatically pass by reference
//description: This file contains the getMed function that will return the mediam number of the scores.


// Function: getMed
// Description: This file contains the getMed function that will return the mediam number of the scores.
// Input:  the score list and the number of the socre in the list
// Output: the mediam score
// Preconditions: the score list size must bigger than 0, the count must be the number of the score in the score list
// Postconditions: the mediam score was return after this fuction, it is a float type
float getMed(const int scores[], int count){
  float tmpMediam;
  if ((count)%2 == 0)   //checking the number of the scores is odd number or not
    tmpMediam = static_cast<float>((scores[(count+1)/2] +scores[(count-1)/2]))/2;
  else
    tmpMediam = static_cast<float>(scores[count/2]);
  return tmpMediam;
  
}