#include <bits/stdc++.h>
using namespace std;


class Customerr{
string name;
int acc_no;
int balance;
int amount;

public:
static int total_bank_balance;
static int total_cos;


public:
Customerr(string n, int a, int b){
name = n;
acc_no = a;
balance = b;
total_bank_balance += balance;
total_cos++;
}

void Display(){
    cout<<name<<" "<<acc_no<<" "<<balance<<" "<<endl;
}

static void totalcustomer(){
cout<<total_cos;
//cout<<name; static function sirf static varibale ko stroe sakta hai.
}


void deposit(int amount){
if(amount > 0){
    balance += amount;
    total_bank_balance += amount;
}else{
    cout<<"NOT POSSIBILE"<<endl;
}
}

void withdraw(int amount){
if(amount > balance){
    cout<<"NOT SUFFICIENT BALANCE"<<endl;
}
}
};

int Customerr::total_cos = 0; //ye actually  mai memory allocation hota hai coz static sirf declare krta hai //ek ki baar create karega or jitne bhi object ho sab share kare. // :: ye scope resolution operator hai 
int Customerr::total_bank_balance = 0;

int main() {
    Customerr c("chitranshi", 1,1000);
    Customerr b("sania", 2, 2000);
    c.Display();
    b.Display();
    cout<<Customerr::total_cos<<endl;
    Customerr::totalcustomer();
    cout<<Customerr::total_bank_balance<<endl;
    
    
    return 0;
}