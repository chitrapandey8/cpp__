#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr {1,1,3,0,5,8,5};
    vector<int> ans;
    unordered_map<int, int> hm;
    int k = 4;
    for(int i = 0; i<k; i++){
        hm[arr[i]]++;
    }
    
    ans.push_back(hm.size());
    
    int n = arr.size();
    for(int  i = k; i<n; i++){
        if(hm.count(arr[k])){
            hm[arr[i]]++;
        }else{
           hm.insert({arr[i],1});
        }
        


        int outgoingelemet = arr[i-k];
        hm[outgoingelemet]--;

        if(hm[outgoingelemet] == 0){
            hm.erase(outgoingelemet);
        }

        ans.push_back(hm.size());

    }

    for(int x : ans){
        cout<<x<<endl;
    }
  



    return 0;
}
