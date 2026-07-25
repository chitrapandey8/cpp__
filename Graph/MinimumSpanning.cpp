#include <bits/stdc++.h>
using namespace std;
//disconnected grsph ka tree nhi bnata
//Space Complexity -- V(mst)+V(parent)+queue--queue ka size worst mai E hoga 
//time compee ElogE e emelemt ko push e element pop
int SpanningTree(int v, vector<vector<int>> adj[]){
///priority queue
//wt, node, par



priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
vector<bool> IsMST(v, 0);
vector<int> parent(v);
int cost = 0;
q.push({0,{0, -1}});

while(!q.empty()){
    int wt = q.top().first;
    int node = q.top().second.first;
    int par = q.top().second.second;

    if(!IsMST[node]){
        IsMST[node] = 1;
        cost += wt;
        parent[node] = par;

        for(int j =0; j<adj[node].size(); j++){
            if(!IsMST[adj[node][j][0]]){ //voh node uss mst ka part nhi hona chahiye
               q.push({adj[node][j][1], {adj[node][j][0], node}});
            }
        }
    }}}

int main(){

    return 0;
}