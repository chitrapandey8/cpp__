#include <bits/stdc++.h>
using namespace std;

class Queue{
stack<int> st1; //for pushing
stack<int> st2; //for popping

public:

bool empty(){
    return st1.empty() && st2.empty();
}

void push(int x){ //in stack 1
    st1.push(x);
}

int pop(){ //st2 se pop karo st2 khali hai toh psuh karo pir pop karo
if(empty()){
    return 0;
} else if(!st2.empty()){
  int element = st2.top();
  st2.pop();
   return element;
}else{ //empty hai toh st1 kelements st2 mai dalo
    while (!st1.empty())
    {
       st2.push(st1.top());
       st1.pop();
    }
    int element = st2.top();
  st2.pop();
   return element;
    
}
}

int peek(){
    if(empty()){
        return 0;
    }
    if(!st2.empty()){
        return st2.top();
    }else{
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
}
};

int main() {
    Queue q;
    q.push(2);
    cout<<q.peek();
    return 0;
}