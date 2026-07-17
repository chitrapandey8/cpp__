#include <bits/stdc++.h>
using namespace std;
///EC == EP
//EP != EC


void DFS(int node,vector<vector<int>> &adj, vector<bool> & visited ){
    visited[node] = 1;
    for(int i = 0; i<adj[node].size(); i++){
        if(!visited[adj[node][i]]){
         
        }
    }
}

int EP(int v, vector<vector<int>> &adj){

    ///Euler Cuicuit
    //calculate the Degree of each node
    //All node Should have even Degree
    //All non-zero degree node should be connected


    ///Euler Path
    //calculate the Degree of each node
    //zero or two node can have odd drgeree and remaining have even degree.
    //All non-zero degree node should be connected


    vector<int> Degree(v, 0);
    int odd_Degree = 0; //no of nodes having odd drgee
    for(int i = 0; i<v; i++){
        Degree[i]  =  adj[i].size();
        if(Degree[i]%2){
            odd_Degree++;
        }
    }

    if(odd_Degree != 2 && odd_Degree != 0){ //1, 4,3,5,6,7 na EP hai na hi EC
          return 0;
    }

    //aLL non degrgee node should be connected
    vector<bool> visited(v, 0);
    for(int i = 0; i<v; i++){
        if(Degree[i]){
            DFS(i, adj, visited);
            break;
        }
    }

    //IF non zero degree node is still not visited , return 0;
    //degree zero hia isko ignore (koi egee nhihai)

    for(int i = 0; i<v; i++){
        if(Degree[i] && !visited[i]){
            return 0;
        }
    }

    ///Eulerisan cirvuit  : 2
    // Eulerai path: 1

    if(odd_Degree == 0){
        return 2;
    }else{
        return 1;
    }
}

int main() {
    return 0;
}