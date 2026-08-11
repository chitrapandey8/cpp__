#include <bits/stdc++.h>
using namespace std;

int minEnergy(int n, vector<int> arr, int k){
    //time complexity --- k^n
if(n == 0){
    return 0;
}

int result = INT_MAX;
for(int i = 1; i<=k && i<= n; i++){
result = min( result, (arr[n] - arr[n-i])+minEnergy(n-i, arr, k));
}
return result;
}

int minEnergy2(int n, vector<int> arr, int k, vector<int> &dp){
    //time complexity --- k*n  /top down
if(n == 0){
    return 0;
}

if(dp[n] != -1){
    return dp[n];
}

int result = INT_MAX;
for(int i = 1; i<=k && i<= n; i++){
result = min( result, (arr[n] - arr[n-i])+minEnergy(n-i, arr, k));
}
return dp[n] =  result;
}

void Tabulation(int k, int n, vector<int> arr){
vector<int> dp(n,-1);
dp[0] = 0;
for(int i  = 1; i<n; i++){
    int result = INT_MAX;

    for(int i = 1; i<=k && i<= n;i++){
        result = min(result, abs(arr[n] - arr[n-i]) + dp[n-i]);
    }
    dp[n] = result;
}
}

///more space optimisation//////////
//mai k tK HI JARI HU TOH K TAK KA DATA RAKHU TO


void Optimal(int k, int n, vector<int> &arr){
k = min(k, n-1); // k maximum n-1 tak ja sakta hia

vector<int> dp(k+1);
dp[0] = 0;
//////////1,2,3,4-- k fill up , intiliase k+1 value
for(int i  = 1; i<n; i++){
    int result = INT_MAX;

    for(int i = 1; i<=k && i<n;i++){
        result = min(result, abs(arr[n] - arr[n-i]) + dp[n-i]);
    }
    dp[n] = result;
}

for(int i  = k+1; i<n; i++){
    int result = INT_MAX;

    for(int i = 1; i<=k; i++){
        dp[i-1] = d[i];
    }

    for(int i = 1; i<=k && i<= n;i++){
        result = min(result, abs(arr[n] - arr[n-i]) + dp[k-i]);
    }
    dp[k] = result;
}}


int main() {
    vector<int> arr = {};
    int n = arr.size();
    vector<int> dp(n, -1);
    return 0;
}