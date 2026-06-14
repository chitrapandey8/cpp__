#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> arr, int k){
int n = arr.size();
int flips = 0;
for(int i = 0; i<=n-k; i++){
    if(arr[i] == 0){
     for(int j = i; j< i+k; j++){
         if(arr[j] == 0){
            arr[j] = 1;
         }else{
            arr[j] = 0;
         }
}
flips++;
}
}
int sum = 0;
for(int x: arr){
sum += x;
}

if(sum == n){
    return flips;
}


return -1;
}

int Better(vector<int> arr, int k){
int activeflips = 0;
int Tflips = 0;
vector<int> flipped(arr.size(),0);

for(int i = 0; i<arr.size(); i++){
    ///first check window is valid or not;
    if(i >= k){
        if(flipped[i-k] == 1){
            activeflips--;
        }
    }
     
    //check the current value of the element:
    if(activeflips%2 == 0 && arr[i] == 0 || activeflips%2 != 0 && arr[i] == 1){
        //check ki aage emeltms bache bhi hai windoe ke liye
        if(i+k > arr.size()){
            return -1;
        }

        Tflips++;
        activeflips++;
        flipped[i] = 1;
    }
   
}
 return Tflips;

}
int main() {
    vector<int> arr = {0,0,0,1,0,1,1,0}; int k = 3;
    cout<<Better(arr,k);

    return 0;
}