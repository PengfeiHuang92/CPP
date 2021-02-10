//file: main3.cpp
//name: Pengfei Huang
//class: CSIS252
//program: #1
//Date: 1/15/2018

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Program Description:
//inputs the length of all three sides of a triangle (floating points)
//then outputs the area of the triangle (floating point).

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
  float lengthOne, //the length of the triangle
	lengthTwo, //the length of the triangle
	lengthThree, //the length of the triangle
	p, // the p value
	num,
	area; //the area of the triangle
  
  lengthOne = getInput("Enter the first lenth of the triangle");
  lengthTwo = getInput("Enter the second lenth of the triangle");
  lengthThree = getInput("Enter the third lenth of the triangle");
  p = (lengthOne + lengthTwo + lengthThree)/2;
  num = p*(p-lengthOne)*(p-lengthTwo)*(p-lengthThree);
  area = pow(num,0.5);
  
//report the outputs
  cout<<fixed<<showpoint<<setprecision(2);
  cout << "The area is "<<area<<"."<<endl;
}