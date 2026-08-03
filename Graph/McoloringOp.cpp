#include <bits/stdc++.h>
using namespace std;

bool find(int node, bool graph[101][101], int n, int m, vector<bool> color){
    if(node == n){
        return 1;
    }
    //color the node wiht m color
    for(int i = 0; i<m;i++){
        //check if adjacent doesnot have same color.
        bool IsPossible  =1;
        for(int j = 0; j<n; j++){
            if(graph[node][j] &&color[j] == i){
                IsPossible = 0;
                break;
            }
        }
         if(IsPossible){ //we can assign i color to this node
            color[node] = i;
            if(find(node+1, graph, n, m, color)){
                return 1;
            }
            color[node] =  -1;
         }
    }
    return 0;
}
//Time Complexit - O()
//space 

int main() {
    return 0;
}