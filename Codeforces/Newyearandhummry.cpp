#include <bits/stdc++.h>
using namespace std;

bool ispossible(int left, int mid){
  int count = 0;
  for (int i = 1; i <= mid; i++)
  {
   count += (5*i);
   if(count > left){
    return false;
  }
  }

  return true;
}


int main() {

   int a;
   cin>>a;
   int time;
   cin>>time;

     int start = 0;
     int end = a;
     int ans = -1;
     int lefttime = 240 - time;
     while(start <= end){
        int mid  = start + (end - start)/2;

        if(ispossible(lefttime,mid)){
          ans = mid;
          start = mid+1;
        }else{
            end = mid-1;
        }
     }
     cout<<ans;

    return 0;
}