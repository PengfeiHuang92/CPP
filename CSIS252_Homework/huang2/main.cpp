//name: Pengfei Huang
//class: CSIS252
//Data: 01/25/2017
//Program #2

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//Description: This program get the Month and day from user, also it askes user to type in the hig temperature on the day and after.
// Then, it returns the span of days,
//	            the maximum high temperature both in fahrenheit and Celsius
//                  the minimum high temperature both in fahrenheit and Celsius
//	  	    the maximum low temperature both in fahrenheit and celsius
//		    the minimum low temperature both in fahrenheit and celsius
//   	  	    the average hight temperature both in fahrenheit and celsius
//    		    the average low temperature both in fahreheit and celsius
//This program will be done when user typed in the sentinel(-999) and show the results.

// this function is turn a fahrenheit into Celsius and return it.
int calculaterCelsius(int fahrenheit){
  //using the round function from cmath
  return round((fahrenheit-32)/1.8);
  
}
const int sentinel= -999; //the constant sentinel -999
int main(){
  cout << fixed << showpoint << setprecision(2); // format to 2 decimals
  
  string month;    // String month
  int dayBegin,  //the begining day
      dayEnd,    //the ending day
      highTempF,  //the hight temperature in Fahrenheit was typed
      lowTempF,   //the low temperature in Fahrenheit was typed
      highestHighTempF=0,  //the hightest high temperture in Fahrenheit
      lowestHighTempF=9999999,  //the lowest high temperature in Fahrenheit
      highTempC,  //teh hight temperature in Celsius was typed
      lowTempC,     // the low temperature in Celsius was typed
      highestLowTempF=0, //the highest low temperature in Fahrenheit
      lowestLowTempF=9999999, //the lowest low temperature in Fahrenheit 
      sumHighTempF=0, //the sum of the hight temperature in Fahrenheit
      sumLowTempF=0; //the sum of the low temperature in Fahrenheit
  double  avgHighTempF=0, //the average higt temperature in Fahrenheit
	  avgLowTempF=0;  //the average  low temperature in Fahrenheit
    
      
  // Prompt the user and read the input    
  cout<<"Please enter the Month: ";
  cin>>month;
  cout<<"PLease enter the Day: ";
  cin>>dayBegin;
  //initial the dayEnd with dayBegin
  dayEnd = dayBegin;
  //this while root will stop when user enter  -999
  while (highTempF !=sentinel){
    // ask for the lhigh temperature and give it to highTempF
    cout<<"Enter high temperature on "<<month <<" " << dayEnd<<" :";
    cin>>highTempF;
    //cheching if user wants to finish this program, it will stop when user type the sentinel(-999)
    if(highTempF != sentinel){
      // ask for the low temperature and give it to lowTempF
      cout<<"Enter low temperature on " <<month<<" "<<dayEnd<<" :";
      cin>>lowTempF;
      highTempC = calculaterCelsius(highTempF);
      lowTempC = calculaterCelsius(lowTempF);
      // print out the temperature message
      cout<<"   High: "<< highTempF <<" degrees F, "<< highTempC<< " degrees C"<<endl;
      cout<<"   Low: "<< lowTempF <<" degrees F, "<< lowTempC<< " degrees C"<<endl;
      //checking if the temperature was typed is the hightest high temperature or not
      if (highTempF > highestHighTempF){
	highestHighTempF = highTempF;
      }
      //checking if the temperature was typed is the lowest high temperature or not
      if (highTempF< lowestHighTempF){
	lowestHighTempF = highTempF;
      }
      //checking if the temperature was typed is the hightest low temperature or not
      if (lowTempF > highestLowTempF){
	highestLowTempF=lowTempF;
      }
      //checking if the temperature was typed is the lowest low temperature or not
      if(lowTempF < lowestLowTempF){
	lowestLowTempF= lowTempF;
      }
      //increaing the day by one
      dayEnd= dayEnd+1;
      //adding the hight temperature
      sumHighTempF = sumHighTempF + highTempF;
      //adding the low temperature
      sumLowTempF = sumLowTempF + lowTempF;
    }
    //getting the average hight temperature and average low temperature in Fahreheit
    avgHighTempF = static_cast<double>(sumHighTempF)/(dayEnd-dayBegin);
    avgLowTempF = static_cast<double>(sumLowTempF)/(dayEnd-dayBegin);
  }
  //print out the message
  cout<<"Summary"<<endl;
  cout<<"........................................"<<endl;
  cout<<" The span of days : " <<month<<dayBegin<<"~"<<dayEnd-1<<endl;
  cout<<" The maximum high temperature is : "<< highestHighTempF<<" degrees F, "<< calculaterCelsius(highestHighTempF)<<" degrees C."<<endl;
  cout<<" The minimum high temperature is : "<< lowestHighTempF<<" degrees F, "<< calculaterCelsius(lowestHighTempF)<<" degrees C."<<endl;
  cout<<" The maximum low temperature is : "<< highestLowTempF<<"degrees F, "<< calculaterCelsius(highestLowTempF)<<" degrees C."<<endl;
  cout<<" The minimum low temperature is : "<< lowestLowTempF<<" degrees F, "<< calculaterCelsius(lowestLowTempF)<<" degrees C."<<endl;
  cout<<" The average hight temperature is : "<< avgHighTempF<<" degrees F, "<< static_cast<double>(avgHighTempF-32)/1.8<<" degrees C."<<endl;
  cout<<" The average low temperature is : "<< avgLowTempF<<" degrees F, "<< static_cast<double>(avgLowTempF-32)/1.8<<" degrees C."<<endl;
  
  return 0;
}
