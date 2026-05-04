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

int main() {
    vector<int> arr = {2,4,56,2,6,5,63};
    int target = 100;
    cout<<FindTarget(arr, target,0);
    return 0;
}