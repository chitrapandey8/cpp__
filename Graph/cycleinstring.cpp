#include <bits/stdc++.h>
using namespace std;

void DFS(int n, vector<vector<int>> &Adj, vector<bool> &visited){
    visited[node] =1 ;
    for(int j = 0; j< adj[node].size(); j++){
        if(!visited[adj[node][j]]){
            DFS(adj[node][j], adj, visited);
        }
    }
}

int Find(int N, vector<string> A){
    //eges create karna
    vector<int> adj(26);
    vector<int> Indegree(26,0);
    vector<int> OutDegree(26,0);
    
    for(int i =0; i<N; i++){
        string temp = A[i];
        int u = temp[0] -'a';
        int v = temp[temp.size()-1] - 'a';
        adj[u].push_back(v);
        OutDegree[u]++;
        Indegree[v]++;
    }

//eucelrian circuti 
    for(int i = 0; i<26; i++){
        if(Indegree[i] != OutDegree[i]){
            return 0;
        }
    }
    
    vector<int> visited(26,0);
    itn node = A[0][0] -'a';
    DFS(node, adj, visited);

    for(int i = 0; i<26; i++){
        //unko dekho ingree out drfee ai but visited ni hai
        if(Indegree[i] && !visited[i]){
            return 0;
        }
    }
}

int main() {

    return 0;
}