#include <bits/stdc++.h>
using namespace std;

void priotyqueue(vector<int> arr, int k, vector<int> &ans){
    ///priority queue mai elemets log n maiinsert hote hia 
    //or ye do tarke ke hote hai  max jo max element ko top pe rakhta hai, or min priroy jo elemt ko top pe rakhta hia
    priority_queue<pair<int, int>> pq;
    int n = arr.size();
    

    /////sabse pehle 0 - k tak ki peheli window ko pq mia dalo or uska top jo ki max hoga usko store karke rakho
    for (int i = 0; i < k; i++)
    {
      pq.push({arr[i],i});
    }
    ans.push_back(pq.top().first);
    
    for(int i = k; i<n; i++){
        ///aab kse se loop n tak chalega or i wala eleemt push hoga 
        pq.push({arr[i],i});

        //check ki top wala eleemt window ke bahar toh nhi hai
        while(pq.top().second <= i-k){
            pq.pop();
        }

        //ans mai top wala elemet push karna hai
        ans.push_back(pq.top().first);
    }

}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans;
    priotyqueue(nums, k, ans);

    for(int x: ans){
        cout<<x<<" ";
    }
    return 0;
}