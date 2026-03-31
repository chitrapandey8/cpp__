#include <bits/stdc++.h>
using namespace std;

int findpivot(vector<int> arr, int start, int end){

     
     while(start < end){
        int mid = start + (end - start) /2;

        if(mid < end && arr[mid] > arr[mid + 1]){
            return mid+1;
        }else if(mid > start && arr[mid] < arr[mid-1]){
           return mid;
        }else if(arr[mid] > arr[start]){
           start = mid +1;
        }else{
           end =  mid-1;
        }
     }
}

int main() {
    vector<int> arr{3,4,5,6,7,9,1,2,3};
    cout<<findpivot(arr, 0, arr.size()-1);
     
    
    return 0;
}