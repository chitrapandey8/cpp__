#include <bits/stdc++.h>
using namespace std;

// int CountVowels(string s, int i,int n,int cnt){
// if(i == n){
//     return cnt;
// }
// if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
// cnt++;
// }
// return CountVowels(s, i+1, n, cnt);
// }

int CountVowels(string s,int i){
if(i == s.size()){
    return 0;
}

if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
    return 1 + CountVowels(s, i+1);
}else{
    return CountVowels(s,i+1);
}
}

int main() {
    string s = "mom";
    cout<<CountVowels(s,0);
    return 0;
}