#include <bits/stdc++.h>
using namespace std;

void Subseq(vector<int> arr, int index, int n, vector<vector<int>> &ans, vector<int> &temp){
    if(index == n){
        ans.push_back(temp);
        return;
    }
    ///yes
    
      temp.push_back(arr[index]);
      Subseq(arr, index+1, n, ans, temp);
    ///No
    temp.pop_back();
    Subseq(arr,index+1, n, ans, temp);
       
}

void SubString(string arr, int index, int n, vector<string> &ans,  string &temp){
    if(index == n){
        ans.push_back(temp);
        return;
    }
    ///yes
    
      temp.push_back(arr[index]);
      SubString(arr, index+1, n, ans, temp);
    ///No
    temp.pop_back();
    SubString(arr,index+1, n, ans, temp);
       
}

int main() {
    // vector<int> arr = {1,2, 3};
    string arr = "abc";
    int n = arr.size();
    // vector<vector<int>> ans;
    vector<string> ans;
    // vector<int> temp;
    string temp = "";
    SubString(arr, 0, n, ans, temp);


    //print ans:
    // for(int i = 0; i< ans.size(); i++){
    //     for(int j = 0; j<ans[i].size(); j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

  for(int i = 0 ;i <ans.size(); i++){
    cout<<ans[i]<<endl;
  }

    return 0;
}