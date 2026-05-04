#include <bits/stdc++.h>
using namespace std;
void LowerToUpper(string& s, int i){
if(i == s.size()){
    return;
}

s[i] = 'A' + s[i] - 'a';
LowerToUpper(s,i+1);
}

int main() {
    string s = "hello";
    LowerToUpper(s, 0);
    cout<<s<<endl;
    return 0;
}