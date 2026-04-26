#include <bits/stdc++.h>
using namespace std;
void even(int n){
    if(n % 2   != 0){
        n--;
    }
    if(n == 2){
        cout<<n<<endl;
        return;
    }
    even(n-2);
    cout<<n<<endl;
    
}

int main() {
    even(11);
    return 0;
}