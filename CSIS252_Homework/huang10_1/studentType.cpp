#include <iostream>
#include <string>
#include "studentType.h"
#include "dateType.h"
#include "personType.h"
#include <fstream>
using namespace std;

istream& operator>>(istream& i ,studentType st){
  string tmpName;
  int tmpScore;
  getline(i,tmpName);
  i>>tmpScore;
  st.setStudent(tmpName,tmpScore);
  i.ignore(80,'\n');
  return i;
}
ostream& operator<<(ostream& out, const studentType& st){
  out<<st.getName()<<": "<< st.getScore()<<endl;
}
studentType::studentType(){
  setStudent("Tim",0);
}
studentType::studentType(string n, int s){
  
  setStudent(n,s);
}

void setStudent(string n, int s){
  dateType tmpDate;
  personType::setPerson(n,tmpDate);
  setScore(s);
}
void setScore(int s){
  
  score = s;
}
int getScore() const{
  return score;
}