#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2,3,5,-4,6,-2,-8,9};
    stack<int> st;

    for(int i = 0; i<arr.size(); i++){
    if(st.empty()){
        st.push(arr[i]);
    }else if(arr[i] >= 0){
     if(st.top() >= 0){
        st.push(arr[i]);
     }else{
        st.pop();
     }
    }else{  ///agar array[i] is negative
        if(st.top() < 0){
            st.push(arr[i]);
        }else{
            st.pop();
        }
    }
    }

    while(!st.empty()){
     cout<<st.top()<<endl;
     st.pop();
    }
    return 0;
}