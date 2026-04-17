#include <bits/stdc++.h>
using namespace std;
int main() {
    string s = "onionionon";
    string p = "onions";
    int n = p.size();
    vector<int> arr(n,0);
    int i = 0;
    int j = 1;
    while (j<n){
   if(p[i] == p[j]){
    arr[j] = i+1;
    i++; j++;
   }else{
    if(i == 0){
        arr[j] = 0;
        j++;
    }else{
        i = arr[i-1];
    }}}

    
    int first = 0;
    int second = 0;
    while(first < s.size() && second < p.size()){
        if(s[first] == p[second]){
            first++; second++;
        }else{
            if(second == 0){
              first++;
            }else{
                second = arr[second-1];
            }
        }
    }
    if(second == p.size()){
        cout<<true<<endl;
    }else{
        cout<<false<<endl;
    }
    
    return 0;
}