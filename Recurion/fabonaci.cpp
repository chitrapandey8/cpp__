#include<bits/stdc++.h>
using namespace std;

int fabonaci(int n){
    if(n == 1){
        return 1;
    }

    if(n == 2){
        return 2;
    }

    return fabonaci(n-1) + fabonaci(n-2);

}

int iterative(int n){
    int n1 = 1;
    int n2 = 2;

    for (int i = 2; i <  n; i++)
    {

        int n3 = n1 + n2;
        n1  = n2;
        n2 = n3;
    }
    return n2;
    
}




int main(int argc, char const *argv[])
{
     int ans  = iterative(4);
     cout<<ans;
    return 0;
}
