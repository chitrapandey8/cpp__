#include<bits/stdc++.h>
using namespace std;

void printnu(int n){
    // if(n == 0){
    //     return;
    // }

    // printnu(n-1);
    // cout<<n<<endl;

    if(n == 6){
        return;
    }

    cout<<n<<endl;
    printnu(n+1);
    
}



int main(int argc, char const *argv[])
{
    //base case
    printnu(1);
    return 0;
}
