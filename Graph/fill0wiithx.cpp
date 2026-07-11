#include <bits/stdc++.h>
using namespace std;

bool Valid(int i, int j, int r, int c){
    return i>=0 && i<r &&&j>=0 &&j<c;

}

int main() {
    vector<vector<int>> arr; int n = arr.size();
    int r = n;
    int c = n;
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};

    //firs row mai jo bhi 0 hai usko quuee mai dalo hum ismia bfs apply karege
   queue<pair<int, int>> q;
   //first row
   for(int j =0; j<c; j++){
    if(arr[0][j] == '0'){
      q.push({0,j});
      arr[0][j] == 'T';
    }
   }
   //first col
   for(int i = 1; i<r; i++){
    if(arr[i][0] == '0'){
q.push({i,0});
      arr[i][0] == 'T';
    }
   }

  // last row
   for(int j = 1; j<c; j++){
    if(arr[r-1][j] == '0'){ 
q.push({r-1, j});
      arr[r-1][j] == 'T';
    }
   }

   //last col
   for(int i = 1; i<r-1; i++){
    if(arr[i][c-1] == '0'){ 
q.push({i, c-1});
      arr[i][c-1] == 'T';
    }
   }


   while(!q.empty()){
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
   


    for(int k = 0; k <4; k++){
        if(Valid([i+row[k], j+col[k]], r, c) && arr[i+row[k]][j+col[k]] == '0'){
            arr[i+row[k]][j+col[k]] = 'T';
            q.push({i+row[k], j+col[k]});
        }
    }
   }


   ///resplace all "0 " with 'X' and 'T with "0" 

   for(int i = 0; i<r; i++){
    for(int j =0; j<c;j ++){
        if(arr[i][j] == '0'){
            arr[i][j] = 'X';
        }else if(arr[i][j] == 'T'){
    arr[i][j] = '0';
        }
    }
   }
      return 0;
}