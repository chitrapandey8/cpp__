#include <bits/stdc++.h>
using namespace std;

void listt(vector<vector<int>> &list, int vertex, int edges){
    int u, v;
    for(int i = 0; i<edges; i++){
        cin>>u>>v;

        list[u].push_back(v);
        list[v].push_back(u);
    }
}


bool BFS(vector<vector<int>> &list, vector<bool> &visited){
queue<pair<int, int>> q;
visited[0] = 1;
q.push({0,-1});

int node, parent;
while(!q.empty()){
    node = q.front().first;
    parent = q.front().second;
    q.pop();
    for(int i = 0; i<list[node].size(); i++){
        /////check karo ki parent hi negboiur node hai toh
        if(parent = list[node][i]){
            continue;
        }

        //agr voh already visited hai toh mtlb kisi or node se visite ho chuka hai dubbhara agar visit horra hai toh, mtlb cycle hia
        if(visited[list[node][i]] == 1){ //if any node comes viivted what does it tell me it tells me that i ahve already vivited this node thorugh some other path, if i have already reached a node through some other part already, and to differrnt routes to the same room create a loop.
            return 1;
        }

        visited[list[node][i]] = 1;
        q.push({list[node][i], node});
    }
}
return 0;
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
    for(int i = 0; i<visited.size(); i++){
        if(!visited[i] && BFS(list, visited)){
            cout<<"True";
            return 1;
        }
    }


    cout<<"NOt true";
    return 0;
}