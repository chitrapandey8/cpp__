#include <bits/stdc++.h>
using namespace std;

bool DetedctCycle(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited){
    visited[node] = 1;

    for(int j =0; j<adj[node].size(); j++){
        if(parent == adj[node][j]){ //agar neighbour parent hai toh ignore krdo jaruri nhi cucle ho
            continue;
        }
        if(visited[adj[node][j]] == 1){ ///negibour already visited hai toh return 1;
            return 1;
        }
        if(DetedctCycle(adj[node][j], node, adj, visited)){
            return 1; ///agar negibour visited nhi hai toh visite karo
        }
    }
    return 0;       

}

int main() {
    vector<bool> visited(v,0);
    //visite unvisited nodes
    for(int i = 0; i<v; i++){ // sab unvisited pe check karega 
        if(!visited[i] &&  DetedctCycle(i, -1, adj, visited)) {
            return 1;
        }
    }
    ///return 0; 
     
    return 0;
}