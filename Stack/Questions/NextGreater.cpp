#include <bits/stdc++.h>
using namespace std;
///Nearest greater elemet 8-6, 6-9, 4-7 ..... 
int main() {
    vector<int> arr = {8,6,4,7,4,9,10,8,12};
    vector<int> ans(arr.size(),-1);

    stack<int> st;
    for(int i = 0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i]; 
            st.pop();
        }
        st.push(i);
    }

    for(int x: ans){
        cout<<x<<" ";
    }
    return 0;
}