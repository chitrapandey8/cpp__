#include <bits/stdc++.h>
using namespace std;
///time - O(v+2E)  
//space - queue O(v+e) v is v=vertices here 

void listt(vector<vector<int>> &list, int vertex, int edges){
    int u, v;
    for(int i = 0; i<edges; i++){
        cin>>u>>v;

        list[u].push_back(v);
        list[v].push_back(u);
    }
}

// void BFS(int v, vector<vector<int>> adj, vector<int> &ans){
//     queue<int> q;
//     vector<bool> visited(v,0);
//     q.push(0);
//     visited[0] = 1;
    
//     int node;
//     while(!q.empty()){
//         ///first nikalo
//        node =  q.front();
//        q.pop();
//        ans.push_back(node);
//        for(int j = 0; j<adj[node].size(); j++){
//           if(!visited[adj[node][j]]){
//               visited[adj[node][j]] = 1;
//               q.push(adj[node][j]);
//           }
//        }}
// }


////////////////BFS//hum sabse pehele intial node ko dalte hai, har front wale node ki sare nebours ko mai visite kareugi ek baar only toh uske liye mai visited array rakhugi agar visit hua hoga toh visite nhi karugi, ph

// void BFS(int v, vector<vector<int>> list, vector<int> &ans){
//     queue<int> q;
//     vector<bool> visited(v,0);
//     q.push(0);
//     visited[0] = 1;

//     int node;
//     while(!q.empty()){
//         node = q.front();
//         q.pop();
//         ans.push_back(node);
//         for(int i =0; i<list[node].size(); i++){
//             if(!visited[list[node][i]]){
//                 visited[list[node][i]] = 1;
//                 q.push(list[node][i]);
//             }
//         }
//     }
    
    
// }

void BFS(vector<vector<int>> &list, vector<int> &ans, vector<bool> &visited){
//bfs mai pehele starting node leti hu phir uske sare edges ko explore karke 
queue<int> q;
q.push(5);
visited[5] = 1;

int node;
while(!q.empty()){
    node = q.front();
    q.pop();
    ans.push_back(node);
    for(int i = 0; i<list[node].size(); i++){
        if(visited[list[node][i]] == 0){
            visited[list[node][i]] = 1;
            q.push(list[node][i]);
        }
    }
}
}

int main() {
    int vertex, edges;
    cin>>vertex>>edges;
    vector<vector<int>> list(vertex);
    listt(list, vertex, edges);


    for(int i = 0; i<list.size(); i++){
        cout<<i<<"->";
        for(int j = 0; j<list[i].size(); j++){
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<bool> visited(vertex);
    vector<int> ans;
    BFS(list, ans, visited);

    

    for(int x: ans){
        cout<<x<<" ";
    }


    return 0;
}