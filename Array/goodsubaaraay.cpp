#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr{23,2,4,6,7};
    unordered_map<int, int> mp;
    int n = arr.size();
    int k=6;

    int sum = 0;
    int rem = 0;
    for(int i = 0; i<n; i++){
      sum += arr[i];
      rem = sum%k;


     if(mp.count(rem)){
        if((i-mp[rem]) >= 2){
          cout<<true<<endl;
        }
     }


    mp.insert(rem,i);
    }

    return 0;
}