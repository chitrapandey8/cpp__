#include <bits/stdc++.h>
using namespace std;

// void AlienDictionary(){


//     ///adjancry list create karo
//     int k ;
//     vector<vector<int>> list(k);
//     vector<int> Indegree(k, 0);
//     int N;


//     for(int i = 0; i< N-1; i++){
//         string str = dict[i] , str2 = dict[i+1];
//         int j =0; k =0 ;

//         while(j<str.size() && k< str2.size() && str[j] ==str2[k]){
//             j++ ;  k++;
//         }
//             if(j == str.size()){
//                 continue;
//             }

//             adj[str[j] - 'a'].push_back(str2[k] - 'a');
//             Indegree[str2[k] - 'a']++;

//         }

//         ////khan algorithm lagao;
//         queue<int> q;
//     for(int i = 0; i<N; i++){
//         if(!Indegree[i]){
//             q.push(i);
//         }
//     }

//     string ans = "";

//         int node = q.front();
//         q.pop();
//         char c = 'a'+node;
//         ans += c;

//         ///now look nodes nehobous and decrese its indegree 
        
//         for(int j = 0; j<adj[node].size(); j++){
//             Indegree[adj[node][j]]--;
//             if(!Indegree[adj[node][j]]){
//             q.push(adj[node][j]);
//             }
//         }

// }

void Aliendictionary(vector<vector<int>> &list, vector<int> &InDegree, string &ans){
queue<int> q;
//pehlee voh push karo jiski indrgree 0 ho

for(int i = 0; i<InDegree.size(); i++){
    if(InDegree[i] == 0){
        q.push(i);
    }
}

   while(!q.empty()){
    int node = q.front();
    q.pop();
    char c = node + 'a';
    ans += c;
    for(int i = 0; i<list[node].size(); i++){
        InDegree[list[node][i]]--;
        if(InDegree[list[node][i]] == 0){
                q.push(list[node][i]);
        }
    }
   }
    

}


int main() {

    vector<string> words =  {"ab", "cd", "ef", "ad"};
    //making adjency list
    int n = words.size();
    vector<vector<int>> list(6);
    vector<int> InDegree(6);

    for(int i = 0; i<words.size()-1; i++){
        string str1 = words[i]; 
        string str2 = words[i+1];

        int j = 0; int k = 0;
        while(j< str1.size() && k < str2.size() && str1[j] == str2[k]){
            j++; k++;
        }

        if(j == str1.size()){
            continue;
        }

        list[str1[j] - 'a'].push_back(str2[k] - 'a');
        InDegree[str2[k] - 'a']++;

    }



    // for(int i = 0; i<list.size(); i++){
    //     cout<<i<<"->";
    //     for(int j = 0; j<list[i].size(); j++){
    //     cout<<list[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int x: InDegree){
    //     cout<<x<<" ";
    // }
    string ans  = "";
    Aliendictionary(list, InDegree, ans);
    cout<<ans<<endl;
    
    return 0;
}