#include <bits/stdc++.h>
using namespace std;
//mai call lagati rahugi to the very end phir jab recusion backtrack karega phir mai stack mai push karugi taki mera order maintianrahe 

void listt(vector<vector<int>> &list, int vertex, int edges){
    int u, v;
    for(int i = 0; i<edges; i++){
        cin>>u>>v;

        list[u].push_back(v);
        list[v].push_back(u);
    }
}


void Topological(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s){
    visited[node] = 1;

    for(int j = 0; j <adj[node].size(); j++){
        if(!visited[adj[node][j]]){
            Topological(adj[node][j], adj, visited, s);
            
        }
    }
    s.push(node);

}



int main() {
    vector<vector<int>> adj;
    int vertices, edges;
    cin>>vertices>>edges;
    listt(adj, vertices, edges);

   
    vector<bool> visited(vertices,0);
    stack<int> s;

    for(int i = 0; i<visited.size(); i++){
        if(visited[i]){
            Topological(i, adj, visited, s);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    Topological(0,adj, visited,s);
    return 0;
}