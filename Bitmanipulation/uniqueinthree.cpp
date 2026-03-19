#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr{3,4,5,3,4,5,6,5,4,3};
    int n = arr.size();
    vector<int> freq(32,0);
   
    for (int i = 0; i < n; i++)
    {
         int num = arr[i];
         int j = 0;

        while(num>0){
     int lastbit = (num&1);
      if(lastbit == 1){
        freq[j]++;
      }
      j++;
      num = num>>1;
        }
        }
        
                int p = 1;
                int ans = 0;
                for(int x: freq){
                    ans = ans + (x%3)*p;
                    p = p<<1;
                }
    
                cout<<ans<<endl;
    return 0;
}