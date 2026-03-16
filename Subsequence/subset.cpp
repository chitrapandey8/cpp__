#include <bits/stdc++.h>
using namespace std;

void filter(int no, vector<int> nums){
    vector<int> ans;
    int j = nums.size()-1;
    while(no > 0){
        
        int last_bit = no&1;
        if(last_bit == 1){
            ans.push_back(nums[j]);
        }
        j--;
        no=no>>1;
        
        
    }



    for(int x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main() {

    vector<int > arr{1,2,3,4,5};
    int n = arr.size();
     for (int i = 0; i < (1<<n); i++)
     {
       filter(i,arr);
     }
     

    return 0;
}