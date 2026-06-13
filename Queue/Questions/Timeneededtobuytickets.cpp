#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr, int k){
    int time = 0;
   for(int i = 0; i< arr.size(); i++){
     if(arr[i] > 0){
        arr[i]--;
        time++;
     }
     if(arr[k] == 0){
        return time;
     }
   }
   return time;
}

int stackk(vector<int> arr, int k){
    
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
    return time;

}

int main() {
    vector<int> arr = {1,5,2,3,7}; int k = 2;
    cout<<brute(arr,k)<<endl;

    
    
    return 0;
}