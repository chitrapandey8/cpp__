#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin>>t;
    while(t-->0){
        int a; cin>>a;
        int b; cin>>b;
        int c; cin>>c;

        int maxx = max({a,b,c});
        int minn = min({a,b,c});

        if(a != maxx && a != minn){
          cout<<a<<endl;
        } else if(b != maxx && b != minn){
            cout<<b<<endl;
        }else{
            cout<<c<<endl;
        }

    }

    return 0;
}