#include <bits/stdc++.h>
using namespace std;


void NBitBinary(int N, vector<string> &ans, string &temp, int zero, int one){

if(temp.size() == N){
    ans.push_back(temp);
    return;
}

if(zero < one){
    temp.push_back('0');
    NBitBinary(N, ans, temp, zero+1, one);
    temp.pop_back();
}

temp.push_back('1');
NBitBinary(N, ans, temp, zero,one+1);
temp.pop_back();

}


int main() {
    vector<string> ans;
    string temp = "";
    int zero = 0;
    int one = 0;
    int N = 4;
    NBitBinary(N,ans,temp,zero,one);
    
    
    for(string s: ans){
        cout<<s<<endl;
    }

    return 0;
}