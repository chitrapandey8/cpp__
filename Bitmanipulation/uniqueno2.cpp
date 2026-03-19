#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr{7,6,5,4,5,7,4,8};
    int xorr = 0;
    for (int i : arr)
    {
        xorr = xorr^i;

    }
    

    int pos = 0;
    int temp = xorr;

    while ((temp&1) != 1)
    {
       pos++;
       temp = temp>>1;

    }


    
    int setA = 0;
    int setB = 0;

     for(int x: arr){
        if((x & (1<<pos)) == 0){
            setA = setA^x;
        }else{
            setB = setB^x;
        }
     }

     cout<<setA<<" "<<setB<<endl;

    
    

    return 0;
}