#include <bits/stdc++.h>
using namespace std;

void reachhome(int start, int home){
    if(start == home){
        cout<<"reached home"<<endl;
        return;
    }
    cout<<start<<endl;
    reachhome(start+1, home);
    
}

int main() {
    reachhome(1,10);
    return 0;
}