//File:  main.cpp
//Name:  Pengfei Huang
//Class: CSIS 252
//Program: assignment #4
//Date:  2/9/2018

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int arraysize = 30;  // the size of arraysize
const double A_min = 90.0; // minimum pct for an A grade
const double B_min = 80.0; // minimum pct for an B grade
const double C_min = 70.0; // minimum pct for an C grade
const double D_min = 60.0; // minimum pct for an D grade
const int sentinel = -1;  // the sentinel when user wants to quit

// read maxscore and test scores from user
void read(int scores[], int& count, int& maximum){
  int tmpScore;
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

// sort an array of ints descendingly
void sort(int numbers[], int n)
{
   int temp;
   int large;
   for (int i=0; i<n-1; i++)  // put n-1 ints in their correct spot
   {
      large=i;
      for (int j=i+1; j<n; j++)  // loop to find the largest
         if (numbers[j] > numbers[large])
            large=j;
      temp = numbers[i];         // put largeest in proper position
      numbers[i] = numbers[large];
      numbers[large] = temp;
   }
  
}

// get the Score in percentage and return it
float getScore(int testScore, int maximum){
  float percentageScore;
  cout<<fixed<<showpoint<<setprecision(2); //format the output with two decimal places
  percentageScore = static_cast<float>((testScore)*100)/maximum; //get percentage score
  return percentageScore;
}

//returen the score grade 
char getGrade(float testPercentage, int maximum){
  char tmpGrade;
  if(testPercentage > A_min) //if testPercentage > 90
    tmpGrade = 'A';
  else if(testPercentage > B_min) //if testPercentage > 80
    tmpGrade = 'B';
  else if(testPercentage > C_min) //if testPercentage > 70
    tmpGrade = 'C';
  else if(testPercentage > D_min)  //if testPercentage > 60
    tmpGrade = 'D';
  else
    tmpGrade = 'F'; //if testPercentage < 60
  
  return tmpGrade;
  
}

//get the Average score form the tests and return it
float getAvg(const int scores[] , int count){
  float sum =0;
  for (int i =0; i <count; i++){  //to get the sum ot the scores array
    sum += scores[i];
  }
  return sum/count;
}

//get the mediam score from the tests and return it
float getMed(const int scores[], int count){
  float tmpMediam;
  if ((count)%2 == 0)   //checking the number of the scores is odd number or not
    tmpMediam = static_cast<float>((scores[(count+1)/2] +scores[(count-1)/2]))/2;
  else
    tmpMediam = static_cast<float>(scores[count/2]);
  return tmpMediam;
  
}

//get the standard deviation
float getStandardDeviation(const int scores[],int count){
  float tmpSD;
  float tmpSum;
  float tmpAvg = getAvg(scores,count);  //get the ave from getAvg
  for(int i =0; i<count;i++){
    tmpSum += pow(static_cast<float>(scores[i])-tmpAvg,2);
    
  }
  tmpSD = pow(tmpSum/count,0.5);
  return tmpSD;
}


//out pt the score in tabular form
void outputScores(const int scores[], int count, int maximum){
  
  cout<<setw(10)<<"Score"<<setw(15)<<"Percentage"<<setw(10)<<"Grade"<<endl;
  for(int i =0; i<count;i++){
    cout<<setw(10)<<scores[i]
        <<setw(15)<<getScore(scores[i],maximum)
        <<setw(10)<<getGrade(getScore(scores[i],maximum),maximum)<<endl;
  }
  
}


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

int main()
{
   int scores[arraysize];
   int count;
   int maximum;

   read(scores,count,maximum);    
   sort(scores,count);
   outputScores(scores,count,maximum);
   outputSummary(scores,count,maximum);

   return 0;
}
