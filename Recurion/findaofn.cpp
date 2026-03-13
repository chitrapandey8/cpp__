#include <bits/stdc++.h>
using namespace std;


///solution1
int print(int a, int n){
    if(n == 0){
        return 1;
    }
    return print(a, n -1) * a;

}

int power(int a, int n){
    int product = 1;
    for(int i = 1; i<=n; i++){
        product *= a;
    }
    return product;
}

//solution 2
int printt(int a, int n){
 if(n == 0){
    return 1;
 }   
  
 int p = power(a, n/2);
 if(n%2 == 0){
    return p*p;
 }else{
    return a*p*p;
 }
}

int main(int argc, char const *argv[])
{
    int ans = printt(5,3); 
    cout<<ans ;
    return 0;
}


