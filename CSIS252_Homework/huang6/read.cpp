//File:  read.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #6
//Date:  3/18/2018
//precondition: scores must have no value on it. the test score must be less than the maximum.
// read maxscore and test scores from user
//description: This file contains the read function that will create a array call scores and get the test score from the user..
#include <fstream>
#include <iostream>
using namespace std;
#include "constants.h"
#include <string>

// Function: read
// Description: This function read the data from testscores file and store the data into scores and names array
// Input:  a score array, a count of the score array , a names array, a count of the names array and the maximum score from the score array
// Output: scores and names array, scount and ncount and the maimum score
// Preconditions: there must not have any data in scores and names array and the scount and ncount start at 0
// Postconditions: this function that reading the data from the file and store it into scores and names array
void read(int scores[], int& scount, string names[], int& ncount,int& maximum){
    ifstream infile;
    infile.open("testscores");
    infile>>maximum;
    infile.ignore(80,'\n');
    string name;
    
    getline(infile,name);
    while(!infile.eof() && scount< arraysize  && ncount < arraysize){
      names[ncount]= name;
      infile>>scores[scount];
      ncount++;
      scount++;
      infile.ignore(80,'\n');
      getline(infile,name);
    }
    

}