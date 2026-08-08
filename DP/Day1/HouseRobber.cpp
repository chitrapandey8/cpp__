#include <bits/stdc++.h>
using namespace std;

int HouseRobber(int n,vector<int> arr){

   if(n <= 0){
     return arr[0];
   }

   if(n == 1){
    return max(arr[0], arr[1]);
   }

   return max(arr[n], HouseRobber(n-2, arr), HouseRobber(n-1, nums));
   ////////time complexity -- 2^n coz we have two options churana ya na churanaa.
}
int HouseRobber(int n,vector<int> arr, vector<int> &dp){ //top down

   if(n <= 0){
     return arr[0];
   }

   if(n == 1){
    return max(arr[0], arr[1]);
   }
   if(dp[n] != -1){
    return dp[n];
   }

   return   dp[n] =  max(arr[n]+HouseRobber(n-2, arr), HouseRobber(n-1, nums));
}

///bottho up
int rob(vector<int> &nums, vector<int> &dp){
   //dp n size ki banehgi
   if(n  == 1){
     return arr[0];
   }

   if(n == 2){ //n size hai
    return max(arr[0], arr[1]);}
    dp[0] = 0;
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i<nums.size(); i++){

        dp[i] = max(nums[i]+ dp[n-2], dp[n-1, nums]);
    }
}
int rob(vector<int> &nums, vector<int> &dp){
   //dp n size ki banehgi
   if(n  == 1){
     return arr[0];
   }

   if(n == 2){ //n size hai
    return max(arr[0], arr[1]);}
    dp[1] = 0;
    dp[2] = max(nums[0], nums[1]);

    for(int i = 2; i<nums.size(); i++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = max(nums[i]+ dp[0], dp[1]);
    }
        
}


////////////////////House Robber2///////////////////
//ppehele ghar se le liya toh last se nhi le  sakti aararay circular hai
int rob22(){
    int n  =nums.size();
    if(n == 1){return nums[0];}

    if(n == 2){
        return max(nums[0], nums[1]);
    }

    vector<int> dp(3, 0);
    d[1] = nums[0];
    dp[2] = max(nums[0], nums[1]);
    for(int i =2; i<n-1; i++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = max(nums[i]+dp[0], dp[1]);   //////////////0 to n-2;
    }

    int resilt = dp[2];
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for(int i = 3; i<n; i++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = max(nums[i]+dp[0], dp[1]);
    }

    resilt = max(resilt, dp[2]);
    return resilt;
}

int main() {
    vector<int> arr; int n = arr.size();
    HouseRobber(n-1, arr);
    return 0;
}