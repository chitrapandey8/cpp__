#include <bits/stdc++.h>
using namespace std;

//mujhe number of quries di ot mujhe batana hai ki usmai kitne prime hai or mai pehele usmai toh mai sive ko phele se hi pre co pute krlu, or phir mai preferd index ke hisab se upsa irteate kerke count rakhlu

int main() {
    
     int n = 100;
    vector<bool> prime(n+1, 1);
    prime[0] = prime[1] = 0;

        for(int i = 2; i*i< prime.size(); i++){
          if(prime[i] == 1){
            for(int  j = i*i; j< prime.size(); j = j+i){
                prime[j] = 0;
            }
          }
        }

        //query brutre force -- 3 se 10 loop laga de sieve pe
        // int cnt  = 0;
        // for (int i = 10; i <30; i++)
        // {
        //     if(prime[i] == true){
        //         cnt++;
        //     }
        // }

        ///optimisedisofprefixsum
        vector<int> presum(n+1,0);
        presum[0] = 0;
        presum[1] = 0;
         for (int i = 2; i < presum.size(); i++)
        {
            presum[i] = presum[i-1] + prime[i];
        }
        
        
        ///query
        int left = 1;
        int right = 10;
        
        int cnt = presum[right] - presum[left-1];
        
        
        
        cout<<cnt<<endl;
        return 0;



}
