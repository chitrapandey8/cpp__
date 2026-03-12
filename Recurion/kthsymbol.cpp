#include<bits/stdc++.h>
using namespace std;


string buildstring(string sr){
 string s = "";
 for(int i =0; i<s.size(); i++){
    char ch = s[i];
    if(ch == '0'){
       s += "01";
    }else{
       s += "10";
    }
 }
 return s;

}

int returnindes(string s, int i, int A, int B){
    if(i == A){
        return (int)(s[B] - '0');
    }

    string st = buildstring(s);
    return returnindes(st, i+1, A, B);
}

int main(int argc, char const *argv[])
{
    
   
    return 0;
}
