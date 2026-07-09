#include <bits/stdc++.h>
using namespace std;
//Time - O(V+E)
//space - O(V)
bool DetectCycle(int node, vector<vector<int>> adj, vector<bool> &path, vector<bool> &visited){
    visited[node] = 1;
path[node] = 1;

//look at ajacent node
for(int i =0; i<adj[node].size(); i++){
    if(path[adj[node][i]]){
        return 1; //cycle present hai
    }
   
     if(visited[adj[node][i]]){
        continue; //agar neigbour already visited hai toh mtln already explored hai toh usse visite mt karo
     }

    if (DetectCycle(adj[node][i], adj, path, visited)){
        return 1;
    }

}
path[node] = 0;
return 0;

}

bool isCyclic(){

}

int main() {
    vector<bool> path(v, 0);
    vector<bool> visited(v,0);

    for(int i= 0; i<visited.size(); i++){
        if(!visited[i] && DetectCycle(0, adj, path, visited)){
            return 1;
        }
    }

    //else return 0;


    return 0;
}