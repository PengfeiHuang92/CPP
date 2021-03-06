//File:  getStandardDeviation.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #6
//Date:  3/18/2018
#include <cmath>
using namespace std;

// Function: getStandardDeviation
// Description: this file contains the getStandardDeviation function that will return the standard deviation of the score array.
// Input:  the score array and the number of the socre in the array
// Output: the standard deviation base on the score array
// Preconditions: the array must be contains at leat one score, getAvg return the correct number
// Postconditions: the standard deviation was return after this fuction, it is a float type.
float getAvg(const int scores[] , int count);
float getStandardDeviation(const int scores[],int count){
  float tmpSD; //the standard deviation 
  float tmpSum; // the sum of the score list
  float tmpAvg = getAvg(scores,count);  //get the ave from getAvg
  for(int i =0; i<count;i++){
    tmpSum += pow(static_cast<float>(scores[i])-tmpAvg,2);
    
  }
  tmpSD = pow(tmpSum/count,0.5);
  return tmpSD;
}
