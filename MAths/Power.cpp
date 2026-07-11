#include <bits/stdc++.h>
using namespace std;



int main() {
    cout<<fixed<<setprecision(5)<<endl;
    double a; cin>>a;
    int b; cin>>b;
    if(b < 0){
        b = -b;
        a = 1.0/a;
    }

      double ans = 1.0;
    // for(int i = 0; i<b; i++){
    //  ans *= a;
    // }
    // cout<<ans<<endl;

      while (b)
      {
        if(b%2 == 1){
            ans = ans*a;
            b--;
        }else{
            ans = ans*ans;
            b = b/2;
        }
      }
      
   cout<<ans<<endl;
    return 0;
}