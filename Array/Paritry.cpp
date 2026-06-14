#include <bits/stdc++.h>
using namespace std;

void TwoPointer(vector<int> &arr){
  int i = 0;
  int j = arr.size()-1;
//   while(i < j){
//     if(arr[i]%2 == 0){
//         i++;
//     }else if(arr[j]%2 != 0){
//         j--;
//     }else{
//         swap(arr[i], arr[j]);
//         i++; j--;
//     }
//   }
     
      while(i<j){
        //jab tak i ko even mile i++ krte jao
        //jab tak j ko odd mile j-- krte jao mtln i or j even odd ki positions fix karre hai
        while(i<j && arr[i]%2 == 0){i++;}
        while(i<j && arr[j]%2 != 0){j--;}
        if(i<j){
            swap(arr[i], arr[j]); i++; j--;
        }
      }
    
}

void inbilt(vector<int> &arr){

    partition(arr.begin(), arr.end(), [](int x){
        return x%2 == 0;
    });

}

int main() {
    vector<int> arr = {-3, -8, -5, 0,2, -9, -4, -7};
    TwoPointer(arr);
    for(int x: arr){
        cout<<x<<" ";
    }
    return 0;
}