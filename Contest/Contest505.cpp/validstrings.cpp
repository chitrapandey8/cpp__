#include <bits/stdc++.h>
using namespace std;


void makeValidString(vector<string> &ans, string &temp, int n, int idx){
  if(idx == n){
     ans.push_back(temp);
     return;
  }
  
  
  temp.push_back('0');
  makeValidString(ans, temp, n, idx+1);
  temp.pop_back();
  temp.push_back('1');
  makeValidString(ans, temp, n, idx+1);
  temp.pop_back();


}

void makeValidString2(vector<string> &ans, string &temp, int n, int idx, int sum, int k){

  if(idx > 0 && temp[idx-1] == '1'){
    sum += idx-1;
  }

  if(idx == n  && sum <= k){
     ans.push_back(temp);
     return;
  }
   if(sum > k){
    return;
   }

  temp.push_back('0');
  makeValidString2(ans, temp, n, idx+1, sum, k);
  temp.pop_back();
  
  if(temp.back() != '1'){

      temp.push_back('1');
      makeValidString2(ans, temp, n, idx+1, sum , k);
      temp.pop_back();
      
  }


}

int main() {
    vector<string> ans;
    string temp = "";
    int n = 3;
    int idx = 0;
    int sum = 0;
    int k = 1;
   makeValidString2(ans, temp, n, idx, sum, k);


   for(string x: ans){
    cout<<x<<" ";
   }
     
    return 0;
}