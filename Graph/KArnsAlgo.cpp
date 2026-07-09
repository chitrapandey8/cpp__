#include <bits/stdc++.h>
using namespace std;

int main() {

    for(int i = 0; i<v; i++){
        for(int j = 0; j<list[i].size(); j++){
            Indegree[list[i][j]]++;
        }
    }


    queue<int> q; //0 wale ko push
    for(int i = 0; i<v; i++){
        if(!InDegree[i]){
            q.push(i);
        }
    }

    
        while(!q.empty()){
            int node = q.front();

            q.pop();
            ans.push_back(node); //jisko mnikala uske neihbours ko ek se minus karo
       
            for(int j = 0; j<list[node].size(); j++){
                Indegree[list[node][j]]--;
                if(Indegree[list[node][j]] == 0){
                    q.push(list[node][j]);
                }
            }

        
    }
    return 0;
}