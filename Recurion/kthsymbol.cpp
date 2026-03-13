#include<bits/stdc++.h>
using namespace std;


int returnindes(int A, int B){
   if(A == 1){
     return 0;
   }

   int power = returnindes(A-1, (B+1)/2);
   if(B%2 != 0){
    return power; 
  } else{
    return power==0?1:0;
  }


}



int main(int argc, char const *argv[])
{
    
    int ans = returnindes(4,5);
    cout<<ans;
    return 0;
}
