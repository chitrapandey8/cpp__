#include <bits/stdc++.h>
using namespace std;

// void printArray(vector<int> arr, int i){
// int n = arr.size();
// if(i == n){
//     return;
// }

// printArray(arr, i+1);
// cout<<arr[i]<<endl;

// }

int SumofArray(vector<int> arr, int i){
    int n = arr.size();

    if(i == n){
        return 0;
    }

    return arr[i] + SumofArray(arr, i+1);

}


int main() {
    vector<int> arr = {1,2,3,4,5};
    cout<<SumofArray(arr, 0);
    return 0;
}