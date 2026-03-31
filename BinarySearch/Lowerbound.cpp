#include <bits/stdc++.h>
using namespace std;

int findfirstelement(vector<int> arr, int target, int start, int end){
    int ans  = -1;
    while(start < end){
        int mid  = start + ( end -  start)/2;
        
        if(arr[mid] == target){
         ans = mid;
         end = mid-1;
        }else{
            start =  mid+1;
        }
       
    }
    return ans;
}

int lastoccurance(vector<int> arr, int target, int start, int end){
    while(start< end){
        int mid = start + (end - start)/2;

        
    }
}

int main() {
    //find the frist occureance of  of 2
    vector<int> arr{0,1,1,2,2,2,2,3};
    cout<<findfirstelement(arr, 2, 0, arr.size()-1)<<endl;

    return 0;
}