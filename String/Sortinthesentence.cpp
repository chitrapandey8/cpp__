#include <bits/stdc++.h>
using namespace std;

int main() {
    string s =  "is2 sentence4 This1 a3";
    vector<string> st(10);
    int i = 0;
    string temp = "";
    int pos = 0;
    int count = 0;
    while(i < s.size()){
        if(s[i] == ' '){
           pos =  temp[temp.size()-1] - '0';
           temp.pop_back();
           st[pos] = temp;
           temp.clear();
           count++;
        }else{
            temp += s[i];
            
        }
       i++; 
    }
     if(!temp.empty()){
   pos = temp[temp.size()-1] - '0';
        temp.pop_back();
        st[pos] = temp;
        count++;
       
     }
    string ans = "";
    for(int i = 0; i<=count; i++){
        ans += st[i];
        ans +=  " ";
    }
    ans.pop_back();
    cout<<ans<<endl;
    return 0;
}