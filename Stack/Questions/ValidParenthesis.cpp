#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = ")";
    stack<int> st;
    for(int i = 0;i<s.size(); i++){
        
            
        if(st.empty() && s[i] == ')'){
          cout<<"NOt possible"<<endl;
          return 0;
        }
        
        if(s[i] == ')'){
            st.pop();
        }else if(s[i] == '('){
            st.push('(');
        }
    }

    if(st.empty()){
        cout<<"BBalanced"<<endl;

    }else{
        cout<<"NOT"<<endl;
        
    }
    return 0;
}