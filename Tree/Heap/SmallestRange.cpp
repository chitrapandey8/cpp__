#include <bits/stdc++.h>
using namespace std;

int main() {
    //pehle max elemet pata karlo kimai max range kaha tak le sakti hu
    vector<vector<int>> arr = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    int maxx = INT_MIN;
    for(int i = 0; i<arr.size(); i++){
        maxx = max(maxx, arr[i][arr[i].size()-1]);
    }
    
    
    bool Check(vector<int> a, vector<vector<int>> arr){
        int cnt = 0;
        
        for(int i = 0; i< arr.size(); i++){
            bool flag = false;
            for(int j = 0; j<arr[i].size(); j++){
                if(arr[i][j] >= a[0] && arr[i][j] <= a[1]){
                    flag = true;
                    cnt++;
                }
            }
            if(flag){
                cnt++;
            }
        }
        if(cnt >= arr.size()){
            return true;
        }
        return false;
    }
    
    vector<int> ans(2);
    for(int i = 0; i<=maxx; i++){
        vector<int> ar(2);
        for(int j = i; j<=maxx; j++){
            ar[0] = i;
            ar[1] = j;
            if(Check(ar, arr)){
                 if((ans[1] - ans[0]) )
            }
        }
    }

    return 0;
}