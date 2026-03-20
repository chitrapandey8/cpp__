#include <bits/stdc++.h>
using namespace std;

// int brute(vector<int> ans){
//     int n = ans.size();
//     int maxgcd = 0;

//     for (int i = 0; i < ans.size(); i++)
//     { 
//         int ans;
//         if(i == 0){
//             ans  = ans[1];
//          for(int j = 2; j<n; j++){
//            ans = __gcd(ans,ans[j]);
//          }
//         }else if(i == n-1){
//           ans = ans[1];
//           for (int j = 2; j < n-1; j++)
//           {
//             ans  = __gcd(ans, ans[j]);
//           }
//         }else {
//            int ans1 = ans[0];
//            for (int j = 1; j <i; j++)
//            {
//             ans1 = __gcd(ans1, ans[j]);
//            }

//            int ans2 = ans[i+1];
//            for (int j = i+1; j<n; j++)
//            {
//            ans2 = __gcd(ans2, ans[j]);
//            }
           

//            ans = __gcd(ans1, ans2);
           
//         }
//        maxgcd = max(maxgcd,ans);
//     }

    
//     cout<<maxgcd<<endl;
// }

int main() {
    
    vector<int> arr{24, 16, 18, 30, 15};
    int n  = arr.size();
    
    ///pregcd;
    vector<int> pregcd(n,0);
    pregcd[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
       pregcd[i] = __gcd(pregcd[i-1], arr[i]);
    }
    
    ///sufixgcd
    vector<int> sufixgcd(n, 0);
    sufixgcd[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
       sufixgcd[i] = __gcd(sufixgcd[i+1], arr[i]);
    }


     int maxx = 0;
     
    for (int i = 0; i < n; i++)
    {
        int currmax  = 0;
        int leftgdc = 0;
        int rightgcd = 0;
       if( i == 0){
           leftgdc = 0;
       }else{

        leftgdc = pregcd[i-1];
       }

       if(i == n-1){
        rightgcd = 0;
       }else{
     rightgcd =  sufixgcd[i+1];
       }
      currmax = __gcd(leftgdc, rightgcd);
      maxx = max(maxx, currmax);

    }
    
    
     
    cout<<maxx<<endl;

    return 0;

}
