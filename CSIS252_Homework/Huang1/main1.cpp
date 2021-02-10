//file: main1.cpp
//name: Pengfei Huang
//class: CSIS252
//program: #1
//Date: 1/15/2018

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Program Description: 
//This program is asking user to input the number of Kilometers (floating point) a car travelled and the number of Liters (floating point) of gasoline used, then outputs MPG (Miles per Gallon) as a floating point.
int main(){
// Variables
 float kilometers, // the number of Kilometers  a car travelled
       miles, //the number of miles  a car travelled
       liters, // the number of Liters  of gasoline used
       gallon, // the number of gallon of gasoline used
       MPG;  // Miles per Gallon
 bool valid = false;
// Prompt the user and read the input  
  while(!valid){               //getting the number of Kilometers
    cout << "input the number of Kilometers: ";
    cin >> kilometers;
    valid = true;
    if(cin.fail()){
      
      cin.clear();
      cin.ignore();
      cout << "input a number only "<<endl;
      valid = false;
    }
    
  }
  
  
  valid = false;
  while(!valid){                //getting the number of Liters of gasoline
    cout << "input the number of Liters of gasoline: ";
    cin >> liters;
    valid = true;
    if(cin.fail()){
      
      cin.clear();
      cin.ignore();
      cout << "input a number only "<<endl;
      valid = false;
    }
    
  }  
  

  miles = kilometers*0.621371; //change kilometers into miles
  gallon = liters *0.264172; //change liters into gallon
  MPG = miles/gallon;
// report the numbers with two decimal places 
  cout << fixed << showpoint << setprecision(2);
  cout << "the number of the kilometers is " << kilometers << "km which equals to "<< miles <<" miles."<<endl;
  cout << "the number of the Listers of gasoline is " << liters << "Listers."<< "listers which equals to "<< gallon <<" gallon."<<endl;
  cout<<"the Mile per Gallon is "<<MPG<<"Km/G"<<endl;
}