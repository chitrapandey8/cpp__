#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t-->0){
        int a; cin>>a;
        int b; cin>>b;
        if(a == b){
            cout<<0<<endl;
            
        }else{
          int diff = abs(b-a);
        if(diff%10 == 0){
            cout<<(diff/10)<<endl;
        }else{
            cout<<(diff/10)+1<<endl;
        }
        }
        
       
    }
    return 0;
}