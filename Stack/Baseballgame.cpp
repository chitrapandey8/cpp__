#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    vector<string> st{"5","2","C","D","+"};
    for(int i = 0; i<st.size(); i++){
        if(st[i] == "C"){
            s.pop();
        } else if(st[i] == "+"){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.push(a);
            int add = a+b;
            s.push(add);
        } else if(st[i] == "D"){
            int a = s.top();
            int dou = a*2;
            s.push(dou);
        }else{
            s.push(stoi(st[i]));
        }

    }
     
    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout<<sum<<endl;
    


    return 0;
}