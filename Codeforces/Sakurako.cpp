#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
      int testcases;
      cin>>testcases;

      while (testcases-->0)
      {
        int a;
        int b;
        cin>>a;
        cin>>b;
       
        if(a%2 == 0 && (b% 2 == 0)){
           cout<<"YES"<<endl;
      }else if(a%2 != 0){
         cout<<"NO"<<endl;
      }else{
          if(a != 0){
            cout<<"YES"<<endl;
          }else{
            cout<<"NO"<<endl;
          }
      }
    }
      
    


    return 0;
}
