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
vector<int> Left(n,-1);
stack<int> st;
for(int i = 0; i<n;i++){
 
   while(!st.empty() && arr[st.top()] < arr[i])

    st.push(i);
}


};

int main() {
    vector<int> arr = {2,1,5,6,2,3};
    
    return 0;
}