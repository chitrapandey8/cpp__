#include <bits/stdc++.h>
using namespace std;
void display(queue<int> q){
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();

    }
    cout<<endl;
    
}

int main() {
    vector<int> arr = {3,6,2,7,8,11};
    int k = 3;
    ////q mai k-1 elemets ko push karao, or iteration k-1 se chalo karo
    
    queue<int> q;
    for(int i = 0; i<k-1; i++){
     q.push(arr[i]);
    }
   cout<<q.size();
    for(int i = k-1; i<arr.size(); i++){
        q.push(arr[i]);
        //print karao
        display(q);
        q.pop(); ///front wale ko pop karo
    }
    return 0;
}