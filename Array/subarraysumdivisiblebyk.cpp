#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr{4,5,0,-2,-3,1};
    int k = 5;
    int count  = 0;
    unordered_map<int, int>mp;
    mp[0] = 1;
    int sum = 0;
    for(int x: arr){
       sum += x;
       int rem = sum%k;
       if( rem<0){rem = rem+k;
    }

       
        
        if(mp.count(rem)){
            count += mp[rem];
        }
         mp[rem]++;

       
    }
    cout<<count<<endl;
    return 0;
}