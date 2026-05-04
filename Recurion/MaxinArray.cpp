#include <bits/stdc++.h>
using namespace std;

int MinelementinArray(vector<int> arr, int i){
    int n = arr.size();
if(i == n-1){
    return arr[i];
}
return min(arr[i], MinelementinArray(arr, i+1));
}

int main() {
    vector<int> arr = {45,4,6,7,3,6};
    cout<<MinelementinArray(arr, 0);
    return 0;
}