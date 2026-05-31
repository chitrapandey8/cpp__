#include <bits/stdc++.h>
using namespace std;

int cal(vector<int> arr,int sum){
if(sum == 0){
    return 1;
}
if(sum < 0){
    return 0;
}

int ans =  0;
for(int i = 0; i<arr.size(); i++){
    ans += cal(arr,sum-arr[i]);
}
return ans;
}


int main() {
    vector<int> arr = {1,5,6};
    int sum = 7;
    int ans = cal(arr,sum);
    cout<<ans<<endl;
    return 0;
}