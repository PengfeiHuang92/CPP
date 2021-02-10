//File:  outputSummary.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #5
//Date:  2/25/2018
#include <iostream>
#include <iomanip>
using namespace std;

// Function: outputSummary
// Description: This file contains the outputSummary function that will out put the scores in the format.
// Input:  a score list, a count of the score list and the maximum score from the score list.
// Output: <none>
// Preconditions: there must be at least one value in the array
// Postconditions: the sMaximum cores, the number of students, the highest score, lowest score , score range, Average score, median score and standard deviation was showed in the //screen
float getAvg(const int scores[] , int count);
float getMed(const int scores[], int count);
float getStandardDeviation(const int scores[],int count);
void outputSummary(const int scores[],int count, int maximum){
  cout<<"Summary..........."<<endl;
  cout<<setw(20)<<left<<"Maximum Score: "<<setw(10)<<right<<maximum<<endl;
  cout<<setw(20)<<left<<"Number of students: "<<setw(10)<<right<<count<<endl;
  cout<<setw(20)<<left<<"High score: "<<setw(10)<<right<<scores[0]<<endl;
  cout<<setw(20)<<left<<"Low Score: "<<setw(10)<<right<<scores[count-1]<<endl;
  cout<<setw(20)<<left<<"Range of scores: "<<setw(10)<<right<<scores[0]-scores[count-1]<<endl;
  cout<<setw(20)<<left<<"Average Score: "<<setw(10)<<right<<getAvg(scores,count)<<endl;
  cout<<setw(20)<<left<<"Median Score: "<<setw(10)<<right<<getMed(scores,count)<<endl; 
  cout<<setw(20)<<left<<"Standard Deviation:"<<setw(10)<<right<<getStandardDeviation(scores,count)<<endl;
}