//File:  getGrade.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #5
//Date:  2/25/2018
#include "constants.h"
using namespace std;


// Function: getGrade
// Description: This file contains the getGrade function that will return the test grade based on the testPercentage.
//returen the score grade 
// Input:  the percentage of the score and the maximum score in the list
// Output: the grade of the score
// Preconditions: the testPercentage must be a float type and it is smaler than 100 and greater than 0, the maximum musst be the biggest score 
// in the score list
// Postconditions: the grade was return from this function, that is a char type
char getGrade(float testPercentage, int maximum){
  char tmpGrade; //the grade of the test
  if(testPercentage >= A_min) //if testPercentage > 90
    tmpGrade = 'A';
  else if(testPercentage >= B_min) //if testPercentage > 80
    tmpGrade = 'B';
  else if(testPercentage >= C_min) //if testPercentage > 70
    tmpGrade = 'C';
  else if(testPercentage >= D_min)  //if testPercentage > or =60
    tmpGrade = 'D';
  else
    tmpGrade = 'F'; //if testPercentage < 60
  
  return tmpGrade;
  
}
