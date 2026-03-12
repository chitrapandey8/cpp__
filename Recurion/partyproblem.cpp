#include<bits/stdc++.h>
using namespace std;

int party(int n){
    if (n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }

    return party(n-1) + party(n-1)*party(n-2);

}

int main(int argc, char const *argv[])
{
    int ans = party(3);
    cout<<ans;
    return 0;
}
