// File:    date.h
// Author:  Pengfei Huang

//Description:
//This file contains the specification for a Date and DateException
#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace DateNameSpace{

	enum format {LittleEndian,MiddleEndian,BigEndian,   // order of the date
		   Slash,Dash,Space,    //delimeter for a numeric date
		   Text,Numeric,    //month formatting
		  Weekday,NoWeekday //day of the week
	};    

	enum arithmetic {Days,Years,Months};

//DateException class
class DateException{
	
  	 public:// method - DateException
		// description - to set the error message initialize it to ""
		// preconditions - a string error
		// postconditions - to set the error message initialize it to ""
		// method input - string msg
		// method output - none
    	 	 DateException(const string& s = ""){ msg =s;}
		// method - what
		// description - return the error message
		// preconditions -  none
		// postconditions - a error message was returned
		// method input - none
		// method output - string msg
       	 	 string what() const {return msg;}  
   	private:
     		 string msg;  //the error message
};

//Date class	
class Date{

	public:
		// method - constructor
		// description - construct a new Date object with current date
		// preconditions - none
		// postconditions - Date object created and initialize it to the current date
		// method input - none
		// method output - none
		Date();
		// method - constructor
		// description - construct a new Date object with (month, day, year)
		// preconditions - none
		// postconditions - Date object created with (month, day, year)
		// method input - int month, int day, int year
		// method output - none
		Date(int,int,int);
		// method - setDate
		// description - change the Date object with (month, day, year)
		// preconditions - month, day, year are int
		// postconditions - Date object has been set with (month, day, year)
		// method input - int month, int day, int year
		// method output - none
		void setDate(int,int,int);
		// method - setToday
		// description - to change the date object to current date
		// preconditions - A Date object was created
		// postconditions - A Date object has been sett with current date
		// method input - none
		// method output - none
		void setToday();
		// method - Today
		// description - return current date
		// preconditions - A Date object was created
		// postconditions - the current date was return
		// method input - none
		// method output - none
		static Date Today();
		// method - getMonth
		// description - return the month of the date
		// preconditions - A Date object was created
		// postconditions - the month was returned
		// method input - none
		// method output - none
		int getMonth() const;
		// method - getDay
		// description - return the day of the date
		// preconditions - A Date object was created
		// postconditions - the day was returned
		// method input - none
		// method output - none
		int getDay() const;
		// method - getYear
		// description - return the year of the date
		// preconditions - A Date object was created
		// postconditions - the year was returned
		// method input - none
		// method output - none
		int getYear() const;
		// method - getDayOfWeek
		// description - return the day of week based on the date
		// preconditions - A Date object was created
		// postconditions - the day of week was returned
		// method input - none
		// method output - none
		string getDayOfWeek() const;
		// method - outputFormat
		// description - setting the output to the right format
		// preconditions - A Date object was created and a format was given
		// postconditions - the output has been change based on the format
		// method input - format 
		// method output - none
		static void outputFormat(format);
		// method - getOutputFormat
		// description - return the output of the date object
		// preconditions - A Date object was created 
		// postconditions - return the output of the date object
		// method input - none 
		// method output - none
		static format getOutputFormat();
		// method - Arithmetic
		// description - setting the ari to the arithmetic which given be the ueser
		// preconditions - A Date object was created 
		// postconditions - ari was set by the user
		// method input - arithmetic 
		// method output - none
		static void Arithmetic(arithmetic);
		// method - getArithmetic
		// description - return the Arithmetic based on the date o
		// preconditions - A Date object was created 
		// postconditions - the ari of the date was returned
		// method input - none 
		// method output - none
		static arithmetic getArithmetic();
		// method - setMonth
		// description - to set the month with int month
		// preconditions - parameter should be int
		// postconditions - the month has been set
		// method input - int month 
		// method output - none
		void setMonth(int);
		// method - setDay
		// description - to set the day with int day
		// preconditions - parameter should be int
		// postconditions - the day has been set
		// method input - int day 
		// method output - none
		void setDay(int);
		// method - setYear
		// description - to set the year with int year
		// preconditions - parameter should be int
		// postconditions - the year has been set
		// method input - int year 
		// method output - none
		void setYear(int);
		// method - operator=
		// description - asign a date object to other date object
		// preconditions - parameter should be a Date
		// postconditions - A copy has make for date object and return it
		// method input - Date  
		// method output - none
		const Date& operator=(const Date&);
		// method - operator+  
		// description - increment a date by int
		// preconditions - parameter should be an int
		// postconditions - a date object has incresing 
		// method input - int  
		// method output - Date
		const Date& operator+(int);
		// method - operator-  
		// description - decresing a date by int
		// preconditions - parameter should be an int
		// postconditions - a date object has decresing 
		// method input - int  
		// method output - Date
		const Date& operator-(int);
		// method - operator- 
		// description - subtract two dates and return the days between two dates
		// preconditions - parameter should be an Date
		// postconditions - the different day was returned
		// method input - Date  
		// method output - int
		int operator-(const Date&) const;
		// method - operator+  
		// description - increment a date by int
		// preconditions - parameter should be an int
		// postconditions - a date object has incresing 
		// method input - int  
		// method output - Date
		const Date& operator+=(int);
		// method - operator-=  
		// description - decresing a date by int
		// preconditions - parameter should be an int
		// postconditions - a date object has decresing 
		// method input - int  
		// method output - Date
		const Date& operator-=(int);
		// method - operator++  
		// description - incresing a date  by int
		// preconditions - none
		// postconditions - a date object has incresing by int
		// method input - int  
		// method output - Date
		Date operator++(int);
		// method - operator++  
		// description - incresing a date  
		// preconditions - none
		// postconditions - a date object has incresing by 1
		// method input - none  
		// method output - Date
		const Date& operator++();
		// method - operator--  
		// description - decresing a date by int
		// preconditions - parameter should be an int
		// postconditions - a date object has decresing 
		// method input - int  
		// method output - Date
		Date operator--(int);
		// method - operator--  
		// description - decresing a date 
		// preconditions - none
		// postconditions - a date object has decresing by 1
		// method input - none  
		// method output - Date
		const Date& operator--();
		//override those relational operators take Date as argument	
		bool operator==(const Date&) const;
		bool operator!=(const Date&) const;
		bool operator<(const Date&) const;
		bool operator<=(const Date&) const;
		bool operator>(const Date&) const;
		bool operator>=(const Date&) const;
		// method - isValid
		// description - checking if the month , day, and year are valid 
		// preconditions - take three arguments
		// postconditions - return true if it is valid, return false if it is invalid
		// method input - int month, int day, and int year  
		// method output - bool
		bool isValid(int,int,int);
		// method - rdn 
		// description - the rdn logic return how many days between two dates 
		// preconditions - take a date as a argument and a date must be created
		// postconditions - retrun the days between two dates
		// method input - Date
		// method output - number of days (int)
		int rdn(const Date&) const;
		// method - daysUntil 
		// description - return the days besed on current date 
		// preconditions - a date class was created
		// postconditions - a number of days was return
		// method input - none
		// method output - number of days (int)
		int daysUntil() const;
		// method - until 
		// description - return the days or years besed on current date and arithmetic
		// preconditions - a date class was created
		// postconditions - a number of days or years was return 
		// method input - none
		// method output - number of days (int)		
		int until() const;
		
	private:
		int month;   //month of the date
		int day;    //day of the date
		int year;    //year of the date
		static format output;    //output format
		static arithmetic ari;    //arithmetic
	};

	ostream& operator<<(ostream&, const Date&);
	istream& operator>>(istream&, Date&);

};

#endif
