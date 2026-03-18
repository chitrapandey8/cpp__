#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr{3,5,-10,2,6,4,-1,5,-3,7,-12,4};
    int sum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
     sum += arr[i];
     if(sum < 0){
        sum = 0;
     }
     maxsum  = max(maxsum,sum); 
    }
    cout<<maxsum<<endl;
    
    return 0;
}