//File:  outputScores.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #6
//Date:  3/18/2018
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Function: outputScores
// Description: This file contains the outputScores function that will put the name, the score , the Percentage score and test grade of the score
//into a file which is testresults.
// Input:  a score array, a count of the score array, a name array, a count of the names array and the maximum score from the score array.
// Output: this function create a testresults file
// Preconditions: there must be at least one value in the score and names array
// Postconditions: the names, the scores, the percentage of score and the grade was written at the testresults file
char getGrade(float testPercentage, int maximum);
float getScore(int testScore, int maximum);
//out pt the score in tabular form
void outputScores(const int scores[], int scount, const string names[], int ncount,int maximum){
  
  ofstream outfile;
  outfile.open("testresults");
  outfile<<fixed<<showpoint<<setprecision(2); //format the output with two decimal places
  outfile<<setw(26)<<left<<"Name"<<setw(12)<<"Score"<<setw(13)<<"Pct"<<setw(10)<<"Grade"<<endl;
  outfile<<setw(26)<<left<<"------------------------  "<<setw(10)<<"-----"<<setw(15)<<"------"<<setw(10)<<"-----"<<endl;
  for(int i =0; i<scount;i++){
    outfile<<setw(26)<<left<<names[i]
	   <<setw(4)<<right<<scores[i]
	   <<setw(12)<<getScore(scores[i],maximum)
	   <<setw(12)<<getGrade(getScore(scores[i],maximum),maximum)<<endl;
  }
  
}