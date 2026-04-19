#include<bits/stdc++.h>
using namespace std;

class Student{
     private:
     string name;
    int age;    //ye memoery mai char ek ek block lega 4 byte hi lega or segment ban leta hai or segmet mai hi read karta hai,
     int grade = 2;
    
    
   ////setter
   public:
   void setname(string n){
    name  = n;
   }

   void getname(){
    cout<<name<<endl;
   }
    
   void getgrade(int n){
    if(n == 123){
        cout<<grade<<endl;
    }else{
        cout<<"error"<<endl;
    }
   }
};

int main(){
    Student s;
    
    s.setname("hello");
    s.getname();
    s.getgrade(123);

    return 0;
}