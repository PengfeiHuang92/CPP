//File:  getScore.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #6
//Date:  3/18/2018
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function: getScore
// Description: TThis file contains the getScore function that will return the test score in percentage.
// Input:  a test score and the maximum score
// Output:  percentage score base on the maximum
// Preconditions: testScore must not be greater than maximum score
// Postconditions: the mediam score was return after this fuction, it is a float type.
float getScore(int testScore, int maximum){
  float percentageScore; //the percentage relate to the test score 
  percentageScore = static_cast<float>(testScore)*100/maximum; //get percentage score
  return percentageScore;
}