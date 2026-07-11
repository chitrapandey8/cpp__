#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<pair<int, int>>> &adj, stack<int> &s, vector<bool> &visited){

    visited[node] =  1;

    for(int j = 0; j < adj[node].size(); j++){
        if(!visited[adj[node][j]]){
            DFS(adj[node][j].first, adj, s, visited); //first negibour node batara hai
        }
    }
}

void ShorthestPath(int N, int M, vector<vector<int>> &edges){
//create adhjency list create

///adjcency list
vector<vector<pair<int, int>>> list(N);

for(int i =0; i<M; i++){
    int u = edges[i][0];
    int v = edges[i][1];
    int weight  = edges[i][2];
    list[u].push_back({v, weight});
}

////topologival sort
stack<int> s;
vector<bool> visited(N);
DFS(0, list, s, visited);

vector<int> dist(N, INT_MAX);
dist[0] = 0;

///stack empthy
while(!s.empty()){
int node = s.top();
s.pop();

//look at the negioubuures
for(int j = 0; j<list[node].size(); j++){
    int neigbour =  list[node][j].first;
    int weight = list[node][j].second;
    dist[neigbour] = min(dist[neigbour], weight+dist[node]);
}


}


for(int i = 0; i<N; i++){
    if(dist[i] == INT_MAX){
        dist[i] = -1;
    }
}

//time complexity = O(v+e);
//space = O(v+e) = adjlist


}


void PahtBatao(vector<vector<pair<int, int>>> list,int N, int M,  int src, int dist){

vector<vector<int>> aadj(N);

for(int i = 0; i<list.size(); i++){ ///edges
aadj[list[i].first-1].push_back(list[i].second-1);
aadj[list[i].second-1].push_back(list[i][0]);
}

///arrasy dist

vector<int> dist(N,-1);
vector<bool> visited(N,0);

queue<int> q;
q.push(src);
visited[src] = 1;
dist[src] = 0;
vector<int> parent(N,-1);

while (!q.empty())
{
  int node  = q.front();
  q.pop();

  for(int i = 0; i<aadj[node].size(); i++){
    if(visited[aadj[node][i]]){
        continue;
    }

    visited[aadj[node][i]] = 1;
    q.push(aadj[node][i]); 
    parent[adj[node][i]] = node;
  }
}

vector<int> path;

while(dest != -1){
path.push_back(dest+1);
dest = parent[dest];
}

//reverse
 
}




void SP(vector<vector<int>> &list, int N,int src ){

///adjajendy list creation

vector<vector<int>> aadj;

for(int i = 0; i<list.size(); i++){ ///edges
aadj[list[i][0]].push_back(list[i][1]);
aadj[list[i][1]].push_back(list[i][0]);
}

///arrasy dist

vector<int> dist(N,-1);
vector<bool> visited(N,0);

queue<int> q;
q.push(src);
visited[src] = 1;
dist[src] = 0;

while (!q.empty())
{
  int node  = q.front();
  q.pop();

  for(int i = 0; i<aadj[node].size(); i++){
    if(visited[aadj[node][i]]){
        continue;
    }

    visited[aadj[node][i]] = 1;
    q.push(aadj[node][i]);
    dist[aadj[node][i]] = dist[node]+1;
  }
}



 
}

int main() {


    return 0;
}