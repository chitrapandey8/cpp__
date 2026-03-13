#include <bits/stdc++.h>
using namespace std;

int main() {

    int a;
    cin>>a;
     
    vector<int> arr(a);
    for(int i = 0; i<a; i++){
        cin>>arr[i];
    }
    
    int rec = 0;
    int crime = 0;
    for(int i = 0; i< arr.size(); i++){
     if(arr[i] != -1){
        rec += arr[i];
     }else{
        if(rec <= 0){
            crime++;
        }else{
            rec--;
        }
     }
    }
    cout<<crime;

    
    return 0;
}