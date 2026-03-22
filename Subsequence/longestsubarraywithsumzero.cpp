#include <bits/stdc++.h>
using namespace std;

int main() {


    vector<int> arr{6,1,2,-3,-4,4,8};
    unordered_map<int, int> hm;
    hm[0] = -1;

    int sum = 0;
    int maxlen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
       sum += arr[i];

       if(hm.count(sum)){
         if(i-hm[sum] > maxlen){
            maxlen = i - hm[sum];
         }
       }
       
       hm.insert({sum,i});
       
    }

    cout<<maxlen<<endl;
    
    return 0;
}