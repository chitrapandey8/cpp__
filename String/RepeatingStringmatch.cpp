#include <bits/stdc++.h>
using namespace std;

bool KMP(string s, string t){ //t ko dhoondha hai s mai
int n =  t.size();
vector<int> lps(n,0);
int prefix = 0;
int suffix = 1;
while(suffix < n){
if(t[prefix] == t[suffix]){
    lps[suffix] = prefix+1;
    prefix++; suffix++;
}else{
    if(prefix == 0){
        lps[suffix] = 0;
        suffix++;
    }else{
        prefix = lps[prefix-1];
    }
}
}


int first = 0; int second = 0;
while(first < s.size() && second < t.size()){
    if(s[first] == t[second]){
        first++; second++;
    }else{
        if(second == 0){
            first++;
        }else{
            second = lps[second-1];
        }
    }
}

if(second == t.size()){
 return 1;
}

return 0;

}



int RSM(string a, string b){

    int repeat = 1;
    string  temp = "";
    temp += a;
    while(temp.size() < b.size()){
        temp += a;
        repeat++;
    }
    
    if(KMP(temp, b) == 1){
        return repeat;
    }
    
    
    if(KMP(temp+a, b) == 1){
        return repeat+1;
    }


    return -1;
}


int main() {
    string a = "abcd";
    string b = "cdabcdab";
    int ans = RSM(a,b);
    cout<<ans<<endl;
    
     
    return 0;
}