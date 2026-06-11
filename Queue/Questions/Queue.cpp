#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(11);
    q.push(13);

    
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}