#include <bits/stdc++.h>
using namespace std;

int main() {
       vector<int> arr = {1,5,2,3,7}; int k = 2;

    ///put all indess in queue and set time zero
    //bhahar nikalke ticket dedo, tiket--, time++
    //if tickets  == zero if kth person return perosn
    queue<int> q;
    for (int i = 0; i < arr.size(); i++)
    {
        q.push(i);
    }
    int time = 0;

    while(arr[k] != 0){
        arr[q.front()]--;
        if(arr[q.front()] != 0){
            q.push(q.front());
        }
        q.pop();
        time++;
    }
    cout<<time<<endl;
    
    return 0;
}