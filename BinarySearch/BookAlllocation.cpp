#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int count, int maxpages){
    int pages = 0;
    int cnt = 1;

    for(int i = 0; i<arr.size(); i++){
        if(pages + arr[i] <= maxpages){
            pages += arr[i];
        }else{
            cnt++;
            pages = arr[i];

            if(cnt > count){
                return false;
            }
        }
    }
    return true;
}


int BookAllocation(vector<int> arr, int student){
    int start = *max_element(arr.begin(), arr.end());
    int end  = accumulate(arr.begin(), arr.end(),0);
    int ans = -1;

    int n = arr.size();
    if(n < student){
        return -1;
    }

    while(start <= end){
      int mid = start + (end - start)/2;

      if(isPossible(arr,student,mid)){
        ans  = mid;
        end = mid-1;
      }else{
        start = mid+1;
      }
    }

    return ans;
}


int main() {
    vector<int> arr = {12, 34, 67, 90};
    cout<<BookAllocation(arr, 2);
    
    return 0;
}