#include <bits/stdc++.h>
using namespace std;

bool DFS(int node, vector<int> &color, bool graph[101][101], int m, int n){

    for(int i = 0; i<m; i++){
        bool IsPossible = 1;
        for(int j =0; j<n; j++){
            if(graph[node][j] && color[j] == i){
                IsPossible = 0;
                 break;
            }
        }
        if(IsPossible == 0){
            continue; ///check the next color
        }
        color[node] = i; //Assign color to the node

        //go to the adjacent node, whom the color is not assinable
        for(int j =0; j<n; j++){
            if(graph[node][j] && color[j] == -1){
                if(!DFS(j, color, graph, m, n)){
                    IsPossible = 0;
                    break;
                }
            }
        }

        //if all the adjacnet node can becolored then isossible will be 1.
        if(IsPossible){
            return 1; 
        }
        color[node] = -1; //move to the next color.
    }
}


bool GraphColoring(bool graph[101][101], int m, int n){
        vector<int> color(n,-1);
        for(int i =0; i<n; i++){
            if(color[i] == -1 && !DFS(i, color, graph, m, n)){
             return 0;
            }
        }
        return 1;
    }

    //time complexity -- O(m*n)^n


int main() {

   
    
    return 0;
}