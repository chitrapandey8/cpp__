#include <bits/stdc++.h>
using namespace std;



int main() {
    stack<int> st;
    string s = "hello";

    //push in stack
    for(int i = 0; i<s.size(); i++){
    st.push(s[i]);
    }

     //pop and insert in stack
     int i = 0;
     while(!st.empty()){
       s[i] = st.top();
       i++;
       st.pop();
     }
    
     cout<<s<<endl;
    return 0;
}