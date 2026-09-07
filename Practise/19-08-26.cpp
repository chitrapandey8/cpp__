#include <bits/stdc++.h>
using namespace std;

void cinemaSearAllocation(int n, vector<vector<int>> &res){

    unordered_map<int, unordered_set<int>> mp;
    for(vector<int> a: res){
        int row = a[0];
        int seat = a[1];
        mp[row].insert(seat);
    }

    int cnt = 0;
    int cntrow = 0;
    for(auto it : mp){
      
        bool block1 = false;
        bool block2 = false;
        
        //for block 1
        if(!it.second.count(2) && !it.second.count(3) && !it.second.count(4) && !it.second.count(5)){
            cnt++;
            block1 = true;
        }
        //for block 2
        if(!block1){
            if(!it.second.count(4) && !it.second.count(5) && !it.second.count(6) && !it.second.count(7)){
                cnt++;
                block2 = true;
            }

        }
        if(!block2){
             if(!it.second.count(6) && !it.second.count(7) && !it.second.count(8) && !it.second.count(9)){
                cnt++;
            }
        }

       cntrow++;
    }
    
    cout<<"cnt"<<" "<<cnt<<endl;
    int left = n - cntrow;
    cout<<"left"<<left<<" "<<endl;
    int ans = cnt;
    ans += left*2;
    cout<<ans<<endl;

}

int main() {
    // int  n = 4;
    // vector<vector<int>> arr = {{4,3},{1,4},{4,6},{1,7}};
    // cinemaSearAllocation(n, arr);


    cout<<abs(2-2);
    return 0;
}