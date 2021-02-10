//File:  read.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #5
//Date:  2/25/2018
//precondition: scores must have no value on it. the test score must be less than the maximum.
// read maxscore and test scores from user
//description: This file contains the read function that will create a array call scores and get the test score from the user..

#include <iostream>
using namespace std;
#include "constants.h"

// Function: read
// Description: This file contains the read function that will create a array call scores and get the test score from the user
// It will stop read until the user type the sentinel value
// Input:  a score list, a count of the score list and the maximum score from the score list. all the peramaters pass by reference
// Output: <none>
// Preconditions: test scores must have no value on it. count must start from 0 and the maximum score must be a int
// Postconditions: The array will be populated with the values entered
//                 from the keyboard and the count will contain the number 
//                 of values in the array. 
void read(int scores[], int& count, int& maximum){
  int tmpScore; //the score user type in 
  count=0;
  cout<<"Enter the maximum score: ";  //get maximum from user
  cin>>maximum;
  cout<<"Enter the test scores end it with -1: ";  //get the test scores from user
  cin>>tmpScore;
  while(tmpScore != sentinel && count<= arraysize){   //put the test scores into the scores array
    scores[count]=tmpScore;
    count++;
    cin>>tmpScore;
  }

}