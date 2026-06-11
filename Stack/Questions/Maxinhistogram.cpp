#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> arr){
    int n= arr.size();
        int maxans = INT_MIN;
        for(int i = 0; i<n; i++){

            int mini = INT_MAX;
            for(int j = i; j<n; j++){
                mini = min(mini, arr[j]);
                maxans = max(maxans, mini*(j-i+1));
            }
        }
        return maxans;
}

int Maxinleftandright(vector<int> arr){
///Next Smaller in right
int n = arr.size();
vector<int> Right(n,n);
stack<int> st;
for(int i = 0; i<n;i++){
 
   while(!st.empty() && arr[st.top()] > arr[i]){
     Right[st.top()] = i;
     st.pop();
   }
    st.push(i);
}

while (!st.empty())
{
    st.pop();
}
////Next Smaller on left;

vector<int> Left(n,-1);
for(int i = n-1; i>=0;i--){
 
   while(!st.empty() && arr[st.top()] > arr[i]){
     Left[st.top()] = i;
     st.pop();
   }
    st.push(i);
}



int ans = INT_MIN;
for(int i = 0; i<n; i++){
ans = max(ans, arr[i]*(Right[i]-Left[i]-1));
}
return ans;
};

int Optimised(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    int ans = INT_MIN;
    for(int i = 0; i<n; i++){
        while(!st.empty() &&  arr[st.top()] > arr[i]){
            int height = st.top();
            st.pop();
            if(st.empty()){
              ans = max(ans, arr[height]*(i));
            }else{
                ans = max(ans, arr[height]*(i-st.top()-1));
            }

        }
        st.push(i);
    }

    while(!st.empty()){
            int height = st.top();
            st.pop();
            if(st.empty()){
              ans = max(ans, arr[height]*(n));
            }else{
                ans = max(ans, arr[height]*(n-st.top()-1));
            }

        }
     return ans;

}

int maximalRectangle(vector<vector<string>> arr){
    
   vector<int> rec(arr[0].size(),0);
   int ans = INT_MIN;
    for(int i = 0; i<arr.size(); i++){
        for(int j =0; j<arr[0].size(); j++){
            if(arr[i][j] == "1"){
                rec[j] += 1;
            }else{
                rec[j] = 0;
            }
        }
        ans = max(ans, Optimised(rec));
    }
    return ans;

}

int main() {
    vector<vector<string>> arr = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    cout<<maximalRectangle(arr);    
    return 0;
}