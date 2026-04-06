#include <bits/stdc++.h>
using namespace std;

bool findpairs(vector<int>& arr , int k, int mid){
    
    int i = 0;
    int j = 1;
    int n = arr.size();
   
    int count = 0;

    while(j < n){
        int diff = arr[j] - arr[i];
        if(diff <= mid){
            count++;
            if(count == k){
                return true;
            }
            i+=2;
            j+=2;
        }else{
            i++;
            j++;
        }
    }
    return false;

}

int main() {
    vector<int> arr{1,1, 2,3,7, 10};
    int start = 0;
    int end = arr[arr.size()-1] - arr[0];
    int k = 2;

    int ans = 0;

    while(start <= end){
        int mid  =  start + (end - start)/2;

        if(findpairs(arr, k, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start =  mid+1;
        }

    }

cout<<ans<<endl;



    

    return 0;
}