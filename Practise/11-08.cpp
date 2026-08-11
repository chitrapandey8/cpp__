#include <bits/stdc++.h>
using namespace std;

void QOTD(){

    vector<int> arr = {3,4,5,1,12,14,13};
    int i = 1;
    int sum = arr[0];
    while(i < arr.size() && arr[i] == arr[i-1]+1){
       sum += arr[i];
       i++;
    }
    unordered_set<int> hs;
    for(int x: arr){
        hs.insert(x);
    } 
    while(hs.count(sum)){
        sum++;
    }
    cout<<sum<<endl;
}


int Subsets(vector<int> &arr, int i, int mini, int maxi, int &target, int &n, int &mod){
       if(i == n){
        if( mini != INT_MAX && (mini + maxi) <= target){
            return 1;
        }
        return 0;
       }
    int notincluded = Subsets(arr, i+1, mini, maxi, target, n, mod);
    int included = Subsets(arr, i+1, min(mini, arr[i]), max(maxi, arr[i]), target, n, mod);
    return (notincluded + included)%mod;
}


int main() {
    vector<int> arr = {3,5,6,7};
    int target = 9;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int i = 0;
    int n = arr.size();
    int mod = 1000000007;
    int cnt = Subsets(arr, i, mini, maxi, target, n, mod);
    cout<<cnt<<endl;

    return 0;
}