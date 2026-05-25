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


void printarr(vector<int> arr, int index){
    if(index  == arr.size()){
        return ;
    }
    
    cout<<arr[index]<<" ";
    printarr(arr, index+1);
    
}

int sumofarray(vector<int> arr, int index){
if(index  == arr.size()){
    return 0;
}

return arr[index] + sumofarray(arr, index+1);


}

int mininarray(vector<int> arr, int index){
    if(index == arr.size()-1){
        return arr[index];
    }

    return max(arr[index], mininarray(arr, index+1));
}

int main() {
    vector<int> arr = {1,2,3,4,0};
    cout<<mininarray(arr, 0);
    return 0;
}