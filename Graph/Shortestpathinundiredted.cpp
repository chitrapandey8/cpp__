#include <bits/stdc++.h>
using namespace std;


void Path(int v, int m, vector<vector<vector<int, int>>> &edges){
///create adjaceny list
vector<pair<int, int>> adj(v+1);
for(int i = 0; i<m; i++){
    int u = edges[i][0];
    int v=  edges[i][1];

    int weight = edges[i][2];
    adj[u].push_back(v, weight);
    adj[v].push_back(u, weight);
}


///dijidtra
vector<bool> Explored(v+1, 0);
vector<int> dist(v+1, INT_MAX);


vector<int> parent(v+1, -1);

priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> q;
q.push({0,-1});
dist[1] = 0;

while(!q.empty()){
    int node = q.top().second;
    q.pop();

    if(Explored[node]){
        continue;
    }

    Explored[node] = 1;

    for(int j= 0; j<adj[node].size(); j++){
        int negibour = adj[node][j].first;
        int weight = adj[node][j].second;

        if(!Explored[negibour] && dist[node] + weight < dist[negibour]){
            dist[negibour] = dist[node] + weight;
            q.push({dist[negibour], negibour});
            parent[negibour] =node;

        }
    }
}


///i reah my destianation
vector<int> path;
if(parent[v] == -1){
    path.push_back(-1);
    return path;
}

int dest = v;
while(dest != -1){
    path.push_back(dest);
    dest = parent[dest];

}
path.push_back(dist[v]);
reverse(path.begin(), path.end());
//return apth;

 }

int main() {
    return 0;
}