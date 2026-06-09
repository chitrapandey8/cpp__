#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {4,3,2,1,8};
    int x = 2;
    stack<int> st;
    for(int i = 0; i<arr.size(); i++){
        st.push(arr[i]);
    }
     
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }

    st.push(x);

    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }

    int i = 0;
    while(i<st.size()){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}