#include <bits/stdc++.h>
using namespace std;

void printt(int n){
    if(n == 0){
      return;
    }
    cout<<n<<endl;
    printt(n-1);
}

int main() {

     printt(5);
    return 0;
}