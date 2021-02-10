//file: main2.cpp
//name: Pengfei Huang
//class: CSIS252
//program: #1
//Date: 1/15/2018

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Program Description:
//inputs the radius (floating point) of a circle 
//then outputs floating point results for the diameter,
//circumference, and area of the circle. Declare and use a constant for pi.

//this function returns a float number only
float getInPut(string message){
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
  
//variables
  float radius, //the radius of a circle
	diameter, //the diameter of a cirecle
	circumference,//the circumference of a cirecle
	area;// area of the circle
  const float pi=3.141592;
// Prompt the user and read the input  
  radius = getInPut("Enter the radius : ");
  diameter = radius *2 ;
  circumference = 2* pi* radius;
  area = pi*radius*radius;
  cout<<fixed<<showpoint<<setprecision(2);
  cout<<"the Radius is : "<<radius<<endl;
  cout<<"the Diameter is :"<<diameter<<endl;
  cout<<"the circumference is : "<<circumference<<endl;
  cout<<"the Area is : "<<area<<endl;
  
}