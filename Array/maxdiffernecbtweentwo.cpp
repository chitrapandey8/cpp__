#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr{9,5,8,12, 2, 3, 7, 4};
     int n = arr.size();
    // vector<int> suffix(n,0);
    // suffix[n-1] = 0;
    // for(int i = n-2;  i >=0 ; i--){
    //  suffix[i] = max(arr[i+1] , suffix[i+1]);
    // }

    // int maxdiff = INT_MIN;
    // for(int i  = 0; i<n; i++){
    //    maxdiff = max(suffix[i] - arr[i], maxdiff);
    // }
    //  cout<<maxdiff;

    int maxright  = arr[n-1];
    int maxdiff = INT_MIN;
    for(int i = n-2; i >= 0 ; i--){
         maxdiff = max(maxdiff, maxright - arr[i]);
         if(arr[i] > maxright){
            maxright = arr[i];
         }
    }
    cout<<maxdiff;
    return 0;
}