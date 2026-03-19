#include <bits/stdc++.h>
using namespace std;

int main() {
 vector<int> arr{1,2,3};
 int ans = 0;
 int sum = 0;
 for (int i = 0; i < 32; i++)
 {
    int A = 0;
    int B = 0;
    
    for(int x: arr){
       if((x & (1<<i)) != 0){ //yaha equlas to 1 nhi kargee kyukinye hya toh 0 return krta ya 2 ki power i;
        A++;
       }else{
        B++;
       }

    }
    int contri = A*B*(1<<i);
    sum  = sum+ contri;

    
 }
 cout<<sum<<endl;

 
    return 0;
}