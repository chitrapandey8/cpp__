#include <bits/stdc++.h>
using namespace std;

class Customer{
    string name;
    int balance;
    int age;
    int amount;

    Customer(string name, int balance, int age){
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
        
    }
   
};


int main() {
    return 0;
}