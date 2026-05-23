#include <bits/stdc++.h>
using namespace std;
int FindSum(vector<int> arr, int index, int n, int targetsum){
       if(targetsum == 0){
        return 1;
       }

       if(index == n  || targetsum < 0){
        return 0;
       }

    return FindSum(arr, index+1, n, targetsum) + FindSum(arr, index+1, n, targetsum-arr[index]);

}


///what if their is zero;
int FindSuminZero(vector<int> arr, int index, int n, int targetsum){
    if(index == n){
        return targetsum == 0;
    }


    return FindSuminZero(arr, index+1, n, targetsum) + FindSuminZero(arr, index+1, n, targetsum-arr[index]);
}


int main() {
    vector<int> arr = {0,1};
    int ans = FindSuminZero(arr, 0, 2, 1);
    cout<<ans;
        return 0;
}