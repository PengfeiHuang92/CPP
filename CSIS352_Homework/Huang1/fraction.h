// File:    fraction.h
// Author:  Pengfei Huang

//Description:
//This file contains the specification for a fraction class

#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
using namespace std;

enum outPutType {mixed,improper,decimal};
class fraction
{
  public:
        // method - constructor
        // description - construct a new fraction object
        // preconditions - none
        // postconditions - fraction object created and initialize it to 1
        // method input - none
        // method output - none
        fraction();        
        
        // method - constructor
        // description - construct a new fraction object 
        // preconditions - denominator can not be 0
        // postconditions - fraction object created 
        // method input - numerator of the fraction: int ,  denominator of the fraction: int
        // method output - none
        fraction(int, int);         
        
        // method - constructor
        // description - construct a new fraction object 
        // preconditions - none
        // postconditions - fraction object created 
        // method input - decimal number of fraction: double
        // method output - none
        fraction(double);           
        
        // method - setFraction
        // description - to create a fraction object
        // preconditions - denominator can not be 0
        // postconditions - fraction object created 
        // method input - numerator of the fraction: int ,  denominator of the fraction: int
        // method output - none
        void setFraction(int,int);     
        
        // method - setFraction
        // description - to create a fraction object
        // preconditions - none
        // postconditions - fraction object created
        // method input - decail number of fraction: double
        // method output - none
        void setFraction(double);      
        
        // method - reduce
        // description - to simplyfy the fraction
        // preconditions - a fraction object has been initialized
        // postconditions - the fraction has been simplyfied
        // method input - none
        // method output - none
        void reduce();          
        
        // method - getNumerator
        // description - return the numerator of the fraction
        // preconditions - a fraction object has been initialized
        // postconditions - the numerator of the fraction has been returned
        // method input - none
        // method output - the numerator of the fraction
        int getNumerator() const;    
        
        // method - getDenominator
        // description - return the numerator of the fraction
        // preconditions - a fraction object has been initialized
        // postconditions - the denominator of the fraction has been returned
        // method input - none
        // method output - the denominator of the fraction
        int getDenominator() const;        
        
        // method - decimalValue
        // description - return the fraction with double value
        // preconditions - a fraction object has been initialized
        // postconditions - a decimal value of the fraction has been returned
        // method input - none
        // method output - none
        double decimalValue() const;       
        
        // method - setDenominator
        // description - set the fraction denominator as the argument
        // preconditions - a fraction object has been initialized and the fraction can not be set as 0
        // postconditions - changing the denominator of the fraction object
        // method input - new denominator of the fraction: int
        // method output - none
        void setDenominator(int);   
        
        // method - setFractionNumerator
        // description - to set the fraction's numerator as the argument
        // preconditions - a fraction object has been initialized
        // postconditions - changing the numerator of the fraction object
        // method input - new numerator of the fraction: int
        // method output - none
        void setFractionNumerator(int);  

        // method - setFractionDenominator
        // description - to set the fraction's denominator as the argument
        // preconditions - a fraction object has been initialized
        // postconditions - changing the denominator of the fraction object
        // method input - new denominator of the fraction: int
        // method output - none        
        void setFractionDenominator(int);          
        
        // method - outputFormat
        // description - changing the outputFormat to the argument 
        // preconditions - a fraction object has been initialized
        // postconditions - the outputFormat of the fraction has been changed
        // method input - out put type of fraction: outPutType
        // method output - none  
        static void outputFormat(outPutType);      
        
        // method - getOutPutFormat
        // description - gettting the outPutType of the fraction
        // preconditions - a fraction object has been initialized
        // postconditions - the outputFormat of the fraction has been returned
        // method input - none
        // method output - the outPutType of the fraction: outPutType  
        static outPutType getOutPutFormat();      
        
        //override those relational operators take fraction as argument
        fraction operator+(const fraction&) const;     
        fraction operator-(const fraction&) const;
        fraction operator*(const fraction&) const;
        fraction operator/(const fraction&) const;
        const fraction& operator=(const fraction&);
        bool operator==(const fraction&) const;
        bool operator!=(const fraction&) const;
        bool operator>(const fraction&) const;
        bool operator>=(const fraction&) const;
        bool operator<(const fraction&) const;
        bool operator<=(const fraction&) const;
        
        //override thoserelational operators take a double as argument
        const fraction& operator=(double);
        bool operator==(double);
        bool operator!=(double);
        bool operator>(double);
        bool operator>=(double);
        bool operator<(double);
        bool operator<=(double);

  private:
        int numerator;     //numerator of the fraction
        int denominator; 		//denominator of the fraction 
        static outPutType format;      //format of the fraction
};

        // method - operator<<
        // description - output the fraction with the right format
        // preconditions - a fraction object has been initialized
        // postconditions - a fraction object has been outputed
        // method input - ostream and fraction
        // method output - ostream  
	ostream& operator<<(ostream&,const fraction&);   
	// method - operator>>
        // description - read the fraction form keyborad
        // preconditions - the input should looke like numerator / denoninator
        // postconditions - a fraction object has been read
        // method input - istream and fraction object
        // method output - istream  
	istream& operator>>(istream&,fraction&);    

#endif
