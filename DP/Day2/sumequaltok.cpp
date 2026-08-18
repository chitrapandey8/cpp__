#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;int k; 
    vector<int> arr = {};
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    for(int i = 0; i<n; i++){
        dp[i][0] = 1;
    }
    if(arr[0] < k){  ///row mai index or col mai sum 
        dp[0][arr[0]] = 1;
    }
    for(int  i = 1; i<n; i++){
        for()
    }

    //time - n*k
    //sapce - n*(k+1)   then order of k
    return 0;
}