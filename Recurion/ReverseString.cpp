#include <bits/stdc++.h>
using namespace std;

// string Reversee(string s, int i, int j){
//     if(j <= i){
//        return s;
//     }
//     swap(s[i], s[j]);
//     return Reversee(s, i+1,  j-1);
// }

void Reversee(string& s, int i, int j){
    if(j <= i){
       return;
    }
    swap(s[i], s[j]);
    return Reversee(s, i+1,  j-1);
}




int main() {
    string s = "h0";
    Reversee(s,0, s.size()-1);
    cout<<s<<endl;
    return 0;
}