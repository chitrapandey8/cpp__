#include <bits/stdc++.h>
using namespace std;
int brute(string s){
int n = s.size();
    int len = 0;
    for(int i = 0; i< n; i++){
        for(int j = i; j< n; j++){
            unordered_set<char> hs;
            for(int k = i; k<=j; k++){
              if(hs.count(s[k])){
                break;
              }else{
              hs.insert(s[k]);
              
              }
                 
              
            }
            if(hs.size() == j-i+1){ //checkin hif the s is valid//
           len = max(len , j-i+1);
            }
            
        }
    }
    return len;
}

int slidingwindowwithhs(string s){
int n = s.size();
int i = 0;
unordered_set<int> hs;
int len = 0;
for(int j = 0; j<n; j++){

 if(hs.count(s[j])){
    hs.erase(s[i]);
    i++;
 }

hs.insert(s[j]);
len = max(len, j-i+1);


}
return len;
}

int slidingwihtarray(string s){
    int len = 0;
    int n = s.size();
    int i = 0;
    int j = 0;
    vector<int> arr(256,0);
    while(j < n){

        while(arr[s[j]]){
            arr[s[i]] = 0;
             i++;           
        }
        
        arr[s[j]] = 1;
        len = max(len,j-i+1);
        j++;

    }
    return len;
}

int main() {
    string s = "abcabcbb";
    cout<<slidingwihtarray(s)<<endl;
    
    return 0;
}