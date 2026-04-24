//An Myexception is an unexpected problem that arises during the excution of a program & our program termiantyes suddenly with some error/issues.
#include <bits/stdc++.h>
using namespace std;

//khud ki class
class Invalidamounterr : public Myruntime_error{
 public:
 Invalidamounterr(): Myruntime_error(mess){

 }
};

class Myexception{
    public :
    string mess;
    public:
    
    Myexception(string mess){
        this->mess = mess;
    }

    void what(){
        cout<<mess<<endl;
    }
};
class Myruntime_error : public Myexception{
    public:
    Myruntime_error(const string *p): Myexception(mess){

    }
};

class Customer{
    string name;
    int balance;
    int acc_no;
    
    public:
    Customer(string name, int balance, int acc_no){
     this->name = name;
     this->balance = balance;
     this->acc_no = acc_no;
    }

    void Deposi(int amount){
   if(amount > 0){
    balance +=  amount;
    cout<<"amount credited"<<endl;

   }else{
    throw "amount should be greater than 0"; //yaha hum throw runtime_error bhi akrf sakte hai cox ye ek runtime hai
   }
    }

    void Withdraw(int amount){
   if(amount > 0 && amount <= balance){
    balance -=  amount;
    cout<<"amount DEbeted"<<endl;
   }else if(amount < 0){
    throw "amnount should be greater than 0"; // ye terminate kar deta hai
   }else{
     throw "BAlance is low";
   }
    }
    void  display(){
    cout<<balance<<endl;
    }
};

int main() {
   Customer c("chitranshi", 100, 1);
   try{
c.Deposi(-1);
c.display();
   }catch(const char *e){ //jo bhi throw hora hai voh yaha e mai ajaayega , runtime_erorr ek class hai , jab voh throw hora hai or phir catch mai cathc hora hai or e mai jatra hai, runtime_error mai char ki jagah runtime_error likahege
   cout<<"Exception occured"<<e<<endl;
   }
    return 0;
}