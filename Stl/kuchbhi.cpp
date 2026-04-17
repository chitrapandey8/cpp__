#include <bits/stdc++.h>
using namespace std;

int main() {
    int num  = 1;
    cout<<num<<endl;
    num++;
    cout<<num<<endl;
    int &temp = num;
    
    cout<<&num<<endl;
    cout<<&temp<<endl;
    temp++;
    cout<<temp<<endl;
    cout<<num<<endl;
    return 0;
}