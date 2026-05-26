#include <bits/stdc++.h>
using namespace std;

int SDW(string s){
int distinct = 0;
int len = s.size();
vector<int> freq(256,0);
for(int i = 0; i<s.size(); i++){
    if(freq[s[i]] == 0){
        distinct++;
    }
    freq[s[i]]++;
}


for(int i = 0; i<freq.size(); i++){
    freq[i] = 0;
}

int i = 0;
int j = 0;
while(j < s.size()){
   if(freq[s[j]] == 0){
    distinct--;
   }
    freq[s[j]]++;
    j++;
    while(distinct == 0){
        len = min(len, j-i);
        freq[s[i]]--;
        if(freq[s[i]] == 0){
            distinct++;
        }
        i++;
    }
 }

return len;
}

int KMP(string s){
int n =  s.size();
vector<int> lps(n,0);
int prefix = 0;
int suffix = 1;
while(suffix < n){
    if(s[prefix] == s[suffix]){
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
return lps[n-1];
}

int PatterMacthing(string s, string t){
  int m = s.size();
  int n = t.size();
  for(int i = 0; i < m-n; i++){
    int first = i;
    int second = 0;
    while(second < n){
        if(s[first] != t[second]){
            break;
        }else{
            first++; second++;
        }
        if(second == n){
            return first - second;
        }
    }
  }
  return -1;
}

int KMPPatterMatching(string s, string t){
    int n = t.size();
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
       
        }}}
        
   int first = 0;
   int second = 0;
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
    
   int ans = first - second;
   if(second == t.size()){
     return ans;
   }
   return -1;

}
int main() {
    string s = "abcdaabceaabceaabdop";
    string t = "aabceaabdo";
    int ans = KMPPatterMatching(s, t);
    cout<<ans<<endl;
    return 0;
}