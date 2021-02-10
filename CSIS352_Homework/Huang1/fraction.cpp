//FIle:  fraction.cpp
//Author: Pengfei Huang

//Description
// This file contains the implementation for a fraction class

#include "fraction.h"
#include <sstream>
#include <fstream>
#include <math.h>

outPutType fraction::format = mixed; //set the format to default

fraction::fraction(){      
    setFractionNumerator(1);  //default value of numerator as 1
    setFractionDenominator(1);     //default value of denominator as 1
}

fraction::fraction(int n, int d = 1 ){  
    setFraction(n,d);
}

fraction::fraction(double num){  
    setFraction(num);
}

void fraction::setFraction(int n,int d){   
    setFractionNumerator(n);
    setFractionDenominator(d);
}

void fraction::setFraction(double num){    
   
    double intpart;  // double modf (double x, double* intpart)
    double remainder; //remainder of the decimal number of num
    int count = 0; //couting how many decimal digits 
    
    remainder= modf(num,&intpart);  
    
    while(intpart!=0.0){  //counting how many decimal numbers
        
        remainder = remainder * 10.0;
        remainder = modf(remainder,&intpart);
        count += 1;
    }
    setFractionNumerator(num * pow(10,count -1 )); // chancing the double to int
    setFractionDenominator(pow(10,count -1 ));// we need to reduce the count by one because we are getting power of 10
    fraction::reduce();
  
}

void fraction::reduce(){    
    int intN = numerator; // numbers of num
    int intD = denominator; // decimal of num
    bool isSimple = false; // default the num has not been simplified

  
    while(!isSimple){  // simplify the fraction
        
        if(intN % 5 == 0 && intD % 5 == 0){ //if intN and intD can be divided by 5
            intN = intN / 5;
            intD = intD / 5;
            
        }else if(intN % 3 ==0 && intD % 3 == 0) { //if intN and intD can be divided by 3
            intN = intN / 3;
            intD = intD / 3;
            
        }else if(intN % 2 ==0 && intD % 2 == 0) { //if intN and intD can be divided by 2
            intN = intN / 2;
            intD = intD / 2;
            
        }else{
            isSimple =true; 
        }
    }
    setFractionNumerator(intN);
    setFractionDenominator(intD);
}

int fraction::getNumerator() const{       
    return numerator;
}

int fraction::getDenominator() const{
    return denominator;
}

double fraction::decimalValue() const{     
    double tmpDecimalValue = 0.0;
    
    tmpDecimalValue = static_cast<double>(getNumerator()) / getDenominator();
    return tmpDecimalValue;
}

void fraction::setDenominator(int d){      
    
    fraction::reduce();

    if(d % getDenominator() == 0  ){
    
    setFractionNumerator(
       getNumerator() * (d / getDenominator()));
    setFractionDenominator(d);
        
    }else{
        cerr<< "error as numerator would have to be "<<getNumerator() * (static_cast<double>(d) / getDenominator())<<endl;
    }
}

void fraction::setFractionNumerator(int n){     
    numerator = n;
}

void fraction::setFractionDenominator(int d){      
     denominator = d;
}

void fraction::outputFormat(outPutType type){    
    format = type;
    
}

outPutType fraction::getOutPutFormat(){    
    return format;
}


//overide the relation operators take a franction as argument
fraction fraction::operator+(const fraction& f) const{     
    fraction tmpF(((getNumerator() * f.getDenominator()) + (getDenominator() * f.getNumerator())),(getDenominator() * f.getDenominator()) );
    tmpF.reduce();
    return tmpF;
}
fraction fraction::operator-(const fraction& f) const{
    fraction tmpF(((getNumerator() * f.getDenominator()) - (getDenominator() * f.getNumerator())),(getDenominator() * f.getDenominator()) );
    tmpF.reduce();
    return tmpF;
}
fraction fraction::operator*(const fraction& f) const{
    fraction tmpF(getNumerator() * f.getNumerator(), getDenominator() * f.getDenominator());
    tmpF.reduce();
    return tmpF;
}
fraction fraction::operator/(const fraction& f) const{
    fraction tmpF(getNumerator() * f.getDenominator(), getDenominator() * f.getNumerator());
    tmpF.reduce();
    return tmpF;
}

const fraction& fraction::operator=(const fraction& f){ 
    setFractionNumerator(f.getNumerator());
    setFractionDenominator(f.getDenominator());
    fraction::reduce();
    return *this;
}

bool fraction::operator==(const fraction& f)const{     
 
    return getDenominator()*f.getNumerator() == getNumerator()*f.getDenominator();
}

bool fraction::operator!=(const fraction& f) const{
    
    return !(*this==f);
}

bool fraction::operator>(const fraction& f) const{
    
    return (getNumerator()*f.getDenominator() > getDenominator()*f.getNumerator());
        
}

bool fraction::operator>=(const fraction& f) const{
    
    return (*this == f || *this > f );
        
}

bool fraction::operator<(const fraction& f) const{
    
    return !(*this >= f);
}

bool fraction::operator<=(const fraction& f) const{
    return !(*this > f);
}

//overide the relation operators take double
const fraction& fraction::operator=(double num){     
    setFraction(num);
    return *this;
}

bool fraction::operator==(double num){
    fraction tmpF;
    tmpF.setFraction(num);
    return (*this == tmpF);
}

bool fraction::operator!=(double num){
    fraction tmpF;
    tmpF.setFraction(num);
    return (*this != tmpF);
}

bool fraction::operator>(double num){
    fraction tmpF;
    tmpF.setFraction(num);
    return (*this > tmpF);
}

bool fraction::operator>=(double num){
    fraction tmpF;
    tmpF.setFraction(num);
    return (*this >= tmpF);
}

bool fraction::operator<(double num){
    fraction tmpF;
    tmpF.setFraction(num);
    return (*this < tmpF);
}

bool fraction::operator<=(double num){
    fraction tmpF;
    tmpF.setFraction(num);
    return (*this <= tmpF);
}

istream& operator>>(istream& i, fraction& f){   
    int tmpN;  //numerator from user
    int tmpD;  //denominator
    char slash;  // extra char
   
    i >> tmpN >> slash >> tmpD;
 
    f.setFractionNumerator(tmpN);
    f.setFractionDenominator(tmpD);
    
    return i;
} 

ostream& operator<<(ostream& o , const fraction& f){      
    stringstream output;
    switch(fraction::getOutPutFormat()){  //checking for outputFormat 
        case mixed: 
            int tmpInt; //getting the integet of the fraction
            tmpInt  =  f.getNumerator() / f.getDenominator() ;
            if(tmpInt){
                if(f.getNumerator() == tmpInt * f.getDenominator()){
                     output <<tmpInt; 
                     break;
                }else{
            output <<tmpInt<<" "<< abs(f.getNumerator() - tmpInt * f.getDenominator())<< "/" << f.getDenominator(); 
            break;}
            }else{
                output << f.getNumerator()<< "/" << f.getDenominator(); 
                break;
            }
        case improper:
            output << f.getNumerator()<< "/" << f.getDenominator();       
            break;
        case decimal: 
            output << static_cast<double>(f.getNumerator()) / f.getDenominator(); break;
        
    }
    o<<output.str();  //formating the output using sstream
    return o;
}
