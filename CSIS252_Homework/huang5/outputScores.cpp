//File:  outputScores.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #5
//Date:  2/25/2018
#include <iostream>
#include <iomanip>
using namespace std;

// Function: outputScores
// Description: This file contains the outputScores function that will output the score , the Percentage score and test grade of the score.
// Input:  a score list, a count of the score list and the maximum score from the score list.
// Output: <none>
// Preconditions: there must be at least one value in the array
// Postconditions: the scores, the percentage of score and the grade was showed in the screen
char getGrade(float testPercentage, int maximum);
float getScore(int testScore, int maximum);
//out pt the score in tabular form
void outputScores(const int scores[], int count, int maximum){
  
  cout<<setw(10)<<"Score"<<setw(15)<<"Percentage"<<setw(10)<<"Grade"<<endl;
  for(int i =0; i<count;i++){
    cout<<setw(10)<<scores[i]
        <<setw(15)<<getScore(scores[i],maximum)
        <<setw(10)<<getGrade(getScore(scores[i],maximum),maximum)<<endl;
  }
  
}