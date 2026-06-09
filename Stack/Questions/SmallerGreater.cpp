#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // vector<int> arr = {7,9,12,10,14,8,3,6,9};
    // vector<int> ans(arr.size(),-1);

    // stack<int> st;
    // for(int i = 0; i<arr.size(); i++){
    //     while(!st.empty() && arr[st.top()] > arr[i]){
    //         ans[st.top()] = arr[i]; 
    //         st.pop();
    //     }
    //     st.push(i);
    // }

    // for(int x: ans){
    //     cout<<x<<" ";
    // }

//////////////////////Another method?????????????????????????

    // vector<int> arr = {4,13,11,5,9,7,8,6};
    // vector<int> ans(arr.size(),-1);

    // stack<int> st;
    // for(int i = arr.size()-1; i>=0; i--){
    //     while(!st.empty() && arr[st.top()] < arr[i]){
    //         ans[st.top()] = arr[i]; 
    //         st.pop();
    //     }
    //     st.push(i);
    // }

    // for(int x: ans){
    //     cout<<x<<" ";
    // }


    ///////////Stock span problem/////////////////
    // vector<int> arr = {100,80,55,70,60,75,85};
    // vector<int> ans(arr.size(),1);

    // stack<int> st;
    // for(int i = arr.size()-1; i>=0; i--){
    //     while(!st.empty() && arr[st.top()] < arr[i]){
    //         ans[st.top()] = st.top()- i; 
    //         st.pop();
    //     }
    //     st.push(i);
    // }

    // for(int x: ans){
    //     cout<<x<<" ";
    // }


    ///////////////////
    vector<int> arr = {100 ,80, 60, 70, 60, 75, 85};
    vector<int> ans(arr.size(),1);

    stack<int> st;
    for(int i = arr.size()-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] < arr[i]){
            ans[st.top()] = st.top()-i; 
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
            ans[st.top()] = st.top()+1;
            st.pop();}
    for(int x: ans){
        cout<<x<<" ";
    }

    return 0;
}