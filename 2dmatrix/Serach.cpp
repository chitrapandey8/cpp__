#include <bits/stdc++.h>
using namespace std;


bool search(vector<vector<int>> arr, int target){
   int n = arr.size();
   int m = arr[0].size();
   int start = 0;
   int end = m*n-1;
   while(start <= end){
    int mid = start + (end -  start)/2;

     int row = mid/m;
     int col = mid%m;
     
     if(arr[row][col] == target){
        return 1;
     }else if(arr[row][col] > target){
          end = mid-1;
     }else{
        start = mid+1;
     }
   }
   return 0;
}

int main() {
    vector<vector<int>> arr = {{1,3,5},{10,11,16},{23, 30, 34}};
    if(search(arr, 3)){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }

    return 0;
}