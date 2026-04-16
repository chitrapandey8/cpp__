#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "ABCDEABCD";
    int n = s.size();
    vector<int> arr(n,0);
    int i = 0;
    int j = 1;
    while(j < n){
        if(s[i] == s[j]){
            arr[j] = i+1;
            i++; j++;
        }else{
            if(i == 0){
                arr[j] = 0;
                j++;
            }else{
                i = arr[i-1];
            }
        }

        
    }
    cout<<arr[n-1]<<endl;
    return 0;
}