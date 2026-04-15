#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 2;
   
    vector<int> arr(1,1);
    while(n>1){
         int carry = 0;
       for(int i = 0; i< arr.size(); i++){
        int res = arr[i]*n + carry;
        arr[i] = res%10;
        carry = res/10;
       }
       
       while(carry){
        arr.push_back(carry%10);
        carry = carry/10;

       }
       n--;
    }
    reverse(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<endl;
    }

    
    return 0;
}