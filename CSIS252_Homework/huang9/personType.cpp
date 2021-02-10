#include "personType.h"
#include "dateType.h"
#include <string>
#include <iostream>

using namespace std;
bool personType::operator==(const personType& p) const{
  return getBirthday() == p.getBirthday();

}
bool personType::operator !=(const personType& p) const{
  return  getBirthday() != p.getBirthday();
}
bool personType::operator <(const personType& p) const{
  return  getBirthday() < p.getBirthday();
}
bool personType::operator <=(const personType& p) const{
  return  getBirthday() <= p.getBirthday();
}
bool personType::operator >(const personType& p) const{
  return  getBirthday() > p.getBirthday();
}
bool personType::operator >=(const personType& p) const{
  return  getBirthday() >= p.getBirthday();
}

istream& operator>>(istream& i ,personType& p){
  string tmpName;
  int day;
  int month;
  int year;
  char slash;
  dateType tmpDate;
  getline(i,tmpName);
  i>>month;
  i>>slash;
  i>>day;
  i>>slash;
  i>>year;
  tmpDate.setDate(month,day,year);
  p.setPerson(tmpName,tmpDate);
  i.ignore(80,'\n');
  return i;
}

ostream& operator<<(ostream& out, const personType& p){
  out<<p.getName()<< ":  "<<p.getBirthday()<<endl;
  return out;
}
personType::personType(){
  dateType date(1,1,2000);
  setPerson("Tim",date);
}
personType::personType(string n, dateType d){
  setPerson(n,d);
}

void personType::setPerson(string n, const dateType& d) {
  name=n;
  birthday=d;
}

string personType::getName() const{
  return name;
  
}

dateType personType::getBirthday() const{
  return birthday;
}
