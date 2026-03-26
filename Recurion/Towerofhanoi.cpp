#include <bits/stdc++.h>
using namespace std;

int recur(int n){
if(n == 0){
    return 0;
}

return recur(n-1) + 1 +  recur(n-1);
}

int fastest(int n){
    return (1<<n)-1;
}

int main() {
    cout<<recur(3)<<endl;
    cout<<fastest(3);
    return 0;
}