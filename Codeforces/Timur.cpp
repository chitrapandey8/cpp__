#include <bits/stdc++.h>
using namespace std;

int main() {
   int testcase;
   cin>>testcase;
   

   while(testcase-->0){
    int a;
   int b;
   int c;
   int d;
   cin>>a;
   cin>>b;
   cin>>c;
   cin>>d;
    int count  = 0;

   if(b>a){
    count++;
   }
   if(c>a){
    count++;
   }
   if(d>a){
    count++;
   }

   cout<<count<<endl;
   }

   

    return 0;
}