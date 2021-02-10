//File:  getAvg.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #5
//Date:  2/25/2018
using namespace std;

// Function: getAvg
// Description: this file contains the getAvg function that will return the Average of the scores.
// Input:  the list of the scores, the number of the scores
// Output: the average of the score list.
// Preconditions: there must be at least one value in the array and count must be the number of the score in the score list
// Postconditions: the average of the scores was retured 
//from this function

float getAvg(const int scores[] , int count){
  float sum =0; //the sum of all the scores
  for (int i =0; i <count; i++){  //to get the sum ot the scores array
    sum += scores[i];
  }
  return sum/count;
}