#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {6,7,8,9};

    int max = 2048;
    vector<int> pairsab(max, 0);
    vector<int> ans(max, 0);

    for(int i = 0; i<arr.size(); i++){
        for(int j =0; j<arr.size(); j++){
            pairsab[arr[i]^arr[j]] =1;
        }
    }
    
   for(int i = 0; i<max; i++){
    if(pairsab[i]){
        for(int x: arr){
            ans[i^x] = 1;
        }
    }
   }

     int totalcnt = 0;
   for(int x: ans){
    if(x){
      totalcnt++;
    }
   }
   cout<<totalcnt<<endl;
    return 0;
}