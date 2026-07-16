#include <bits/stdc++.h>
using namespace std;
bool valid(){

}

int Code(int n, int m , vector<vector<int>> A, int x, int y){
//time - O(n*m)
//space - O(min(n,m)) --min oath ya min step -- bsf would be better
   if(x == 0 && y ==0 ){
    return 0;
   }

   if(!A[0][0]){
    return -1;
   }

    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    //row, col , step
    queue<pair<int, pair<int, int>>> q;
    q.push({0,{0,0}});
    vector<vector<bool>> visited(n, vector<bool>(m,0));
    visited[0][0] = 1;

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second.first;
        int step = q.front().second.second;
        q.pop();

        ///up down left right
        for(int k = 0; k<4;k++){
            int new_i = i+row[k];
            int new_j = j+col[k];
            if(valid(new_i, new_j, n, m) && A[new_i][new_j] & !visited[new_i][new_j]){
                if(new_i == x && newj == y){
                    cout<<"FOUNT"<<endl;
                    cout<<"step+1";
                }
                visited[new_i][new_j] = 1;
                q.push(new_i, {new_j, step+1});
            }

        }
    }
}

int main() {
    return 0;
}