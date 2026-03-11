#include<bits/stdc++.h>
using namespace std;

int factoriall(int n){
     if(n == 0){
        return 1;

    }
     return factoriall(n-1) * n;
   
}


int main(int argc, char const *argv[])
{
   
    cout<<factoriall(5);
    return 0;
}
