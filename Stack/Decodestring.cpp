#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "3[a2[c]]";
    int k = 0;
    int i = s.size()-1;
    string ans = "";
    string temp = "";
    while(i >= 0){
        if(s[i] == ']'){
            i--;
          while(s[i] >= 'a' && s[i] <= 'z'){
            temp += s[i];
            i--;
          }
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            while(s[i] >= 'a' && s[i] <= 'z'){
                temp += s[i];
                i--;
            }
        }

        if(s[i] == '['){
            k = s[i-1] - '0';
        }
        cout<<temp<<endl;
        reverse(temp.begin(), temp.end());
        string a = "";
        for(int j = 0; j<k;j++){
           a += temp;
        }
        
        if(a.size() == 0){
            ans = temp + ans;
        }
        ans =  a +  ans;
        temp.clear();
        k = 0;
        i--;

    }
    
    cout<<ans<<endl;
    return 0;
}