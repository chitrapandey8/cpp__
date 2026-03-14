#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin>>a;
    
    vector<int> arr(a);
    for(int i = 0; i<a; i++){
        cin>>arr[i];
    }

    int start = 0;
    int end = arr.size()-1;
    
    bool flag = true;
    int sereja = 0;
    int dima = 0;
    while (start<=end){
      if(flag){
        if(arr[start] > arr[end]){
            sereja += arr[start];
            flag = false;
            start++;
        }else{
            sereja += arr[end];
            flag = false;
            end--;
        }
      }else{
         if(arr[start] > arr[end]){
            dima += arr[start];
            flag = true;
            start++;
         }else{
            dima += arr[end];
            flag = true;
            end--;
         }
      }
    }
    
     cout<<sereja<<" "<<dima;


    return 0;
}