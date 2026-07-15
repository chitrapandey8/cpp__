#include <bits/stdc++.h>
using namespace std;
//time --worst case -- v*e , best casw O(e);
//space - O(v)

//agar graph undirected or negative wirhgt ka hai toh koi bhi ans nhi de sakta

void Bellman(int v, vector<vector<int>> &edges, int s){
vector<int> dist(v,1e8);
////1e8 is 10 ki power 8
dist[s]  = 0;
int e =  edges.size();

for(int i = 0; i<v-1; i++){
    //relax all eddges
     bool flag = 0;
    for(int j =0; j<e; j++){
        int u = edges[j][0];
        int v  = edges[j][1];
        int wt  = edges[j][2];

        if(dist[u] == 1e8){
            continue;
        }


        if(dist[u] + wt < dist[v]){
          flag =1 ;
            dist[v] = dist[u] + wt;
        }
    }

    if(!flag){ ///aagr flag 1 hoga mtln chnage hua hai toh hi aage karo warna wahi sehi ans return kardo
        return dist;
    }
}
///to detect cycle//////////

    for(int j =0; j<e; j++){
        int u = edges[j][0];
        int v  = edges[j][1];
        int wt  = edges[j][2];

        if(dist[u] == 1e8){
            continue;
        }

        if(dist[u] + wt < dist[v]){
            
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }
return dist;
}

int main() {

    return 0;
}