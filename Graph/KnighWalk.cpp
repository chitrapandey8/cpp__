#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m){
    return i >=0 && j>=0 && i<n && j<m;
}

int minStep(vector<int> &Knight, vector<int> &Target, int n){

    vector<int> row = {2,2,-2,-2,};


    //base case
    if(Target[0] == Knight[0] && Target[1] == Knight[1]){
        return 0;
    }
queue<pair<int, int>> q;
vector<vector<bool>> chess(n, vector<bool>(n,0));
q.push({Knight[0], Knight[1]});
chess[Knight[0]][Knight[1]] =1;

int step = 0;
while(!q.empty()){
    int count = q.size();
    while(count--){
      int i  = q.front().first;
      int j = q.front().second;
      q.pop();

      for(int k = 0; k<8; k++){
        int new_i = i+row[k];
        int new_j = j+col[k];
        if(valid(new_i, new_j, N) && !chess[new_i][new_j]){
            return step+1;
         }

         chess[new_i][new_j] = 1;
         q.push({new_i, new_j});
      }

    } 
    step++;
}
}



int main() {
    
    return 0;
}