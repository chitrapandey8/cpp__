#include <bits/stdc++.h>
using namespace std;

//Abstraction -- IT displays only essential information && and hiding the unneccsary details. mujhe nhi janna ki kaam kese klarr ahia kya ye mujhe result dera hai

class Customerrr{
    string name;
    int balance;
    int age;
    int amount;
    
    public:
    Customerrr(string name, int balance, int age){
        this->name = name;
        this->balance = balance;
        this->age = age;
    }
    
    void diposit(int amount){
    if(amount > 0){
        balance += amount;
    }else{
        cout<<"not possible"<<endl;
    }
    }

    void withdraw(int amount){
        if(amount > balance){
            cout<<"not enough balance"<<endl;
        }else{
            balance -= amount;
        }
    }

    void display(){
        cout<<name<<" "<<balance<<endl;
    }
   
};


int main() {
    Customerrr c("chita", 100, 7);
    c.display();
    c.diposit(1000);
    c.display();
    c.withdraw(200);
    c.display();
    c.diposit(-1);
    return 0;
}