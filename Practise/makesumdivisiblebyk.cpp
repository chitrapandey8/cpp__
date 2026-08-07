#include <bits/stdc++.h>
using namespace std;

int SubaaraySum(vector<int> arr, int target){
int ans = INT_MAX;
int left = 0;
int right = 0;
int n = arr.size(); int sum = 0;
while (right < n)
{
    sum += arr[right];

    while(sum >= target){
        ans = min(ans, right-left+1);
        sum -= arr[left];
        left++;
    }
    right++;
}
 

 return ans;
}

int main() {
    int n,p; cin>>n>>p; 
    vector<int> arr;
    for(int i = 0; i<n; i++){
        int a; cin>>a;
        arr.push_back(a);
    }
     int summ = 0;
    for(int x: arr)
    summ += x;
    
    int rem = 0;
    if(summ%p == 0){
      cout<<0<<endl;
    }else{
        rem = summ%p;
    }
    int ans = SubaaraySum(arr, rem);
    cout<<ans<<endl;
    return 0;
}