#include <bits/stdc++.h>
using namespace std;

//iske usecases- recomdation syatem
//stable marriage problem


bool Bipartite(int node, vector<vector<int>> adj, vector<int> &color){

    for(int i = 0;i < adj[node].size(); i++){
        if(color[adj[node][i]] == -1){ //color nhi milahoga
           color[adj[node][i]] = (color[node]+1)%2;
           if(!Bipartite(adj[node][i], adj, color)){
             return 0;
           }   
        }else{
            ///color mil gaya hoga pehelehi
            if(color[node] == color[adj[node][i]]){
                return 0;
            }
        }
    }
return 1;
}

int main() {
    int v;
    vector<int> color(v, -1);
    color[0] = 0;

    for(int i = 0; i<v; i++){
        if(color[i] == -1){
            color[i] = 0;
            if(!Bipartite(0, adj, color)){
                return 0;
            }
        }
    }
    Bipartite(0, adj, color);

    
    return 0;
}