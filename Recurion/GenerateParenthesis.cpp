#include <bits/stdc++.h>
using namespace std;

void GenerateParen(int n, int left , int right, vector<string> &ans, string &temp){
if(left == n && right == n){
    ans.push_back(temp);
    return;
}
if(left < n){
    temp.push_back('(');
    GenerateParen(n, left+1, right, ans, temp);
    temp.pop_back();
}

if(right < left){
    temp.push_back(')');
     GenerateParen(n, left, right+1, ans, temp);
    temp.pop_back();
    }
}
int main() {
    int n = 3;
    int left = 0;
    int right = 0;
    vector<string> ans;
    string temp = "";
    GenerateParen(n,left, right, ans, temp);

    for(int i = 0; i<ans.size(); i++){
       cout<<ans[i]<<endl;
    }
    return 0;
    
}