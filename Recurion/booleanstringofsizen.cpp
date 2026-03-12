#include<bits/stdc++.h>
using namespace std;

int booleanstering(int n, int prev){
    if(n == 0){ //agar meri no of positon left 0 hogay iska mtln meri ek string ban gyi h toh return 1;
        return 1;
    }

    int count = 0; //ye no of ways calculate kara hhai ki kinti strings ban rahu hai

    count += booleanstering(n-1,0);

    if(prev == 0){
        count += booleanstering(n-1,1);
    }

    return count;

}

int fabonacci(int n){
    if(n == 1){
        return 2;
    }
    if(n == 2){
        return 3;
    }

     return fabonacci(n-1) + fabonacci(n-2);
}


int main(int argc, char const *argv[])
{
    // int ans  = booleanstering(2,0);
    int ans = fabonacci(2);
    cout<<ans;
    return 0;
}

