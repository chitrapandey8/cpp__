#include <bits/stdc++.h>
using namespace std;

int main() {
vector<int> arr = {};
    unordered_map<int, int> hm;
    int k = 7;

    int sum = 0;
    int rem = 0;
    int ans =0;
    for(int i= 0;i < arr.size(); i++){
        sum += arr[i];
        rem = sum%k;
        
        if(rem<0){
            rem = k+rem;
        }

        if(hm.count(rem)){
            ans += hm[rem];
            hm[rem]++;
        }else{
            hm[rem] = 1;
        }
          
    }

    return 0;
}