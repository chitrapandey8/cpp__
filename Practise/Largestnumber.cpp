#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2){
int n1 = s1.size(); int n2 = s2.size();
int i = 0, j = 0;
while (i < n1 && j< n2){
 
 if(s1[i] > s2[j]){
    return true;
 }else if(s1[i] < s2[j]){
    return false;
 }
 i++; j++;

}
return false;

}

int main() {
    vector<int> nums = {3,30,34,5,9};
    string ans = "";
    ans += to_string(nums[0]);
    for(int i = 1; i<nums.size(); i++){
        string a = "";
        a += to_string(nums[i]);
        
        string a1 = "";
        string a2 = "";
        a1 += a + ans;
        a2 += ans + a;
        if(comp(a1, a2)){
            ans = a1;
        }else{
            ans = a2;
        }
    }
    cout<<ans<<endl;
    return 0;
}