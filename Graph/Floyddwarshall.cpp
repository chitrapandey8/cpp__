#include <bits/stdc++.h>
using namespace std;

void Floydd(vector<vector<int>> &adj){
   int n = adj.size();
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
          if(adj[i][j] == -1){
            adj[i][j] = INT_MAX;
          }
        }
    }

    ///floyss warshall
    for(int k= 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j =0 ; j<n; j++){
                if(adj[i][k] == INT_MAX || adj[k][j] == INT_MAX){
                    continue;
                }
               adj[i][j] = min(adj[i][j] , adj[i][k]+adj[k][j]);
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
          if(adj[i][j] == INT_MAX){
            adj[i][j] = -1;
          }
        }
    }

    ///time complexity -- O(v^3)
    //space complexity -- O(1)
    //how to detect negative cycle agar matrix ke diagonal mai ek bhi negative aagay toh negative cycle.
    //if i use floydd warshall in dense garph i will get O(v^3)
    ///sparse time will be ElogV , (v^2logV)
}

int main() {

    return 0;
}