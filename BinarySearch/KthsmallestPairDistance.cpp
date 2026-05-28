#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> arr, int k, int mid){ ///sliding window
    int i = 0;
    int cnt = 0;
    for(int j = 1; j<arr.size(); j++){
      
        while(arr[j] - arr[i] > mid){
            i++;
        }
         cnt  += (j-i);
  
    }

    if(cnt >= k){
        return true;
    }
   return false; 
}



int SEarchSpace(vector<int> arr, int k){
sort(arr.begin(), arr.end());
int start = 0;
int end = arr[arr.size()-1] - arr[0];
int ans = 0;
while(start <= end){
    int mid = start + (end -  start)/2;

    if(isPossible(arr, k, mid)){
       ans = mid;
       end = mid-1;
    }else{
        start = mid+1;
    }
}
return ans;
  
}

int main() {
    vector<int> arr = {1,6,1};
    cout<<SEarchSpace(arr,3);
    return 0;
}