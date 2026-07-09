#include <bits/stdc++.h>
using namespace std;
///////Two colouring algorithm
//jab odd length ki cycle hogi waha par biparite graph exist nhi krta, ya jabmai ksisi node ko colour na kar pau
//it will look at its all neigbour
//if any color is not assigned , then assign colot to them oppositr to them,
//else agar already color assighned hai toh uska neigbour color is same as present node, we will declare it as bipartite graph

void Bipartite(){

}

int main() {
    int v;
    vector<int> color(v,-1);
    queue<int> q;


    for(int i = 0; i<v; i++){
        if(color[i] == -1){
            q.push(0);
    color[0] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();


        for(int j = 0; j<adj[node].size(); j++){
         if(color[adj[node][j]] == -1){
            color[adj[node][j]]  = (color[node]+1)%2;
            q.push(adj[node][j]); //jsikao abhi color assign kiya usse queue mai dalo
         }else{
            ///if color of node ios already assigned
            if(color[node] == color[adj[node][j]]){
                return 0;
            }
         }
        }
    }
   
        }
    }

    ///time- O(v+e)
    //space - O(v)
    
    ///return 1 ///bipartie hi hai
    return 0;
}