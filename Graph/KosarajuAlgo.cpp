#include <bits/stdc++.h>
using namespace std;

void TopoLogical(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> s){
visited[node]  = 1;
for(int i = 0; i<adj[node].size(); i++){
    if(!visited[adj][node][j]){
        TopoLogical(adj[node][j], adj,visited, s);
    }
}
s.push(node);
}

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited){
visited[node] = 1;

for(int i = 0; i<adj[node].size(); i++){
    if(visited[adj[node]][i]){
        DFS(adj[node][i], adj, visited);
    }
}
}

int Kosaraju(int v, vector<vector<int>> &adj){
    /////////topological sort
    stack<int> s;
    vector<bool> visited( v,0);
    for(int i =0; i<v; i++){
        if(!visited[i]){
        TopoLogical(i, adj, visited, s);
    }}
    //reverse the eges

    vector<vector<int>> adj2(v);
    for(int i = 0; i<v; i++){
        for(int j = 0; j<adj[i].size(); j++){
            int u = i;
            int v = adj[i][j];
            adj2[v].push_back(u);
        }
    }

    for(int i = 0; i<v; i++){
 visited[i] = 0;
    }

    int scC = 0;
    while (!s.empty())
    {
      int node = s.top();
      s.pop();
      if(!visited[node]){
        scC++;
        DFS(node, adj2, visited);
      }
    }
    
}

int main() {
    return 0;
}