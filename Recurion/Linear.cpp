#include <bits/stdc++.h>
using namespace std;

bool FindTarget(vector<int> arr, int target, int i){
if(i == arr.size()){
    return false;
}

if(arr[i] == target){
    return true;
}

return FindTarget(arr, target, i+1);

}

void linersearch(vector<int> arr, int index, int X){
    if(index == arr.size()){
        cout<<"NOT FOUND!";
        return;
    }

    if(arr[index] == X){
        cout<<index<<" "<<"Found"<<endl;
      return;
    }

    return linersearch(arr, index+1, X);
}

void BinarySearch(vector<int> arr, int start, int end, int target){
    if(start >= end){
        cout<<"Not found!"<<endl;
        return;
    }

    int mid = start + (end - start)/2;

    if(arr[mid] == target){
        cout<<"Found"<<" "<<mid<<endl;
        return;
    }

    if(arr[mid] > target){
        return BinarySearch(arr, start, mid-1, target);
    }else{
        return BinarySearch(arr, mid+1, end, target);
    }
}

int main() {
    vector<int> arr = {2,4,56,2,6,5,63};
    int target = 2;
    BinarySearch(arr,0, arr.size()-1, target);
    return 0;
}