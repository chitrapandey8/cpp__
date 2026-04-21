#include <bits/stdc++.h>
using namespace std;

// wrapping up data & information in a single unit, while controlling access to them. so that people cannot have direct access to them and cannot change them by them own. 
class Customer{
   string name;
   int balance = 0; //sensitive data ko public mai mat dalo
   int age;
   
   public:
   Customer(string name, int balance, int age){
    this->balance = balance;
    this->name = name;
    this->age = age;
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

   void updateage(int age){
      if(age < 100 && age > 0){
         this->age = age;
      }else{
         cout<<"INVALID AGE"<<endl;
      }
   }

   void display(){
    cout<<name<<" "<<balance<<" "<<age<<endl;
   }

};

int main() {
    Customer a("chitranshi", 100, 18);
    a.setDeposit(100);
    a.display();
    a.updateage(20);
    a.display();
    return 0;
}
