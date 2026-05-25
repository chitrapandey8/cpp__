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
    }   return IsPalindrom(s, i+1, j-1);
}


void checkPalindrom(string s, int i, int j){
    if(i >= j){
        cout<<"YES"<<endl;
        return;
    }

    if(s[i] != s[j]){
        cout<<"NO"<<endl;
        return;
    }
    return checkPalindrom(s, i+1, j-1);
}

int cntvowels(string s, int index, int cnt){
    if(index == s.size()){
        return cnt;
    }

    if(s[index] == 'a' || s[index] == 'e' || s[index] == 'i' || s[index] == 'o' || s[index] == 'u'){
        cnt++;
    }

    return cntvowels(s, index+1, cnt);
}

int cntvowelss(string s, int index){
    if(index == s.size()){
        return 0;
    }

    if(s[index] == 'a' || s[index] == 'e' || s[index] == 'i' || s[index] == 'o' || s[index] == 'u'){
        return 1 + cntvowelss(s, index+1);
    }else{
        return cntvowelss(s, index+1);
    }
}

void Reversestring(string &s,  int i, int j){
    if(i >= j){
        return;
    }

    swap(s[i], s[j]);
    return Reversestring(s, i+1, j-1);
}

void convertlowertoupper(string &s, int index){
    if(index == s.size()){
        return;
    }

    s[index] = toupper(s[index]);
    return convertlowertoupper(s, index+1);

}

int main() {
    string s = "hello";
    convertlowertoupper(s, 0);
    cout<<s<<endl;
    return 0;
}