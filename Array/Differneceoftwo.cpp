#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> num = {9,5,8,12,2,3,7,4};
    int n = num.size();
    vector<int> presum(n,0);
    presum[n-1] = num[n-1];
    for(int i = n-2; i>=0; i--){
       presum[i] = max(num[i], presum[i+1]);
    }

    for(int i = 0; i< n; i++){
        cout<<presum[i]<<" ";
    }
    
     
    int ans = INT_MIN;

    for(int i = 0; i<n;i++){
     ans = max(ans, presum[i] - num[i]);
    }
     cout<<ans<<endl;

    return 0;
}