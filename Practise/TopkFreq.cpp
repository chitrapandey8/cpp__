#include <bits/stdc++.h>
using namespace std;

struct func
{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};


int main() {
    vector<int> nums = {1,1,1,2,2,3};
    unordered_map<int, int> mp;
    for(int i = 0; i<nums.size(); i++){
        mp[nums[i]]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int , int>>, func> p;
    for(auto it: mp){
        p.push({it.first, it.second});
    }
  
    vector<int> ans;
    int k = 2;
    while(k--){
      ans.push_back(p.top().first);
      p.pop();
    }  

    for(int x: ans){
        cout<<x<<" ";
    }
    return 0;
}