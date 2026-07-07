#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2,5,10,8,100,1000,5,15};
    int k = 999;
     int end = 0;
     int product = 1;
     int start = 0;
     int ans  = 0;
    while(end < arr.size()){
        product *= arr[end];

        while(product >= k){
             product /= arr[start];
             start++;
        }
      ans += (end-start)+1;
      end++;
    return 0;
}