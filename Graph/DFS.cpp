#include <bits/stdc++.h>
using namespace std;

void listt(vector<vector<int>> &list, int vertex, int edges){
    int u, v;
    for(int i = 0; i<edges; i++){
        cin>>u>>v;

        list[u].push_back(v);
        list[v].push_back(u);
    }
}


// void DFS(int node, vector<vector<int>> &adj , vector<bool> &visted, vector<int> &ans){
//    visted[node] = 1;
//    ans.push_back(node);

//    for(int j = 0; j<adj[node].size(); j++){ //us wali vector pe iterate karo, means negibour
//     if(!visted[adj[node][j]]){
//       DFS(adj[node][j], adj, visted, ans); // aab jo node pe hu uusse explore karo usek liye call laeggei phie usse array pe jake explore hoga
//     }
//    }
// }

void DFS(int node, vector<vector<int>> &list, vector<bool> &visited, vector<int> &ans){
    visited[node] = 1;
    ans.push_back(node);

    for(int i = 0; i<list[node].size(); i++){
        if(!visited[list[node][i]]){
            DFS(list[node][i], list, visited, ans);
        }
    }

}

void DFSIterativebyStack(vector<vector<int>> &list, vector<int> &ans){

    stack<int> st;
    st.push(0);
    vector<bool> visited(list.size());
    
    int node;
    while(!st.empty()){
        node = st.top();
        st.pop();
         
        if(visited[node]){
            continue;
        }
        visited[node] = 1;
        ans.push_back(node);
        for(int i = list[node].size()-1; i>=0; i--){
            if(!visited[list[node][i]]){
                st.push(list[node][i]);
            }
        }
    }

}



int main() {
    int vertex, edges;
    cin>>vertex>>edges;
    vector<vector<int>> list(vertex);
    listt(list, vertex, edges);

    for(int i = 0; i<list.size(); i++){
        cout<<i<<"->";
        for(int j = 0; j<list[i].size(); j++){
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }

    // vector<bool> visited(vertex, 0);
    // vector<int> ans;
    // DFS(0, list, visited, ans);

    vector<int> ans;
    DFSIterativebyStack(list, ans);

    for(int x: ans){
    cout<<x<<" ";
    }
    return 0;
}
