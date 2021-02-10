//file: main5.cpp
//name: Pengfei Huang
//class: CSIS252
//Program: #1
//Date: 1/15/2018
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Program Description: inputs loan amount (floating point), APR - Annual Percentage Rate (floating point), and term of the loan in months (int). Note: the APR is entered as a percent. //For example 9.5% would be entered as 9.5 not as 0.095. Output is floating point values for the monthly payment, total amount paid over the life of the loan, and total interest paid //over the life of the loan. The calculation is for a standard loan amortized for a specific period of time with a fixed rate.


int main(){
  //variables
  float amount,//loan amount
	APR,//Annual Percentage Rate
	paymentMonth,// the monthly payment
	paymentTotal,//the total amount paid over the life of the loan
	interestPaid;//the total interest paid over the life of the loan
	
  int	term;//the term of the loan in months
  //Prompt the user and read the input  
  cout<<"Enter the Amount : ";
  cin>>amount;
  cout<<"Enter the APR- Annual Percentage Rate : ";
  cin>>APR;
  cout<<"Enter the term of the loan in months : ";
  cin>>term;
  paymentMonth = amount*(APR/1200 + APR/1200/(pow((1+APR/1200),term)-1));
  paymentTotal = paymentMonth*term;
  interestPaid = paymentTotal-amount;
  
  cout<< "paymentMonth: "<<paymentMonth<<endl;
  cout<< "paymentTotal: "<<paymentTotal<<endl;
  cout<<"interestPaid: "<<interestPaid<<endl;
  
  
  
}