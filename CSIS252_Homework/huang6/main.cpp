//File:  main.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #6
//Date:  3/18/2018

#include <iostream>
#include <iomanip>
#include <string>
#include "constants.h"
using namespace std;

//functions
void read(int scores[], int& scount, string names[], int& ncount,int& maximum);
void sort(int numbers[], string names[], int n );
float getScore(int testScore, int maximum);
char getGrade(float testPercentage, int maximum);
float getAvg(const int scores[] , int count);
float getMed(const int scores[], int count);
float getStandardDeviation(const int scores[],int count);
void outputScores(const int scores[], int scount, const string names[], int ncount,int maximum);
void outputSummary(const int scores[],int count, int maximum);


// Function: main
 /***d Description:escription: getting scores from user and return the summary.
maximum score
the number of students processed
high score
low score
range of scores (high score minus low score)
average score
median score
standard deviation of scores (since we have all the scores, use the population standard deviation)
***/
// Input:  <none>
// Output: <none>
// Preconditions: <none> 
// Postconditions: <none>
int main()
{
   int scores[arraysize]; //the list of the scores
   string names[arraysize]; //the list of the names
   int scount=0; // the number of the test score in the scores array
   int ncount=0; // the number of the name in the names array
   int maximum; // the maximum of the score

   read(scores,scount,names,ncount,maximum);
   sort(scores,names,scount);
   outputScores(scores,scount,names,ncount,maximum);
   outputSummary(scores,scount,maximum);

   return 0;
}













