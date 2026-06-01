#include <bits/stdc++.h>
using namespace std;


int SoD(int N){
    if(N < 10){
        return N;
    }

    return N%10 + SoD(N/10);
}

int main() {
    int N = 123;
    int ans = SoD(N);
    cout<<ans<<endl;
    return 0;
}