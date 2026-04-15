#include<bits/stdc++.h>
using namespace std;

int main(){
 vector<char> ch  {'S','n','A','K','e'};

 for(int i = 0; i<ch.size(); i++){
    if(ch[i] >= 'A' && ch[i] <= 'Z'){
        ch[i]  = ch[i] + 32;
    }else{
        ch[i] = ch[i] - 32;
    }
 }

 for(int i = 0; i<ch.size(); i++){
    cout<< ch[i] <<endl;
 }
}