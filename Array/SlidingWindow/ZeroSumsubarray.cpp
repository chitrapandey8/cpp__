#include <bits/stdc++.h>
using namespace std;
///brute force1 n^3
///brute force2 n^2
///prefix sum

void Prefixsum(vector<int> &arr){\

unordered_map<int, int> hm;
hm[0] = 1;
int ans = 0;
int  prefix = 0;
for(int i = 0; i<arr.size(); i++){
    prefix += arr[i];
     if(hm.count(prefix)){
        ans += hm[prefix];
     }
    
     hm[prefix]++;
     
     
}
cout<<ans<<endl;
}

int main() {
    ////kitne 
    vector<int> arr = {6,4,-5,1,8,3,2,10,-4,0,4,-9};
    Prefixsum(arr);


    return 0;
}