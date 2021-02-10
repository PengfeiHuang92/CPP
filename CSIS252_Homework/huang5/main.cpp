//File:  main.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #5
//Date:  2/25/2018

#include <iostream>
#include <iomanip>
#include <cmath>
#include "constants.h"
using namespace std;

/***description: getting scores from user and return the summary.
maximum score
the number of students processed
high score
low score
range of scores (high score minus low score)
average score
median score
standard deviation of scores (since we have all the scores, use the population standard deviation)
***/
//functions
void read(int scores[], int& count, int& maximum);
void sort(int numbers[], int n);
float getScore(int testScore, int maximum);
char getGrade(float testPercentage, int maximum);
float getAvg(const int scores[] , int count);
float getMed(const int scores[], int count);
float getStandardDeviation(const int scores[],int count);
void outputScores(const int scores[], int count, int maximum);
void outputSummary(const int scores[],int count, int maximum);

// Function: main
// Description: the main function of the program that calls other functions
// Input:  <none>
// Output: <none>
// Preconditions: <none> 
// Postconditions: <none>
int main()
{
   int scores[arraysize]; //the list of the scores
   int count; // the number of the score
   int maximum; // the maximum of the score

   read(scores,count,maximum);
   sort(scores,count);
   outputScores(scores,count,maximum);
   outputSummary(scores,count,maximum);

   return 0;
}













