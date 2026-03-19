#include <bits/stdc++.h>
using namespace std;


int mincost(vector<vector<int>>& curr, int n, int currentcity, int visited){
    if(visited == (1<<n)-1){
        return curr[currentcity][0];
    }

    
    
    int cost = INT_MAX;
    for (int city = 0; city < n; city++)
    {
       if((visited &(1<<city)) == 0){
        int min_cost = curr[currentcity][city] + mincost(curr,n, city,visited|(1<<city));
        cost  = min(cost,min_cost);
       }
    }
    return cost;

}

int main() {
    vector<vector<int>>  arr{{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    cout<<"the min cost"<<mincost(arr,arr.size(),0,1);

    
    return 0;
}