#include <iostream>
#include <fstream>
#include "timeType.h"
#include "dateType.h"
#include "personType.h"
using namespace std;

int main(){
  
  personType person; //test the person method without giving the name and birthday
  cout<<person<<endl;
  cout<<"Changing the name and birthday from the file"<<endl;
  ifstream f;
  f.open("people");  
  f>>person;	//testing >>
  cout<<person<<endl; //testing <<
  cout<<"Person's name: "<<person.getName()<<endl;  //testing getName method
  cout<<"Person's birthday: "<<person.getBirthday()<<endl; //testing getBirthday method
  cout<<"------------------"<<endl;
  cout<<"change the birthday to 10/12/2018"<<endl;
  dateType tmpBirthday(10,12,2018);
  person.setPerson(person.getName(),tmpBirthday);  //testing setPerson method
  cout<<person<<endl;
  cout<<"------------------"<<endl;
  cout<<"change the name to Josh"<<endl;   
  person.setPerson("Josh",person.getBirthday());
  cout<<person<<endl;
  cout<<"------------------"<<endl;
  //dateType testBirthday(10,12,2017);
  cerr<< "...................aaaaaaaaaaa"<<endl;
  dateType testBirthday(2,29,1999);
  personType person_test("Test",testBirthday); //testing the person method with two attributes, name and birthday
  cout<<"testing person: test"<<endl;
  cout<<person_test<<endl;
  cerr<< "...................aaaaaaaaaaa"<<endl;
  cout<<"compare "<<person.getName()<<" with "<<person_test.getName()<<endl;
  cout<<"compare the two people are equal "<<endl;
  if(person==person_test) //testing operator == 
    cout<< "True"<<endl;
  else
    cout<<"False"<<endl;
  cout<<endl;
  
  cout<<"------------------"<<endl;
  cout<<"compare the two people are not equal "<<endl; //testing operator!= 
  if(person!=person_test)
    cout<< "True"<<endl;
  else
    cout<<"False"<<endl;
  
  cout<<"------------------"<<endl;
  cout<<"compare the person is less than or equal to person_test "<<endl; //testing operator<= 
  if(person<=person_test)
    cout<< "True"<<endl;
  else
    cout<<"False"<<endl;
  
  cout<<"------------------"<<endl;
  cout<<"compare the person is less than person_test "<<endl; //testing operator < 
  if(person<person_test)
    cout<< "True"<<endl;
  else
    cout<<"False"<<endl;
  
  cout<<"------------------"<<endl;
  cout<<"compare the person is greater than or equal to person_test "<<endl; //testing operator >=
  if(person>=person_test)
    cout<< "True"<<endl;
  else
    cout<<"False"<<endl;

  cout<<"------------------"<<endl;
  cout<<"compare the person is greater than person_test "<<endl; //testing operator>
  if(person>person_test)
    cout<< "True"<<endl;
  else
    cout<<"False"<<endl;
 
}
