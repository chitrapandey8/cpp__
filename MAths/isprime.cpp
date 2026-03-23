#include <bits/stdc++.h>
using namespace std;


bool isprimebrute(int n){
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
     if(n%i == 0){
        cnt++;
     }   
    }
    if(cnt == 2){
        return true;
    }
    return false;
}

bool anotheroptimised(int n){
    for (int i = 2; i < n; i++)
    {
       if(n%i == 0){
        return false;
       }
    }
    return true;
    
}

int main() {

    ///generate prime 1 to n iska optimisation hai siever of eratne..............
    //  for (int i = 1; i <= 100; i++)
    //  {
    //     if(isprimebrute(i)){
    //         cout<<i<<endl;
    //     }
    //  }
  

     
     

   
    // if(anotheroptimised(2)){
    //     cout<<"Prime"<<endl;
    // }else{
    //     cout<<"Not Prime"<<endl;
    // }

     return 0;
}