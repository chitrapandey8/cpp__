#include <bits/stdc++.h>
using namespace std;

int Fab(int n){
   if(n == 1){
    return 1;
   }
   if(n == 2){
    return 2;
   }

    return Fab(n-1) + Fab(n-2);
}

int main() {
    cout<<Fab(5);
    return 0;
}