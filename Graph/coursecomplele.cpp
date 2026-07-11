#include <bits/stdc++.h>
using namespace std;

int main() {
    ///make adj list


    vector<vector<int>>  adj;
    vector<vector<int>>  relations;


    for(int i =0; i< relations.size(); i++){
       adj[relations[i][0]-1].push_back(relations[i][1]-1); // 0 based indexing
    }


    int n = 0;
    vector<int> InDegree(n,0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<adj[i].size(); j++){
            InDegree[adj[i][j]]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<n ;i++){
        if(!q.empty()){
            q.push(i);
        }
    }

    ///maxi time to compleeter previosu course
    vector<int> CT(n, 0);

    while(!q.empty()){
        int node = q.front();
           q.pop();
        for(int j = 0; j<adj[node].size(); j++){
            InDegree[adj[node][j]]--;
            if(InDegree[adj[node][j]]){
                q.push(adj[node][j]);
            }

            ///maximum time to compelte previosu course + present course time
          CT(adj[node][j]) = max(CT(adj[node][j]),CT[node] + time[node]);
        }
    }


    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, CT[i]+ time[i]);
    }
    return 0;
}