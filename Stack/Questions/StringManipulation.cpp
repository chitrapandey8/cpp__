#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> st = {"ab", "ac", "da","da","ac","db","ea"};
    stack<string> s;

    for(int i = 0; i<st.size(); i++){
        if(s.empty()){
            s.push(st[i]);
        }else if(s.top() == st[i]){
            s.pop();
        }else{
            s.push(st[i]);
        }
    }

    cout<<s.size()<<endl;
    return 0;
}