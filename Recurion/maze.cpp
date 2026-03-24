#include <bits/stdc++.h>
using namespace std;

int fnnk(vector<vector<int>> nums, int i, int j){
    if( i>= 0 && j>= 0 && nums[i][j] == -1){
        return 0;
    }
    
    if( i < 0 ||  j < 0){
      return 0;
    }

    if(i == 0 || j == 0){
        return 1;
    }

    return fnnk(nums,i-1,j) + fnnk(nums, i, j-1);
}

int fnn(int i, int j){
    if( i == 0 || j == 0){
      return 1;
    }

    if( i == -1 || j == -1){
        return 0;
    }

    return fnn(i-1, j) + fnn(j, i-1);
}

int main() {
    
    vector<vector<int>> arr {{1,1,1},{1,1,-1},{1,1,1}};
    cout<<fnnk(arr,2,2);
    return 0;
}