#include <bits/stdc++.h>
using namespace std;
// time- O(V2) space - O(v)
void Disjistra(int V, vector<vector<vector<int>>> &adj, int s){
    vector<bool> Explored(V,0);
     vector<int> dist(V, INT_MAX);
     dist[s] = 0;

     ///select a node which is not explored yet and its distance is
     int node = -1, value = INT_MIN;
     for(int i = 0; i<V; i++){
        if(!Explored[i] && value> dist[i]){
            node= i;
            value = dist[i];
        }
     }

     Explored[node] = 1;
     //relax the edges
     for(int j = 0; j<adj[node].size(); j++){
        int neigbour = adj[node][j][0];
        int weight =  adj[node][j][1];
          //explore edges which are not explored
        if(!Explored[neigbour] && dist[node] + weight < dist[neigbour]){
            dist[neigbour]  = dist[node] + weight ;
        }
     }
     //return dist;
}


void ByHEap(){
     vector<bool> Explored(V,0);
     vector<int> dist(V, INT_MAX);
     dist[s] = 0;

     priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> q;
     q.push({0,s});


     ///jab tak queue empty na hoajye
     while(!q.empty()){
        int node=  q.top().second;
        q.pop();

        if(Explored[node] == 1){
            continue;
        }

        Explored[node] = 1;
        
     //relax the edges
     for(int j = 0; j<adj[node].size(); j++){
        int neigbour = adj[node][j][0];
        int weight =  adj[node][j][1];
          //explore edges which are not explored
        if(!Explored[neigbour] && dist[node] + weight < dist[neigbour]){
            dist[neigbour]  = dist[node] + weight ;
        }
     }

     }
     

     
     //relax the edges
     for(int j = 0; j<adj[node].size(); j++){
        int neigbour = adj[node][j][0];
        int weight =  adj[node][j][1];
          //explore edges which are not explored
        if(!Explored[neigbour] && dist[node] + weight < dist[neigbour]){
            dist[neigbour]  = dist[node] + weight ;
            q.push({dist[neigbour], neigbour});
        }
     } 

     //space -- priority queue O(v+e)
     //time -- elogv --- sari e edges ko andar dalre hai or baahr nikalre hai, toh heap mai elogn time lagta hai or mujhe v vertexe dalna hai toh elogv
     //when we use dense graph seconf beomes - v^2logv
     //v^2 -- for first method
     //dense -- first method
     //sparsh --  second
}

int main() {
    return 0;
}