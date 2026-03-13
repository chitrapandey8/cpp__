#include<bits/stdc++.h>
using namespace std;



int print(int n){
    if(n == 1){
        return 1;
    }

    return print(n-1) + n;
}

int main(int argc, char const *argv[])
{
    int ans = print(5);
    cout<<ans<<endl;
    return 0;
}
