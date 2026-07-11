#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int r, int c){
    i>=0 && i <r && j>=0 && j<c;}

int main() {
    vector<vector<int>> arr;
    int r = arr.size();
    int c = arr[0].size();

    queue<pair<int, int>> q;
    for(int i =0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(arr[i][j] == 2){
                q.push({i,j});
            }
        }
    }

    int timer = 0;
    while(!q.empty()){
        timer++;
        int curr_pat = q.size();
        while (curr_pat--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
           

            int row[4] = {-1,1,0,0};
            int col[4] = {0,0,-1,1};
            //check in up
             
            for(int  k = 0; k<4; k++){
                if(valid(i+row[k], j+col[k], r, c)&&arr[i+row[k]][j+col[k]] == 1){
                arr[i+row[k]][j+col[k]] == 2;
                q.push({i+row[k], j+col[k]});
                }
            }
        
        }
            
    }

    for(int i = 0; i<r; i++){
        for(int j = 0; j<arr[0].size(); j++){
            if(arr[i][j] ==1 ){
                return -1;
            }
        }
    }

    cout<<timer-1<<endl;
    //time - O(m*n)
    //space - O(m*n)
    return 0;
}