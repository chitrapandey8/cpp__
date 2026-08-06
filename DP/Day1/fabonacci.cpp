#include <bits/stdc++.h>
using namespace std;

int fb(int n, vector<int> dp){ //top down  
 
    if(n<=1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
   return  dp[n] =  fb(n-1, dp) + fb(n-2, dp);
}


int fb2(int n){
    
if(n <= 1){
    return n;
}

 //sabse pehel base case bhaedo phir uski values use karo aage ke bharo
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i<=n; i++){
         dp[i]  = dp[i-2] + dp[i-1];
    }

    for(int x: dp){
        cout<<x<<endl;
    }
    return dp[n];
}

int fb3(int n){
 if(n<= 1){
    return n;
 }

    vector<int> dp(3);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i<=n; i++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[0] + dp[1];
    }
    
    for(int x: dp){
        cout<<x<<" ";
    }
    return dp[n];
}

int main() {
    int n = 5;
    // vector<int> dp(n+1, -1);
    // int ans = fb(n, dp);
    // cout<<ans<<endl;

    fb3(5);
    return 0;
}