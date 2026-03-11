#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
     int a;cin>>a;
     int b;cin>>b;
    int count = 0;
      while(true){
        if(a>b){
            cout<<count;
            break;
        }

        count++;
        a = a*3;
        b = b*2;
      }
    return 0;
}