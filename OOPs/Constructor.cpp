#include<bits/stdc++.h>
using namespace std;

class Customer{
    public:
    string name;
    int acc_num;
    int balance;
    int *bank;
        
    char s;
    int a;

    //default constructor:
    Customer(){
        cout<<"construxc is default"; //output mai ye statment print ho jayegi ye by deafylt call ho jata hai,
    }
    
    //paratimised constructor:
    Customer(string a, int b, int c, int bank){ //paramistirised constructor.
      name  = a; //default value assignong
      acc_num = b;
      balance = c;
      this->bank =  new int;
      *this->bank = bank;
    }

     //copy constructor:
     Customer(const Customer &B){
      name = B.name;
      acc_num = B.acc_num;
      balance = balance;
      bank = bank;
      
      cout<<"coppy constructor called"<<endl;
     }

     //it is the last function to be called, dynameic memoery agar li h toh usko relase bhi kaarao , warna by deafult bhi hota hai
      ~Customer(){
        cout<<"destructor is called"; //dynamic memoery relade karta hai. destructor reverse order mai call hota hai.
      }

    void print(){
        cout<<"i a"<<name <<"acc no id " <<acc_num <<*this->bank<<endl;
    }
};

int main()
{
    Customer A1("h",6, 6, 3); //dynammic meory allocation
    
    //copying obj
    A1.print();


    

    return 0;

}
