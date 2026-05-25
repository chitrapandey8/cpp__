#include <bits/stdc++.h>
using namespace std;

void waveform(vector<vector<int>> arr){
vector<int> ans;
for(int j = 0; j< arr[0].size(); j++){
  if(j%2 == 0){
    for(int i = 0; i<arr.size(); i++){
        ans.push_back(arr[i][j]);
    }
  }else{
    
        for(int i = arr.size()-1; i>= 0; i--){
            ans.push_back(arr[i][j]);
                }
  }
  }
  for(int x: ans){
    cout<<x<<" ";
  }

}


int main() {
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    waveform(arr);
    
    return 0;
}