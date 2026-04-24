#include <bits/stdc++.h>
using namespace std;

//overview of the exception  class
// class exception{
//     protected:
//     string mess;
//     public:
//     exception(string mess){
//         this->mess = mess;
//     }

//     void what(){
//         cout<<mess<<endl;
//     }
// };

int main() {
    try{
     int *p = new int[10000000000000000];
    cout<<"Memory allocation is sucessfull"<<endl;
    delete []p;
    }catch(const exception &e){//exception ek class hai , kya throw hora hai uska type hai exceptio ka type   
    cout<<"Exception occured line"<<e.what()<<endl; //bad_alloc ek class hai exception we can also write bad_alloc in place of exception
    }
    
    return 0;
}