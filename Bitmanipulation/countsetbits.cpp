#include <bits/stdc++.h>
using namespace std;

class Bits{
    public:
    int Countsetbits(int n){
     int cnt = 0;
    while(n){
        int last_bit = n&1;
        cnt += last_bit;
        n = n>>1;
    }
    return cnt;
    }


    int CountSetbits(int n){
    int cnt = 0;
    while (n)
    {
        n = n & (n-1);
        cnt++;
    }
    return cnt;
    }
    
    //check ith bit given a not n
    int checkithbit(int n, int i){
        if((n&(1<<i)) > 0){
          return 1;
        }else{
            return 0;
        }
        
    }

    //set setbit ith bit in a no. 
    int SetBits(int n, int i){
       int mask = 1<<i;
       return n | mask;
    }
     
    ///clean ith bit
    int Cleanithbit(int n, int i){
        int mask = ~(1<<i); 
        return n&mask;
    }

    ////Update the ith bit  n == 5, value to update
    int updatethebit(int n, int V, int i){
        int mask = ~(1<<i);
        int no = n&mask;

        return no | (V<<i);
    }

    ////9


};


int main() {
    Bits b = Bits();
    cout<<b.updatethebit(13,0,2);
    

    return 0;
}