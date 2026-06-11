#include <bits/stdc++.h>
using namespace std;

class MinStack{

    stack<int> st1;
    stack<int> st2;

    public:
    MinStack(){
    }
    
    void push(int value){
     if(st1.empty()){
        st1.push(value);
        st2.push(value);
     }else{
         st1.push(value);
        st2.push(min(value, st2.top()));
     }
    } 

    void pop(){
      if(st1.empty()){
        return;
      }else{
        st1.pop();
        st2.pop();
      }
    }

    int top(){
       if(st1.empty()){
        return -1;
       }else{
         return st1.top();
       }
    }

    int getmin(){
      if(st2.empty()){
          return -1;
      }else{
        return st2.top();
      }
    }
};



int main() {
     MinStack m;
     m.push(2);
     m.push(3);
     cout<<m.getmin()<<endl;
     cout<<m.top()<<endl;
    return 0;
}