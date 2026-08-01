#include <bits/stdc++.h>
using namespace std;
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, stack<int> s, vector<bool> &Instack, vector<vector<int>> &ans, int timer){
    visited[node] = 1;
    disc[node] = low[node] = timer;
    s.push(node);
    Instack[node] = 1;

    for(int j = 0; j <adj[node].size(); j++){
        int neib = adj[node][j];
        if(!visited[neib]){
            timer++;
            DFS(neib, adj, visited, disc, low, s, Instack, ans, timer);
            low[node] = min(low[node], low[neib]);
        }else{
            if(Instack[neib]){

                low[node] = min(low[node], disc[neib]);
            }
        }
    }

    if(disc[node] == low[node]){
        vector<int> temp;
        while(!s.empty() && s.top() != node)
        {
            temp.push_back(s.top());
            Instack[s.top()] = 0;
            s.pop();
        }

         temp.push_back(node);
            Instack[s.top()] = 0;
            s.pop();
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
    }

}

int main() {
    int v;
    vector<vector<int>> ans;
    vector<int> disc(v);
    vector<int> low(v);
    vector<bool> visited(v,0);
    stack<int> s;
    vector<bool> InStack(v, 0);
    int timer = 0;
    vector<vector<int>> adj;

    for(int i = 0; i<v; i++){
        if(!visited[i]){
            DFS(0, adj, visited, disc, low, s, InStack, ans, timer);

        }
    }

    return 0;
}