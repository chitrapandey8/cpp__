#include <bits/stdc++.h>
using namespace std;

bool Find(vector<int> arr, int n, int index, int target){
    if(target == 0){
        return 1;
    }

    if(index == n || target < 0){
        return 0;
    }
  
    return Find(arr, n, index+1, target) || Find(arr, n, index+1, target - arr[index]);
}



int Findtarget(vector<int> arr, int index, int target){
    if(target == 0){
        return 1;
    }

    if(index == arr.size() || target == -1){
        return 0;
    }



    return Findtarget(arr, index+1, target) || Findtarget(arr, index+1, target-arr[index]);
}


int main() {
    vector<int> arr = {2,3,6};
    int target = 2;
    if(Findtarget(arr, 0, target)){
        cout<<"Present"<<endl;
    }else{
        cout<<"Not Present"<<endl;
    }
    
    return 0;
}