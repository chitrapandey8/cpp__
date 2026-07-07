///////////////////////////undirected unweightted///////////////////////////////
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int vertex, edges;
//     cin>>vertex>>edges;

//     vector<vector<int>> list(vertex);

//     int u, v;
//     for(int i = 0; i<edges; i++){
//     cin>>u>>v;
     
//      list[u].push_back(v);
//      list[v].push_back(u);
     
//     }

//     for(int i = 0; i<vertex; i++){
//         cout<<i<<"->";
//         for(int j = 0; j<list[i].size(); j++){
//             cout<<list[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


///////////////////////////////////undirected weightted graph////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertex, edges;
    cin>>vertex>>edges;

    vector<vector<pair<int, int>>> list(vertex);

    int u, v, weight;
    for(int i = 0; i<edges; i++){
        cin>>u>>v>>weight;

        list[u].push_back({v,weight});
        list[v].push_back({u,weight});
    }

     for(int i = 0; i<list.size(); i++){
        cout<<i<<"->";
        for(int j = 0; j<list[i].size(); j++){
            cout<<list[i][j].first<<","<<list[i][j].second<<" ";
        }
          cout<<endl;
     }
    return 0;
}