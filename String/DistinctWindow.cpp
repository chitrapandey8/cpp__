#include <bits/stdc++.h>
using namespace std;
   
int main() {
    string s = "AABBBCBBAC";
    //first calculate all distince charactewrs in a string
    int first = 0;
    int second = 0;
    int diff = 0;
    int n  = s.size();
    int len = INT_MAX;
    vector<int> arr(256,0);
    while(first<n){
     if(arr[s[first]] == 0){
        diff++;
     }
     arr[s[first]]++;
     first++;
    }
    for(int i = 0; i<arr.size(); i++){
        arr[i] = 0;  
    }
    
    first = 0;
    while(second < n){

        while(diff && second <n ){
            if(arr[s[second]] == 0){
                diff--;
            }
            arr[s[second]]++;
            second++;
        }
        len = min(len, second-first);

        while(diff == 0){
            
                len = min(len, second-first);
        
         arr[s[first]]--;
         if(arr[s[first]] == 0){
            diff++;
         }
         first++;
        }
    

    }
    cout<<len<<endl;
    return 0;
}