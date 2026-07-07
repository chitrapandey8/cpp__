// #include <bits/stdc++.h>
// using namespace std;

// ///adjacrncy matrix time - O(v^2) , space - O(v^2);
// //undirected unweighted graph-


// int main() {
//     int vertex, edges;
//     cin>>vertex>>edges;

//     vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex,0)); //jinte vertex utne rows and cols

//     int u,v;
//     for(int i =0;i < edges; i++){
//         cin>>u>>v;
//         //undirected unweightted graph
//         // AdjMat[u][v] = 1;
//         // AdjMat[v][u] = 1;

//         ///undirected werighted graph take one input weight put 
//         // AdjMat[u][v] = weight;


//         ///direted weighted graph
//         AdjMat[u][v] =1; //only in one direction on in both
//     }

//     for(int i = 0 ;i<vertex; i++){
//         for(int j = 0; j<vertex; j++){
//             cout<<AdjMat[i][i]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

///////////////////////////////////////////////////Undirected UnWeighted Graph/////////////////////////////////////////////////////
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ///undirected unweight graph
//     int vertices, edges;
//     cin>>vertices>>edges;
//     vector<vector<bool>> mat(vertices, vector<bool>(vertices,0));

//     int v, u;
//     for(int i = 0; i<edges; i++){
//         cin>>v>>u;
//         mat[v][u] = 1;
//         mat[u][v] = 1;
//     }

    
//     ////////Printing matrixx//////////
//     for(int i = 0; i<vertices; i++){
//         for(int j = 0; j<vertices; j++){
//             cout<<mat[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }


//////////////////////////////////////////////Undirected Weightted Grpaph/////////////////////////////////
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int vertices, edges;
//     cin>>vertices>>edges;
//     vector<vector<int>> mat(vertices, vector<int>(vertices,0));


//     ///take inputs of edges and weights
//     int v, u, weight;
//     for(int i = 0; i<edges; i++){
//      cin>>v>>u>>weight;
//      mat[v][u] = weight;
//      mat[u][v] = weight;
//     }


//     //Printing matrix;
//     for(int i = 0; i<vertices; i++){
//         for(int j =0; j<vertices; j++){
//             cout<<mat[i][j]<<" "; 
//         }
//         cout<<endl;
//     }
//     return 0;
// }


////////////////////////////////////////////Directed  Unweighted  Graph/////////////////////////
#include <bits/stdc++.h>
using namespace std;

int main() {
    ///undirected unweight graph
    int vertices, edges;
    cin>>vertices>>edges;
    vector<vector<bool>> mat(vertices, vector<bool>(vertices,0));

    int v, u;
    for(int i = 0; i<edges; i++){
        cin>>v>>u;
        mat[v][u] = 1;
        
    }

    
    ////////Printing matrixx//////////
    for(int i = 0; i<vertices; i++){
        for(int j = 0; j<vertices; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


///////////////////////////////Directed weighted graph/////////////////////
