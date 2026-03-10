#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
      

    // for(int i = 0; i<arr.size(); i++){
    //     bool flag = false;
    //     for(int j = i+1; j<arr.size(); j++){
    //         if(arr[i] == arr[j]){
    //             flag = true;
    //             cout<<i<<endl;
    //             break;
    //         }

    //     }
    //     if(flag){
    //         break;
    //     }
    // }

    // vector<int> arr{3,2,1,5,2,6,8,3,8};
    // unordered_map<int, int> mp;
    // for(int x :arr){
    //     mp[x]++;
    // }

    // // for(auto i = mp.begin(); i != mp.end(); i++){
       
    // // }
    // for(int i = 0; i<arr.size(); i++){
    //     if(mp[arr[i]]  == 2){
    //         cout<<arr[i]<<endl;
    //         break;
    //     }
    // }

    vector<int> nums{6,6,1,3,4,4,3};
    unordered_set<int> s(nums.begin(),nums.end());
    cout<<s.size()<<endl;
    

    return 0;
}
