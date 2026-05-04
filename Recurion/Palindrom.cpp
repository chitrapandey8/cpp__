#include <bits/stdc++.h>
using namespace std;

void IsPalindrom(string s, int i, int j){
    if(j<=i){
        cout<<"true";
        return;
    }

    if(s[i] != s[j]){
        cout<<"false";
        return;
    }

      return IsPalindrom(s, i+1, j-1);

}

int main() {
    string s = "mom";
    IsPalindrom(s, 0, s.size()-1);
    return 0;
}