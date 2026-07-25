#include <bits/stdc++.h>
using namespace std;

int main() {
   
   vector<int> arr = {1,2,3};
   int num = 0;
   for(int x: arr){
    num = num*10 + x;
   }
   num++;
    vector<int> ans;
    while(num){
        int last_digit = num%10;
        ans.push_back(last_digit);
        num = num/10;
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans){
        cout<<x<<" ";
    }

    return 0;
}