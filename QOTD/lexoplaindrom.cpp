#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "z";
    vector<int> arr(26,0);
    for(int i = 0;i <26; i++){
        arr[s[i] - 'a']++;
    }

    string ans = "";
    int odd = -1;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] > 0 &&  arr[i]%2 == 0){
          int n = arr[i]/2;
          ans += string(n,  'a' + i);
        }else if(arr[i] > 0 && arr[i]%2 == 1){
            odd = i;
        }
    }

    string another = "";
    for(int i = 0; i<arr.size(); i++){
        if(arr[i]%2 == 0){
          int n = arr[i]/2;
          another += string(n,  'a' + i);
        }
    }

    reverse(another.begin(), another.end());
    string oddstieng = "";
    if(odd >= 0){
        oddstieng = string(arr[odd], 'a' + odd);
    }
    
    string a = "";
    if(odd >= 0){
     
     a += ans;
     a += oddstieng;
     a += another;
    }else{
     a += ans;
     a += another;
    }
    
    cout<<a<<endl;
    return 0;
}