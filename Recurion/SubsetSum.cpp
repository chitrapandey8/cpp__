#include <bits/stdc++.h>
using namespace std;

void Generate(vector<int> arr, int index, int n, vector<int> &ans, int sum){
    if(index == n){
        ans.push_back(sum);
        return;
    }
    
    ///yas
    sum += arr[index];
    Generate(arr, index+1, n, ans, sum);

     sum -= arr[index];
    //no
    Generate(arr, index+1, n, ans, sum);


}

int main() {
    vector<int> arr = {3,4,5};
    vector<int> ans;
    int sum = 0;
    Generate(arr, 0, 3, ans, sum);

    for(int x : ans){
        cout<<x<<endl;
    }
    return 0;
}