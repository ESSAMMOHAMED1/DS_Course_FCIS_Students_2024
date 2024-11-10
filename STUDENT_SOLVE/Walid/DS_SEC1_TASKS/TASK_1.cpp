/*
 1- Create a class Student with private variables name and studentID.
 2- Include public variables like section
 3- Provide a constructor to initialize the private data members.
 4- Write get and set methods for the private data members.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class student
{
string name;
int id ;
public:
    int section ;

student (string n , int i)
{
name = n;
id = i;
}

void set_name(string n){
name = n ;
}
void set_id(int i){
id = i ;

}
string get_name(){
return name;
}
int get_id(){
return id ;
}


};



int main(){

student s("ahmed",2023);
cout<<s.get_name()<<endl;
cout<<s.get_id()<<endl;

student s2("" , 0);
s2.set_name("walid");
s2.set_id(2024);
cout<<s2.get_name()<<endl;
cout<<s2.get_id()<<endl;

}
