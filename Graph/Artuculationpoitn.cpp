#include <bits/stdc++.h>
using namespace std;

void DFS(int node, int parent, vector<vector<int>> adj, vector<bool> visited,vector<int> disc, vector<int> low, int timer){
visited[node] = 1;
disc[node] = low[node] = timer;


for(int j = 0; j<adj[node].size(); j++){
    int neib = adj[node][j];
    if(neib == parent){
        continue;
    }else if(visited[neib]){
          low[node] = min(low[node], disc[neib]);
    }else{
        child++;
        timer++;
        DFS(neib, node, adj, visited, disc, low, artpoint, timer);
        if(disc[node] <= low[neib] && parent != -1){
            artpoint[node] = 1;
        }
        low[node] = min(low[node], low[neib]);
    }
}

if(child > 1 && parent == -1){
    ///rott node condotion
    artpoint[node] =1;
}
}

int main() {
    int v;
    vector<bool> artpoint(v,0);
    vector<int> disc(v);
    vector<int> low(v);
    vector<bool> visited(v, 0);
    int timer = 0;
    DFS(0,-1,adj, visited, disc, low, artpoint, timer);

    vector<int> ans;
    for(int i = 0; i<v; i++){
        if(artpoint[i]){
            ans.push_back(i);
        }
    }

    if(ans.size() == 0){
        ans.push_back(-1);
    }
    return 0;
}