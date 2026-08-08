#include <bits/stdc++.h>
using namespace std;

///recursion//
// int solve(int n){
//     if(n <= 2){
//         return n;
//     }
//     return solve(n-2) + solve(n-1);
// }

// int Climinin(int n){
// vector<int> dp(n+1, -1);
// dp[0]  = 0;
// dp[1] = 1;
// dp[2] = 2;
// for(int i = 3; i<=n; i++){
//     dp[i] = dp[i-2] + dp[i-1];
// }

// return dp[n];
// }

// //////////////[10, 15, 20]/////////
// int mincost(vector<int> &cost, int n){

// }



int mincost(vector<int> cost, int n){
    if(n <= 1){
        return 0;
    }
  
    return  min(cost[n-1] + mincost(cost, n-1), cost[n-2] + mincost(cost, n-2));
}

// int mincost(vector<int> cost, int n, vector<int> &dp){
//     if(n <= 1){
//         return 0;
//     }

//     if(dp[n] != -1){
//         return dp[n];
//     }
//     return dp[n]  =   min(cost[n-1] + mincost(cost, n-1, dp), cost[n-2] + mincost(cost, n-2,dp));
// }

// int mincost(vector<int> cost, int n, vector<int> &dp){
//     if(n <= 1){
//         return 0;
//     }

//     if(dp[n] != -1){
//         return dp[n];
//     }
//     return dp[n]  =   min(cost[n-1] + mincost(cost, n-1, dp), cost[n-2] + mincost(cost, n-2,dp));
// }



int main() {
    // int ans = Climinin(3);
    // cout<<ans<<endl;
    // vector<int> dp(n+1);
    // dp[0] = 0;
    // dp[1] = 1;
    // for(int  i = 2;  i<dp.size(); i++){
    //      dp[i]  =   min(cost[i-1] + dp[i-1], cost[n-2] +  d[n-2]);
    //  }
    
    int arr[] = {1,2,3,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 100;
    int target = 2;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == target){
            cnt++;
        }
    }
    int arr2[n+cnt];
    int j = 0;
    for(int i = 0; i<n; i++){
         if(arr[i] != target){
          arr2[j++] = arr[i];
         }else{
           arr2[j++] = arr[i];
           arr2[j++] = x;
         }
    }
    n = n+cnt;
    for(int i = 0; i<n; i++){
        cout<<arr2[i]<<" ";
    }
    
    
    
     return 0;
}

