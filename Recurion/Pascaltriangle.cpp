#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> ans;
    ans.push_back({1});
    ans.push_back({1,1});
     
    for(int i = 2; i < n; i++){
        vector<int> arr(i+1,1);

        for(int j = 1; j<ans[i-1].size(); j++){
            arr[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans.push_back(arr);
    }











    for(vector<int> x: ans){
        for(int a:x){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}