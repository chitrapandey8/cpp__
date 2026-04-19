#include <bits/stdc++.h>
using namespace std;

class Customer{
   string name;
   int balance = 0;
   
   public:
   Customer(string name, int balance){
    this->balance = balance;
    this->name = name;
   }

   void setDeposit(int amount){
     if(amount > 0){
        balance += amount;
     }else{
        cout<<"not real payment"<<endl;
     }
   }

   void withdraw(int amount){
   if(amount > balance){
    cout<<"possible"<<endl;
   }else{
    balance -= amount;
   }
   }

   void display(){
    cout<<name<<" "<<balance<<endl;
   }

};

int main() {
    Customer a("chitranshi", 100);
    a.withdraw(50);
    a.display();
    return 0;
}
