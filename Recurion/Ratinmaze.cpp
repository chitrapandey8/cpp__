#include <bits/stdc++.h>
using namespace std;

int  isPossible(int i, int j, int n){
 if(i < n && i >= 0 && j <n && j>= 0){
    return 1;
 } 
 return 0;

}



void Ratmaze(vector<vector<int>> arr,int n, int i, int j, string path, vector<vector<int>> &visited, vector<string> &ans){
  ////Base Condition:
  if(i == n-1 && j == n-1){
    ans.push_back(path);
    return;
  }


    vector<int> row = {1,0,0,-1};
    vector<int> col = {0,-1,1,0};

    string dir = "DLRU";
   
  //mai current cell ko visite kiya toh ussee 1 mark kardo
  visited[i][j] = 1;
 

  for(int k = 0;k <4; k++){
    if((isPossible(i+row[k], j+col[k],n)) && arr[i+row[k]][j+col[k]] && !visited[i+row[k]][j+col[k]]){
     path += dir[k];
     Ratmaze(arr, n, i+row[k], j+col[k], path, visited, ans);
     path.pop_back();
    }
  }
  visited[i][j] = 0; ///sari possible direction try karne ke baad usko wapas zero kardo
}


int main() {
    vector<vector<int>> arr = {{1,1,1,0,1}, {1,0,1,1,1},{0,0,1,1,1},{1,0,0,1,1},{1,0,0,0,1}};
    int n = 5;
    string path = "";
    vector<string> ans;
    vector<vector<int>> visited = {{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0},{0,0,0,0,0}};
    
     Ratmaze(arr, n, 0,0,path, visited, ans);

    for(string a: ans){
        cout<<a<<endl;
    }
     
    return 0;
}