#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr, int target, int start, int end){
if(start > end){
    return 0;
}

int mid = start + (end - start)/2;

if(arr[mid] == target){
    return mid;
}

if(arr[mid] > target){
return BinarySearch(arr, target, start, mid-1);
}else{
    return BinarySearch(arr, target, mid+1, end);
}

}

int main() {
    vector<int> arr {2,4,6,8,10,11,12,14};
    int target = 2;
    cout<<BinarySearch(arr, target, 0, arr.size()-1);
    return 0;
}