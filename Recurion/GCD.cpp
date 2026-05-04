#include <bits/stdc++.h>
using namespace std;

int fn(int a, int b){
if(b == 0){
    return a;
}

int modu = a%b;
return fn(b, modu);
}

int main() {
    cout<<fn(12, 39);
    return 0;
}