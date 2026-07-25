#include <bits/stdc++.h>
using namespace std;

int main() {
    string s ="01010";
    bool flag1 = false;
    bool flag2 = false;
    int zero = 0;
    string t = "1" + s + "1";
    int cnt = 0;
    int total = 0;
    int cnt1 = 0;
    cout<<t<<endl;
    for(int i = 0; i<t.size(); i++){
        if(!flag1 && t[i] == '1'){
          flag1 = true;
        }else if(!flag2 &&  t[i] == '0'){
          flag2 = true;
        }
        
        if(flag1 && t[i] == '0'){///agar mil gyaa hia already toh flag1 true hoga or agar aaab zero aaye toh s=count karo
          cnt++;
        }else if(flag1 && t[i] == '1'){
            total += cnt;
            cnt = 0;
        } 

        // if(flag2 && t[i] == '1'){
        //   cnt1++;
        // }else if(flag2 && t[]){

        // }


    }
    cout<<total<<endl;
    return 0;
}  