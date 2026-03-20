#include <bits/stdc++.h>
using namespace std;


int brute(int a, int b){
 int minn = min(a,b);
 int gcd  = 1;
 for (int i = 1; i < minn; i++)
 {
  if((a%i == 0) && (b%i == 0)){
     gcd = i;
  }
 }

 cout<<gcd<<endl;
}

int iterativeway(int a, int b){
    int A = 0;
    int B = 0;
    while(a!= 0){
      
        A = b%a;
        B = a;
        a = A;
        b = B;
    }
    return b;
}

int recursiongdc(int a, int b){
    if( a == 0){
        return b;
    }

    recursiongdc(b%a, a);
}

int main() {
    // int a = 10;
    // int b = 12;
    // int ans  = recursiongdc(a,b);
    // cout<<ans<<endl;

    vector<int> arr{10, 20, 30, 40, 50};
    int n = arr.size();
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
       ans = recursiongdc(ans, arr[i]);
    }
    if(ans == 1){
        cout<<"YES"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
    return 0;
}