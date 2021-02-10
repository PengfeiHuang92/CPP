//File:  outputSummary.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #6
//Date:  3/18/2018
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Function: outputSummary
// Description: This file contains the outputSummary function that will create a testsummary file which contains all the summary from the scores array
// Input:  a score array, a count of the score array and the maximum score from the score array
// Output: this function creat a file called testsummary
// Preconditions: there must be at least one value in the array
// Postconditions: the Maximum cores, the number of students, the highest score, lowest score , score range, Average score, median score and standard deviation was written into the //testsummary file
float getAvg(const int scores[] , int count);
float getMed(const int scores[], int count);
float getStandardDeviation(const int scores[],int count);
void outputSummary(const int scores[],int count, int maximum){
  ofstream outfile;
  outfile.open("testsummary");
  outfile<<fixed<<showpoint<<setprecision(2); //format the output with two decimal places
  outfile<<setw(20)<<left<<"Maximum Score: "<<setw(10)<<right<<maximum<<endl;
  outfile<<setw(20)<<left<<"Number of students: "<<setw(10)<<right<<count<<endl;
  outfile<<setw(20)<<left<<"High score: "<<setw(10)<<right<<scores[0]<<endl;
  outfile<<setw(20)<<left<<"Low Score: "<<setw(10)<<right<<scores[count-1]<<endl;
  outfile<<setw(20)<<left<<"Range of scores: "<<setw(10)<<right<<scores[0]-scores[count-1]<<endl;
  outfile<<setw(20)<<left<<"Average Score: "<<setw(10)<<right<<getAvg(scores,count)<<endl;
  outfile<<setw(20)<<left<<"Median Score: "<<setw(10)<<right<<getMed(scores,count)<<endl; 
  outfile<<setw(20)<<left<<"Standard Deviation:"<<setw(10)<<right<<getStandardDeviation(scores,count)<<endl;
}