#include <bits/stdc++.h>
using namespace std;

int Fabonacii(int n){
    if(n == 1){
        return 1;
    }
    if(n == 0){
        return 1;
    }

    return Fabonacii(n-1) + Fabonacii(n-2);
}

int main() {
    cout<<Fabonacii(5);
    return 0;
}