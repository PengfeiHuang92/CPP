//file: main4.cpp
//name: Pengfei Huang
//class: CSIS252
//Program: #1
//Date: 1/15/2018


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//Progrem Description: inputs the length of sides A and B of a right triangle (both floating points)
//then outputs the floating point length of the hypotenuse.

//this function returns a float number only
float getInput(string message){
    float tmpFloat;
    bool valid = false;
    while(!valid){
	cout<<message;
	cin>>tmpFloat;
	valid = true;
	if(cin.fail()){
	  cin.clear();
	  cin.ignore();
	  valid=false;
	  
	}
      
    }
    return tmpFloat;
}
int main(){
  cout<<fixed<<showpoint<<setprecision(2);
  float lengthA,//the length of A side
	lengthB,//the length of B side
	lengthC;//the length of C side
	
  lengthA = getInput("Enter the length of A side: ");
  lengthB = getInput("Enter the length of B side: ");
  lengthC = pow(pow(lengthA,2)+pow(lengthB,2),0.5);
  cout<<"The length of C side is "<<lengthC<<endl;
  
}