#include <bits/stdc++.h>
using namespace std;

int countNumber(vector<int> arr, int pattern){
    int count = 0;
    for(int x: arr){
        if((x & pattern) == pattern){
            count++;
        }
    }
    return count;
}



int main() {
    vector<int> nums{4,8,12,16};
    int pattern  = 0;
    for (int i = 31; i >= 0; i--)
    {
       int count = countNumber(nums, pattern | (1<<i));
       if(count >= 2){
        pattern = pattern | (1<<i);
       } 
    }
    
    cout<<pattern<<endl;

    return 0;
}