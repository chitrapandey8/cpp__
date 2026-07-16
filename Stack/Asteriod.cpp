#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr= {3,5,-6,2,-1,4};

     stack<int> st;
        for(int i = 0; i<arr.size(); i++){
            if(st.empty()){
                st.push(arr[i]);
            }else if(!st.empty() && arr[i] < 0){
                while(!st.empty() && st.top() >0){
                   if(st.top() < abs(arr[i])){
                    st.pop();
                   }else{
                    continue;
                   }
                }
                  st.push(arr[i]);
            }else{
                st.push(arr[i]);
            }           
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        for(int x: ans){
            cout<<x<<" ";
        }
    return 0;
}