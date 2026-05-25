#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {4,3,2,1,2,7,6};
    int n = arr.size();
    for(int i= 0; i<n; i++){
        arr[i]--;
    }

    for(int i = 0; i<n; i++){
        arr[arr[i]%n] += n;
    }
    
    //missing
    for(int i = 0; i<n; i++){
        if(arr[i]/n == 0){
            cout<<i+1<<endl;
        }
    }

    for(int i = 0; i<n; i++){
        if(arr[i]/n == 2){
            cout<<i+1<<endl;
        }
    }
    return 0;
}