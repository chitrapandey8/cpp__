#include <bits/stdc++.h>
using namespace std;

int main() {

    //stack is a container like ds which follows lifo(elemet that was inserted at the last will be inserted first), 
    stack<int> s;
     
    for (int i = 0; i <=5; i++)
    {
       s.push(i);
    }

    while(!s.empty()){
        cout<<s.top()<<endl; 
        s.pop();
    }
    
    return 0;
}