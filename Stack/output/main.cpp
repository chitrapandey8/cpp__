#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n =  arr.size();
        stack<int> s;
        vector<int> ans(n,0);
        for(int i = n-1; i>=0; i--){
            if(s.empty() || arr[i] == arr[s.top()]){
                ans[i] = 0;
                s.push(i);
            }
            
            while(!s.empty() && arr[i] > arr[s.top()]){
                s.pop();
            }
            
            if(s.empty()){
                ans[i] = 0;
                s.push(i);
            }
            
            if(arr[i] < arr[s.top()]){
                ans[i] = s.top() - i;
                s.push(i);
            } 
        }
        return ans;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr{73,74,75,71,69,72,76,73};
    vector<int> a =  s.dailyTemperatures(arr);
    for(int x:a){
        cout<<x<<" ";
    }
    return 0;
}
