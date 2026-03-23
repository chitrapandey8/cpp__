#include <bits/stdc++.h>
using namespace std;

int main() {

    //mujhe 1 to 100 tak prime calculater karne h toh mai sabser phlel ek array bnaungi ismai sabko initialy sabko true rakhugi
    int  n  = 100;
    vector<bool> boo(n+1, true);

    for (int i = 2; i*i < boo.size(); i++) //ye wala loop posiible primes pe chlta hai,agar koi no prime hai toh uski ke hi posssible multiples false kargee, 
    {
        if(boo[i] == true){
            for (int j = 2*i; j < boo.size(); j = j+i) // or ye loop i ke multiple ke liye chltaahi or unhe false mark karta hai
       {
        boo[j] = false;
       }
        }
      
       
    }

    for (int i = 2; i < boo.size(); i++)
    {
       if(boo[i] == true){
        cout<<i<<endl;
       }
    }
    
    
    return 0;
}