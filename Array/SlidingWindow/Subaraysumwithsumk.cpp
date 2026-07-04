#include <bits/stdc++.h>
using namespace std;

void Optimal(vector<int> &arr, int k){

    unordered_map<int, int> hm;
    hm[0] = 1;
     int sum = 0;
     int ans= 0;
    for(int i = 0;i<arr.size(); i++){
      sum += arr[i];
    
      if(hm.count(sum-k)){
         ans += hm[sum-k];
      }
      hm[sum]++;
    }
    cout<<ans<<endl;

}

int main() {
    vector<int> arr = {2,1,7,-4,2,1,3,4,-15,2,-3,6};
    Optimal(arr,6);

    return 0;
}