#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "cbacdcbc";
    vector<int> arr(26,0);
    //find number of distinct characters
    int d = 0;
    for(int i = 0; i<s.size(); i++){
        if(arr[s[i] - 'a'] == 0){
            d++;
            arr[s[i] - 'a']++;
        }
    }
    for(int x: arr){
        cout<<x<<" ";
    }
    
    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        while(!st.empty() && st.top() > s[i]){

            d++;
            arr[st.top() - 'a'] = 1;
            st.pop();
        }

        if(arr[s[i] - 'a'] == 1){
            st.push(s[i]);
            d--;
            if(d == 0){
                break;
            }
            arr[s[i] - 'a'] == 0;
        }


    }
    
    return 0;
}