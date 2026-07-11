#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int r, int c){
    return i>=0 && i<r && j>=0 && j<=c;
}

int main() {
    vector<vector<int>> arr;
    int r = arr.size();
    int c = arr[0].size();

    int row[8] = {-1,-1,-1, 1,1 ,1,0,0};
    int col[8] = {-1,0,1, -1,0,1,-1,1};

    queue<pair<int, int>> q;
    int count = 0;

    for(int i = 0; i<r; i++){
        for(int j = 0;j< c; j++){
            if(arr[i][j] == '1'){
                count++;

                q.push(make_pair(i,j));
                arr[i][j] = '0';

                while(!q.empty()){
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();

                    //jisko quuee se nikalae uske sare direction mai dekho 
                    for(int k = 0; k<8; k++){
                        if(valid(new_i+row[k], new_j+col[k]) && arr[new_i+row[k]][new_j+col[k]] == '1'){
                            arr[new_i+row[k]][new_j+col[k]] = '0';
                            q.push({new_i+row[k], new_j+col[k]});
                        }
                    }
                }
            }
        }
    }
    return 0;
}