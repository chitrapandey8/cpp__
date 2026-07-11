#include <bits/stdc++.h>
using namespace std;

int main() {

    ///adj list banao pehele
     vector<pair<int, int>> pre;int N;
     vector<int> Indegree(N,0);

    vector<vector<int>> adj;
    int p ;

    for(int i = 0;i <p; i++){
      adj[pre[i].second].push_back(pre[i].first);
      Indegree[pre[i].first]++;
    }
    
    //kahn algortithm
    queue<int> q;
    for(int i = 0; i<N; i++){
        if(!Indegree[i]){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        ///now look nodes nehobous and decrese its indegree\f\\
        
        for(int j = 0; j<adj[node].size(); j++){
            Indegree[adj[node][j]]--;
            if(!Indegree[adj[node][j]]){
            q.push(adj[node][j]);
            }
        }
    }



     


    return 0;
}