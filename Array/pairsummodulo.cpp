#include <bits/stdc++.h>
using namespace std;

long long fact(int n){
    int fac = 1;
    for (int i = 1; i <= n; i++)
    {
       fac *= i;
    }
    return fac;
}

long long ncr(int n, int r){
    return fact(n)/(fact(r)* fact(n-r));
}


int brute(vector<int> arr){
   
    int m   = 3;
    vector<int> ans;
    int count=  0;

    for(int i = 0; i<arr.size()-1; i++){
        for (int j = i+1; j < arr.size(); j++)
        {
           if((arr[i] + arr[j])%m == 0){
              count++;
           }
        }

        
    }
    
   cout<<count<<endl;
}

int optimal(vector<int> arr, int m){
unordered_map<int, int> mp;
int k  = 5;
for(int x: arr){
    mp[((x%k)+k)%k]++;
}


int count = 0;
////when rem is zer0
count += ncr(mp[0],2);

//when k is even 
if(k%2  == 0){
    count += ncr(mp[k/2], 2);
}

for (int i = 0; i <= k/2; i++)
{
  if(i != k-i) {
    count += mp[i]* mp[k-i];
  } 
}
cout<<count<<endl;

}




int main() {
     vector<int> arr{4,7,6,5,8,3, 10, 15};
     int k = 5;
     int ans = optimal(arr, k);
     cout<<ans<<endl;

    return 0;
}