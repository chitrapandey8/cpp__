#include <bits/stdc++.h>
using namespace std;

void ajadencyMatrix(vector<bool> &visited, vector<vector<int>> &graph, int &vertices, int &edges){
     int m,n;
     for(int i = 0; i<edges; i++){
        cin>>m>>n;
        graph[m].push_back(n);
        graph[n].push_back(m);
     }
    
}

void BFS(vector<vector<int>> &Graph, vector<bool> &visited, vector<int> &ans){
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int node = q.front(); q.pop();
        ans.push_back(node);
        for(int i = 0;i < Graph[node].size(); i++){
          if(!visited[Graph[node][i]]){
             visited[Graph[node][i]] = true;
             q.push(Graph[node][i]);
          }
        }
    }
    
}

///toposort with DFS
void DFS(int node,vector<vector<int>>& edge,stack<int> &s, vector<bool> &visited){
       visited[node] = true;
       
       for(int i = 0; i< edge[node].size(); i++){
           if(!visited[edge[node][i]]){
               DFS(edge[node][i],edge,s,visited);
           }
       }
       s.push(node);
       
    }


///kahns - indegree inkalo queue mai dalo phir jinki indegree 0 hia unhe process akro phir usse node se jispar bhi edge jari hai uski indegree kam -- karo


///////////covid spread gfg -- if at any cell i find a covid pateint then i will spread it to its connected cell i will move to its left, right, up, down to spread
bool Valid(int r, int c, int noofrows, int noofcols){
    return r >= 0 && r < noofrows && c >= 0 && c < noofcols;
}

int timetaken(vector<vector<int>> &arr){

    int r = arr.size(); int c = arr[0].size();
    vector<int> row = {-1,1,0,0};
    vector<int> col = {0,0,-1,1};
 
    queue<pair<int, int>> q;
    int time = 0;

    for(int i = 0 ;i < r;  i++){
        for(int j = 0; j < c; j++){
            if(arr[i][j] == 2){
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        int n = q.size();
        time++;
        while(n--){

          auto it = q.front();
          int  i = it.first;
          int  j = it.second;
          q.pop();
          for(int p = 0; p < 4; p++){
              if(Valid(i+row[p], j+col[p],r,c) && arr[i+row[p]][j+col[p]] == 1){
                arr[i+row[p]][j+col[p]] = 2;
                q.push({i+row[p], j+col[p]});
              }
          }
        }
    }

    for(int i = 0 ;i < r;  i++){
        for(int j = 0; j < c; j++){
            if(arr[i][j] == 1){
               return -1;
            }
        }
    }

  return time-1;

}


int main() {
    

    vector<vector<int> > arr= {{2, 1, 0, 2, 1}, {0, 0, 1, 2, 1}, {1, 0, 0, 2, 1}};
     

  cout<<timetaken(arr);
    return 0;
}