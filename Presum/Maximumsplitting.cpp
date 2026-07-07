#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "011101";
     
        int maxsum = 0;
        for(int i = 1; i<s.size()-1; i++){
        int sum0 = 0;
        int sum1 = 0;
         for(int j = 0; j <i; j++){
            if(s[j] == '0'){
                sum0++;
            }
         }
         cout<<"sum0:"<<" "<<sum0<<endl;
          for(int j = i; j<s.size(); j++){
            if(s[j] == '1'){
                sum1++;
            }
          }
          cout<<"sum1:"<<" "<<sum1<<endl;
         maxsum = max(maxsum , (sum0+sum1));
        }
        cout<<maxsum<<endl;

    return 0;
}