#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 5;
    int n = 3;
    int ans = 1;
    while(n>0){
      if((n&1) == 1){
         ans *= a;
      }
      
        a = a*a;
    n = n>>1;
    }
   
    cout<<ans<<endl;
    return 0;
}