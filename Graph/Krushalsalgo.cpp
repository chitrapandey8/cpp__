#include <bits/stdc++.h>
using namespace std;

int FindParent(int u, vector<int> &Parent){
    if(u == Parent[u]){
       return u;
    }

    return Parent[u] = FindParent(Parent[u], Parent);
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank){
int Pu = FindParent(u, parent);
int Pv = FindParent(v, parent);

if(rank[Pu] > rank[Pv]){
    parent[Pv] = Pu;
}else if(rank[Pu] < rank[Pv]){
     parent[Pu] = Pv;
}else{
    parent[Pv] = Pu;
    rank[Pu]++;
}

}

int SpanningTree(int v, vector<vector<vector<int>>> adj){

vector<int> parent(v);
vector<int> rank(v,0);
for(int i = 0;i<v;i ++){
    parent[i] = i;
}


vector<pair<int, pair<int, int>>> temp;
for(int i =0; i<v; i++){
    for(int j =0; j<adj[i].size(); j++){
        temp.push_back({adj[i][j][1], {i, adj[i][j][0]}});

    }
}

//Priority queue
//wt, u, v
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q(temp.begin(), temp.end()); //heap mai convert karde arry ko

for(int i = 0;i<v; i++){
    for(int j =0; j<adj[i].size(); j++){
        q.push({adj[i][j][1], {i, adj[i][j][0]}});
    }
}

int cost = 0;
int edges = 0;
while(q.empty()){
    int wt = q.top().first;
    int u = q.top().second.first;
    int v = q.top().second.second;
    q.pop();

    if(FindParent(u, parent) != FindParent(v, parent)){
        cost += wt;
        UnionByRank(u, v, parent, rank);
    }
}
//why heap --
//v + ELogE + ElogE
//best case VlogE + v+e   ///vlogV + E -- best complee graph

}

int main() {

    return 0;
}