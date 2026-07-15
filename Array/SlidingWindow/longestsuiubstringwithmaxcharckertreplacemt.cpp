#include <bits/stdc++.h>
using namespace std;
//  AABABBA k =1
   // AABBBBA
   //AABB k = 2 if length 4-2 = 2 == k    
    
int Brute(string &s, int k){
   int maxlen = INT_MIN;
   for(int i = 0; i<s.size(); i++){
    int maxfreq = 0; unordered_map<char, int> hm;
    for(int j = i; j<s.size(); j++){
        hm[s[j]]++;
        maxfreq = max(maxfreq, hm[s[j]]);
        if((j-i+1) - maxfreq == k){
            maxlen = max(maxlen, j-i+1);
        }
    }
   }
return maxlen;
}   

int SlidingWindow(string &s, int k){
int maxlen = INT_MIN;
unordered_set<char> hs(s.begin(), s.end());

for(char c: hs){
    int l = 0; int count = 0;
    for(int r = 0; r <s.size(); r++){
        if(s[r] == c){
           count++;
        }
        
         while((r-l+1 - count) > k){
            if(s[l] == c){
                count--;
            }
            l++;
         } 

        maxlen = max(maxlen, r-l+1);

    }
}
return maxlen;
}

int slidingWindowO(string &s, int k){
    int maxlen = INT_MIN;
    int left = 0;
    int count = 0;
    unordered_map<char, int> hm;
    for(int right = 0; right<s.size(); right++){
          hm[s[right]]++;
          count = max(count, hm[s[right]]);
           while ((right-left+1) - count > k)
           {
            hm[s[left]]--;
            left++;
           }
        
          maxlen = max(maxlen, right-left+1);
    }

    return maxlen;

}

int main() {
    string s = "AABABBA"; int k = 1;
    cout<<slidingWindowO(s, k)<<endl;
    return 0;
}