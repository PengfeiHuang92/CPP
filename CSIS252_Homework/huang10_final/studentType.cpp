#include <iostream>
#include <string>
#include <iomanip>
#include "studentType.h"

using namespace std;
bool studentType::operator==(const studentType& st) const{
  return getScore() == st.getScore();
}
bool studentType::operator !=(const studentType& st) const{
  return  getScore() != st.getScore();
}
bool studentType::operator <(const studentType& st) const{
  return  getScore() < st.getScore();
}
bool studentType::operator <=(const studentType& st) const{
  return  getScore() <= st.getScore();
}
bool studentType::operator >(const studentType& st) const{
  return  getScore() > st.getScore();
}
bool studentType::operator >=(const studentType& st) const{
  return  getScore() >= st.getScore();
}
istream& operator>>(istream& i ,studentType& st){
  string tmpName;
  int tmpScore;
  getline(i,tmpName);
  i>>tmpScore;
  st.setStudent(tmpName,tmpScore);
  i.ignore(80,'\n');
  return i;
}

studentType::studentType(){
  dateType date(1,1,2000);
  personType::setPerson("Tim",date);
  setScore(0);
}

void studentType::setScore(int s){
  score = s;
}
studentType::studentType(string n, int s){
  dateType date(1,1,2000);
  personType::setPerson(n,date);
  setScore(s);
}

void studentType::setStudent(string n, int s){
  dateType date(1,1,2000);
  personType::setPerson(n,date);
  score = s;
}

int studentType::getScore() const{
  return score;
}

ostream& operator<<(ostream& out, const studentType& p){
  out<<setw(15)<<left<<p.getName()<<setw(10)<<right<<p.getScore();

  return out;
}