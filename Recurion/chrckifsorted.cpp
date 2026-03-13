#include<bits/stdc++.h>
using namespace std;

bool issorted(vector<int> arr, int i){
    
    int n = arr.size();
    if(i == n-1){
       return true;
    }
    

    if(arr[i] < arr[i+1] && issorted(arr, i+1)){
        return true;
    }else{
        return false;
    }
 }



int main(int argc, char const *argv[])
{
    vector<int> arr{1,2,3,4,8,6,7};
    cout<<issorted(arr,0);
    return 0;
}
