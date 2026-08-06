#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr= {1,1,1,1,1}; int  k = 10;
    int l = 0;
    int r = 0;
    int n = arr.size();
    int cnt = 0;
    int numofsumarrays = 0;
    unordered_map<int, int> mp;
    while(r < n){

        if(mp[arr[r]] >= 1){
            cnt += mp[arr[r]];
        }
        mp[arr[r]]++;
       while(cnt >= k){
           numofsumarrays += n-r; 
           mp[arr[l]]--;
           cnt -= mp[arr[l]];
           l++;
       }
       
       r++;

    }
    cout<<numofsumarrays<<endl;
    return 0;
}