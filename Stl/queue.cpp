#include <bits/stdc++.h>
using namespace std;

int main() {

    //queue is a ds whick follows lifo last in first out, follwed by whatsap in messing, the message that is send first eill be recied first,, used when we want to odering of elemet,
    //imp funton push ,pop ,front, empty
    queue<int> qu;

    for (int i = 0; i <=5; i++)
    {
        qu.push(i);
    }

    while (!qu.empty())
    {
        cout<<qu.front();
        qu.pop();
    }
    
    
    return 0;
}