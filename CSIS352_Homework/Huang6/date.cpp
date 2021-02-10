//FIle:  date.cpp
//Author: Pengfei Huang

//Description
// This file contains the implementation for a date class

#include "date.h"
#include <sstream>
#include <fstream>
#include <ctime>
#include <string>
#include "date.h"
using namespace std;
using namespace DateNameSpace;

format Date::output = Slash;
arithmetic Date::ari = Days;
static string monthFormatting = "Numeric";   //setting default value
static string orderOfDate= "MiddleEndian";    //setting default value
static string delimeter = "Slash";    //setting default value
static string dayOfWeek = "NoWeekday";    //setting default value

Date::Date(){
// this section gets and output the current date and time
   tm *current;
   time_t lt;
   lt = time(0);
   current = localtime(&lt);
   setMonth(current->tm_mon+1);
   setDay(current->tm_mday);
   setYear(current->tm_year + 1900);
}
Date::Date(int m, int d, int y){
    setDate(m,d,y);
}
void Date::setDate(int m, int d, int y){
    if(isValid(m,d,y)){
        setMonth(m);
        setDay(d);
        setYear(y);
    }else{  //throw out the exceptions 
        
        if (m>12 || m<1){    // invalid month error
            throw DateException("DateException: invalid month, month =" + to_string(m));
        }else{  // invalid date error
            throw DateException("DateException: invalid day, month =" + to_string(m)+", day=" + to_string(d) + ", year="+to_string(y));
        }
    }
    
    
}
void Date::setToday(){
    *this = Date();  //set the day to current date
   
}

Date Date::Today(){
    
    return Date();
}
int Date::getMonth() const{
	return month;
}
int Date::getDay() const{
	return day;
}
int Date::getYear() const{
	return year;
}
string Date::getDayOfWeek() const{
    int tmpMonth = getMonth();
    int tmpDay = getDay();
    int tmpYear = getYear();
    string tmpStrDayOfWeek ="";
    //getting the day of the Weekday
      int  centuries = (3-tmpYear/100%4)*2;
   switch (tmpMonth)
   {
      case 1  : if (tmpYear % 400 == 0 || (tmpYear%4 == 0 && tmpYear%100 != 0)) //checking if the year is leap Year
                   tmpMonth = 6;
                else
                   tmpMonth = 0; 
                break;
      case 2  : if (tmpYear % 400 == 0 || (tmpYear%4 == 0 && tmpYear%100 != 0))
                   tmpMonth = 2;
                else
                   tmpMonth = 3; 
                break;
      case 3  : tmpMonth = 3; break;
      case 4  : tmpMonth = 6; break;
      case 5  : tmpMonth = 1; break;
      case 6  : tmpMonth = 4; break;
      case 7  : tmpMonth = 6; break;
      case 8  : tmpMonth = 2; break;
      case 9  : tmpMonth = 5; break;
      case 10 : tmpMonth = 0; break;
      case 11 : tmpMonth = 3; break;
      case 12 : tmpMonth = 5; break;
   }


   switch ((centuries+tmpYear%100+tmpYear%100/4+tmpMonth+tmpDay)%7)
   {
      case 0 : tmpStrDayOfWeek = "Sunday"; break;
      case 1 : tmpStrDayOfWeek = "Monday"; break;
      case 2 : tmpStrDayOfWeek="Tuesday"; break;
      case 3 : tmpStrDayOfWeek="Wednesday"; break;
      case 4 : tmpStrDayOfWeek="Thursday"; break;
      case 5 : tmpStrDayOfWeek="Friday"; break;
      case 6 : tmpStrDayOfWeek="Saturday";break;
   }
   return tmpStrDayOfWeek;

}

void Date::outputFormat(format f){
    output = f;
      switch(output){
        case MiddleEndian: orderOfDate = "MiddleEndian";break;
        case LittleEndian: orderOfDate = "LittleEndian"; break;
        case BigEndian: orderOfDate = "BigEndian"; break;
        case Slash: delimeter = "Slash"; break;
        case Dash: delimeter = "Dash"; break;
        case Space: delimeter = "Space"; break;
        case Text: monthFormatting = "Text"; break;
        case Numeric: monthFormatting = "Numeric"; break;
        case Weekday: dayOfWeek = "Weekday"; break;
        case NoWeekday: dayOfWeek = "NoWeekday"; break;
               
    }
}

format Date::getOutputFormat(){
    return output;
}
void Date::Arithmetic(arithmetic tmpAri){
    ari = tmpAri;
}
arithmetic Date::getArithmetic(){
    return ari;
}

void Date::setMonth(int m){
	month = m;
}
void Date::setDay(int d){
	day = d;
}
void Date::setYear(int y){
	year = y;
}
const Date& Date::operator=(const Date& date){
    setDate(date.getMonth(),date.getDay(),date.getYear());
    return *this;
}
const Date& Date::operator+(int i){
    
    int tmpMonth = getMonth();
    int tmpDay = getDay();
    int tmpYear = getYear();
    int total;   //total days based on int i 
    switch(Date::getArithmetic()){
        case Months:
            break;
        case Days:
            total = tmpDay + i;
            while(isValid(tmpMonth,total,tmpYear) == false){
                if(tmpMonth==1 || tmpMonth==3 ||tmpMonth==5 ||tmpMonth==7 ||tmpMonth==8 ||tmpMonth==10 ||tmpMonth==12){
                   if(tmpMonth + 1 <=12){ tmpMonth +=1; total -= 31;}
                   else{tmpMonth=1; total-=31; tmpYear+=1;}
                    
                }else if(tmpMonth == 4 ||tmpMonth == 6 ||tmpMonth == 9 ||tmpMonth ==11){
                    tmpMonth+=1; total-=30;
                    
                }else{
                    if(tmpYear % 400 == 0 || (tmpYear%4 == 0 && tmpYear%100 != 0)){
                        tmpMonth+=1; total-=29;
                    }else{
                        tmpMonth+=1; total-=28;
                    }
                }
            }
            tmpDay =total;
            break;
        case Years:
            tmpYear = tmpYear+i;
            break;
    }
    setDate(tmpMonth,tmpDay,tmpYear);
    return *this;
    
}
const Date& Date::operator-(int i){
    int tmpMonth = getMonth();
    int tmpDay = getDay();
    int tmpYear = getYear();
    int total;    //total days based on int i 
    switch(Date::getArithmetic()){
        case Months:
            break;
        case Days:
            total = tmpDay - i;
            while(isValid(tmpMonth,total,tmpYear) == false){
                if(tmpMonth==5 ||tmpMonth==7 ||tmpMonth==8 ||tmpMonth==10 ||tmpMonth==12){
                    tmpMonth -=1; total += 30;                  
                    
                }else if(tmpMonth == 1 ||tmpMonth == 2 ||tmpMonth == 4 ||tmpMonth == 6 ||tmpMonth == 9 ||tmpMonth ==11){
                    if(tmpMonth  ==1){
                        tmpMonth=12; total+=31; tmpYear-=1;
                    }else{
                    tmpMonth-=1; total+=31;
                    }
                }else{
                    if(tmpYear % 400 == 0 || (tmpYear%4 == 0 && tmpYear%100 != 0)){
                        tmpMonth-=1; total+=29;
                    }else{
                        tmpMonth-=1; total+=28;
                    }
                }
            }
            tmpDay =total;
            break;
        case Years:
            tmpYear = tmpYear -i;
            break;
    }
    setDate(tmpMonth,tmpDay,tmpYear);
    return *this;
    
}
int Date::operator-(const Date& date) const{
    int tmpNum;
    switch(date.getArithmetic()){
        case Years:
            if(getYear()-date.getYear() >=0){
                if(getMonth()>date.getMonth()){
                    tmpNum = getYear() - date.getYear();
                }else if(getMonth() == date.getMonth()){
                    if(getDay() >= date.getDay()){
                        tmpNum = getYear() - date.getYear();
                    }else{
                        tmpNum = getYear() - date.getYear() -1;
                    }
                }else{
                    tmpNum = getYear() - date.getYear() -1;
                }
                    
            }else{
                if(getMonth()>date.getMonth()){
                    tmpNum = getYear() - date.getYear() +1;
                }else if(getMonth() == date.getMonth()){
                    if(getDay() >= date.getDay()){
                        tmpNum = getYear() - date.getYear();
                    }else{
                        tmpNum = getYear() - date.getYear() ;
                    }
                }else{
                    tmpNum = getYear() - date.getYear() ;
                }
            }
            
            break;
        case Months:
            break;
        default:
             tmpNum = rdn(*this) - rdn(date);
          
            break;
    }
    return tmpNum;
}
const Date& Date::operator+=(int i){
    return *this +i ;
}
const Date& Date::operator-=(int i){
    return *this - i;
}
Date Date::operator++(int){  //post increment
    Date tmpDate(getMonth(),getDay(),getYear());
    switch(Date::getArithmetic()){
        case Months:
            break;
        case Days:
            if(isValid(getMonth(),getDay()+1,getYear())){
                setDate(getMonth(),getDay()+1,getYear()); 
            }else if(isValid(getMonth()+1,1,getYear())){
                setDate(getMonth()+1,1,getYear());
            }else if(isValid(1,1,getYear()+1)){
                setDate(1,1,getYear()+1);
            }
            break;
        case Years:
            setDate(getMonth(),getDay(),getYear()+1);
            break;
    }
    
    return tmpDate;
}
const Date& Date::operator++(){  //pre increment
    switch(Date::getArithmetic()){
        case Months:
            break;
        case Days:
            if(isValid(getMonth(),getDay()+1,getYear())){
                setDate(getMonth(),getDay()+1,getYear()); 
            }else if(isValid(getMonth()+1,1,getYear())){
                setDate(getMonth()+1,1,getYear());
            }else if(isValid(1,1,getYear()+1)){
                setDate(1,1,getYear()+1);
            }
            break;
        case Years:
            setDate(getMonth(),getDay(),getYear()+1);
            break;
    }
    return *this;
}
Date Date::operator--(int){  //post decrement
    Date tmpDate(getMonth(),getDay(),getYear());
    switch(Date::getArithmetic()){
        case Months:
            break;
        case Days:
            if(isValid(getMonth(),getDay()-1,getYear())){
                setDate(getMonth(),getDay()-1,getYear()); 
            }else if(isValid(getMonth()-1,31,getYear())){
                setDate(getMonth()-1,31,getYear());
            }else if(isValid(getMonth()-1,30,getYear())){
                setDate(getMonth()-1,30,getYear());
            }else if(isValid(getMonth()-1,29,getYear())){
                setDate(getMonth()-1,29,getYear());
            }else if(isValid(getMonth()-1,28,getYear())){
                setDate(getMonth()-1,28,getYear());
            }else if(isValid(12,31,getYear()-1)){
                setDate(12,31,getYear()-1);
            }break;
        case Years:
             setDate(getMonth(),getDay(),getYear()-1);
    }
    
    
    return tmpDate;
}
const Date& Date::operator--(){  //pre increment
   switch(Date::getArithmetic()){
        case Months:
            break;
        case Days:
            if(isValid(getMonth(),getDay()-1,getYear())){
                setDate(getMonth(),getDay()-1,getYear()); 
            }else if(isValid(getMonth()-1,31,getYear())){
                setDate(getMonth()-1,31,getYear());
            }else if(isValid(getMonth()-1,30,getYear())){
                setDate(getMonth()-1,30,getYear());
            }else if(isValid(getMonth()-1,29,getYear())){
                setDate(getMonth()-1,29,getYear());
            }else if(isValid(getMonth()-1,28,getYear())){
                setDate(getMonth()-1,28,getYear());
            }else if(isValid(12,31,getYear()-1)){
                setDate(12,31,getYear()-1);
            }break;
        case Years:
             setDate(getMonth(),getDay(),getYear()-1);
    }
    return *this;
}
bool Date::operator==(const Date& date) const{
    return getDay() == date.getDay() && getMonth() == date.getMonth() && getYear() == date.getYear();
}
bool Date::operator!=(const Date& date) const {
    return !(*this==date);
}
bool Date::operator<(const Date& date) const{
    bool tmp =false;
    if(getYear() < date.getYear()){
        tmp = true;
    }else if(getYear() == date.getYear()){
        if(getMonth() < date.getMonth()){
            tmp =true;
        }else if(getMonth() == date.getMonth()){
            if(getDay() < date.getDay()){
                tmp =true;
            }
        }
        
    }
    return tmp;
}
bool Date::operator<=(const Date& date) const{
    return (*this < date || *this == date);
}
bool Date::operator>(const Date& date) const{
    return !(*this <= date);
}
bool Date::operator>=(const Date& date) const{
    return !(*this < date);
}
bool Date::isValid(int m, int d, int y ){   
    bool isValid =false;
    if(m < 13 && m > 0){  //if m is valid
        
    if(m == 1 || m == 3 ||m == 5 ||m == 7 ||m == 8 ||m == 10 ||m == 12){  //if month has 31 dyas 
                if(d <= 31 && d>0){  //the day only can be valid from 1 to 30
                    isValid =true;
                }
    }else if(m == 2){  // if the month is February
         
        if(y % 400 == 0 || (y%4 == 0 && y%100 != 0)){
            if(d<=29 && d>0){  //the leap year has 29 days in February
                isValid =true;
            }
        }else{
            if(d<29 && d>0){  //no leap year has 28 days in February
                isValid =true;
            }
        }
        
    } // end of if(m == 2)
    else{ //if the month has 30 dyas
         if(d <= 30 && d>0){  //the day only can be valid from 1 to 30
                    isValid =true;
                }
    }
        
    }
    return isValid;
}
 int Date::rdn(const Date& date) const{  //rdn logic
     int m =date.getMonth();
     int d =date.getDay();
     int y = date.getYear();
      if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;

}
int Date::daysUntil() const{
    Date currentDate;
    Date currenrBirtday;
     int tmpNum;
    if(getMonth()<currentDate.getMonth()){
        currenrBirtday.setDate(getMonth(),getDay(),currentDate.getYear()+1);
    }else if(getMonth() == currentDate.getMonth()){
        if(getDay()<currentDate.getDay()){
            currenrBirtday.setDate(getMonth(),getDay(),currentDate.getYear()+1);
        }
    }else{
        currenrBirtday.setDate(getMonth(),getDay(),currentDate.getYear());
    }
    
     tmpNum = (rdn(currenrBirtday)- rdn(currentDate));
    
    return tmpNum;
}
int Date::until() const{
    int tmpNum;
    Date currentDate;
    switch(Date::getArithmetic()){
        case Months:
            /*** B level
            if(getMonth() > currentDate.getMonth()){
                if(getDay() > currentDate.getDay()){
                    tmpNum = getMonth() - currentDate.getMonth()-1;
                }else{
                    tmpNum = getMonth() - currentDate.getMonth();
                }
            }else if(getMonth() < currentDate.getMonth()){
                if(getDay() > currentDate.getDay()){
                    tmpNum = getMonth() - currentDate.getMonth()-1;
                }else{
                    tmpNum = getMonth() - currentDate.getMonth();
                }
            }
            ***/
            break;
        case Days:
            tmpNum =rdn(*this) - rdn(currentDate);
            break;
        case Years:
            if(getYear()>= currentDate.getYear()){
            if(getMonth() > currentDate.getMonth()){
            tmpNum = getYear() - currentDate.getYear();
            }else if (getMonth() ==currentDate.getMonth()){
                if(getDay() >= currentDate.getDay()){
                    tmpNum = getYear() - currentDate.getYear();
                }
            }else{
                tmpNum = getYear() - currentDate.getYear()-1;
            }
            }else{
                if(getMonth() < currentDate.getMonth()){
            tmpNum = getYear() - currentDate.getYear();
            }else if (getMonth() ==currentDate.getMonth()){
                if(getDay() <= currentDate.getDay()){
                    tmpNum = getYear() - currentDate.getYear();
                }
            }else{
                tmpNum = getYear() - currentDate.getYear()+1;
            }
            }
            break;
    }
    return tmpNum;
}
ostream& DateNameSpace::operator<<(ostream& o, const Date& date){
    

    stringstream outputStr;
    string tmpStr="";
    string tmpMonthOfYear="";
    string tmpStrDayOfWeek=date.getDayOfWeek();
    
    //getting the month of the yrear
            switch(date.getMonth()){
                case 1 : tmpMonthOfYear = "January"; break;
                case 2 : tmpMonthOfYear = "February"; break;
                case 3 : tmpMonthOfYear = "March"; break;
                case 4 : tmpMonthOfYear = "April"; break;
                case 5 : tmpMonthOfYear = "May"; break;
                case 6 : tmpMonthOfYear = "June"; break;
                case 7 : tmpMonthOfYear = "July"; break;
                case 8 : tmpMonthOfYear = "August"; break;
                case 9 : tmpMonthOfYear = "September"; break;
                case 10 : tmpMonthOfYear = "October"; break;
                case 11 : tmpMonthOfYear = "November"; break;
                case 12 : tmpMonthOfYear = "December"; break;
                
            }
  
    if(dayOfWeek == "Weekday"){
 
        
        //getting the tmpStr with Text format
        if(monthFormatting == "Text"){
            
            
            //getting the tmpsStr with text of the month of the year
          
                if(orderOfDate == "LittleEndian"){
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getDay()) + " " + tmpMonthOfYear + ", " + to_string(date.getYear());
                }else if(orderOfDate == "MiddleEndian"){
                    tmpStr = tmpStrDayOfWeek + ", " + tmpMonthOfYear + " " + to_string(date.getDay()) + ", " + to_string(date.getYear());
                }else{
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getYear()) + " " + tmpMonthOfYear + " " + to_string(date.getDay());
                }
                   
          
        }else{
            if(delimeter =="Slash"){
                if(orderOfDate == "LittleEndian"){
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getDay()) + "/" + to_string(date.getMonth()) + "/" + to_string(date.getYear());
                }else if(orderOfDate == "MiddleEndian"){
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getMonth()) + "/" + to_string(date.getDay()) + "/" + to_string(date.getYear());
                }else{
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getYear()) + "/" + to_string(date.getMonth()) + "/" + to_string(date.getDay());
                }
                   
            }else if(delimeter == "Dash"){
                if(orderOfDate == "LittleEndian"){
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getDay()) + "-" + to_string(date.getMonth()) + "-" + to_string(date.getYear());
                }else if(orderOfDate == "MiddleEndian"){
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getMonth()) + "-" + to_string(date.getDay()) + "-" + to_string(date.getYear());
                }else{
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getYear()) + "-" + to_string(date.getMonth()) + "-" + to_string(date.getDay());
                }
                
            }else{
                if(orderOfDate == "LittleEndian"){
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getDay()) + " " + to_string(date.getMonth()) + " " + to_string(date.getYear());
                }else if(orderOfDate == "MiddleEndian"){
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getMonth()) + " " + to_string(date.getDay()) + " " + to_string(date.getYear());
                }else{
                    tmpStr = tmpStrDayOfWeek + ", " + to_string(date.getYear()) + " " + to_string(date.getMonth()) + " " + to_string(date.getDay());
                }
            }
            
        }
    }else{  
        //getting the tmpStr with Text format
        if(monthFormatting == "Text"){
    
            //getting the tmpsStr with text of the month of the year
          
                if(orderOfDate == "LittleEndian"){
                    tmpStr =  to_string(date.getDay()) + " " + tmpMonthOfYear + ", " + to_string(date.getYear());
                }else if(orderOfDate == "MiddleEndian"){
                    tmpStr = tmpMonthOfYear + " " + to_string(date.getDay()) + ", " + to_string(date.getYear());
                }else{
                    tmpStr = to_string(date.getYear()) + " " + tmpMonthOfYear + " " + to_string(date.getDay());
                }
                   
          
        }else{
            if(delimeter =="Slash"){
                if(orderOfDate == "LittleEndian"){
                    tmpStr = to_string(date.getDay()) + "/" + to_string(date.getMonth()) + "/" + to_string(date.getYear());
                }else if(orderOfDate == "MiddleEndian"){
                    tmpStr =  to_string(date.getMonth()) + "/" + to_string(date.getDay()) + "/" + to_string(date.getYear());
                }else{
                    tmpStr =  to_string(date.getYear()) + "/" + to_string(date.getMonth()) + "/" + to_string(date.getDay());
                }
                   
            }else if(delimeter == "Dash"){
                if(orderOfDate == "LittleEndian"){
                    tmpStr =  to_string(date.getDay()) + "-" + to_string(date.getMonth()) + "-" + to_string(date.getYear());
                }else if(orderOfDate == "MiddleEndian"){
                    tmpStr =  to_string(date.getMonth()) + "-" + to_string(date.getDay()) + "-" + to_string(date.getYear());
                }else{
                    tmpStr =  to_string(date.getYear()) + "-" + to_string(date.getMonth()) + "-" + to_string(date.getDay());
                }
                
            }else{
                if(orderOfDate == "LittleEndian"){
                    tmpStr =  to_string(date.getDay()) + " " + to_string(date.getMonth()) + " " + to_string(date.getYear());
                }else if(orderOfDate == "MiddleEndian"){
                    tmpStr =  to_string(date.getMonth()) + " " + to_string(date.getDay()) + " " + to_string(date.getYear());
                }else{
                    tmpStr =  to_string(date.getYear()) + " " + to_string(date.getMonth()) + " " + to_string(date.getDay());
                }
            }
            
        }
        
    }
            
            
   
    outputStr <<tmpStr;
    
    o<<outputStr.str();
    return o;
}
istream& DateNameSpace::operator>>(istream& i, Date& date ){

    int tmpMonth;
    int tmpDay;
    int tmpYear;
    char tmpSlash;
    i>>tmpMonth>>tmpSlash>>tmpDay>>tmpSlash>>tmpYear;
    
    if(i.fail()){
        i.clear();
        i.ignore(1000,'\n');
        throw ios_base::failure("input stream failure");
        
    }else{
       date.setDate(tmpMonth,tmpDay,tmpYear);
    }
    
    return i;
}



