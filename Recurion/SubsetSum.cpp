#include <bits/stdc++.h>
using namespace std;


void Generatesum(vector<int> arr, int index, int sum, vector<int> &ans, vector<vector<int>> &anssubset, vector<int> temp){

    if(index == arr.size()){
      ans.push_back(sum);
      anssubset.push_back(temp);
      return;
    }


    /// add the element to the sum
    sum += arr[index];
    temp.push_back(arr[index]);
    Generatesum(arr, index+1, sum, ans,anssubset, temp);

    ///dont include to the
    temp.pop_back();
    sum -= arr[index];
    Generatesum(arr, index+1, sum, ans, anssubset,  temp);
}





int main() {
    vector<int> arr = {3,4,5};
    vector<int> ans;
    int sum = 0;
    vector<vector<int>> anss;
    vector<int> temp;
    Generatesum(arr, 0, sum, ans, anss, temp);
     
    for(vector<int> xx: anss){
        for(int a:xx){
            cout<<a<<" ";
        }
        cout<<endl;
    }


    for(int x: ans){
        cout<<x<<" ";
    }


    

    return 0;
}