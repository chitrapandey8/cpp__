#include <bits/stdc++.h>
using namespace std;
//mai call lagati rahugi to the very end phir jab recusion backtrack karega phir mai stack mai push karugi taki mera order maintianrahe 

void listt(vector<vector<int>> &list, int vertex, int edges){
    int u, v;
    for(int i = 0; i<edges; i++){
        cin>>u>>v;

        list[u].push_back(v);
        
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


void KahnAlgorithm(vector<vector<int>> &adj, vector<int> &Indegree, vector<int> &ans){
///hum usko queue mai dalte hai jiski indegree 0 hoti hai uske mtlb ye hai i agar uski indgree -0 hai toh voh kispe pe depeent nhi hai mai usse pehele rak sakti hu bakiyo se 
queue<int> q;
for(int i = 0;i <Indegree.size(); i++){
    if(Indegree[i] == 0){
        q.push(i);
    }
}

 while(!q.empty()){
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for(int i = 0; i<adj[node].size(); i++){
        Indegree[adj[node][i]]--;
        if(Indegree[adj[node][i]] == 0){
            q.push(adj[node][i]);
        }
    }
 }

}

int main() {
    int vertices, edges;
    cin>>vertices>>edges;
    vector<vector<int>> adj(vertices);
    listt(adj, vertices, edges);

   
    // vector<bool> visited(vertices,0);
    // stack<int> s;

    // for(int i = 0; i<visited.size(); i++){
    //     if(visited[i] == 0){
    //         Topological(i, adj, visited, s);
    //     }
    // }

    vector<int> ans;
    // while(!s.empty()){
    //     ans.push_back(s.top());
    //     s.pop();
    // }

    // Topological(0,adj, visited,s);



 ///////////////kahn Algorithm//////////////
 vector<int> Indegree(adj.size());
 for(int i =0; i<adj.size(); i++){
     for(int j = 0; j<adj[i].size(); j++){
        Indegree[adj[i][j]]++;
     }
 }

 for(int x: Indegree){
    cout<<x<<" ";
 }

cout<<endl;

 KahnAlgorithm(adj, Indegree, ans);

    for(int x: ans){
        cout<<x<<" ";
    }
    return 0;
}