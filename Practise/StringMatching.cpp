#include <bits/stdc++.h>
using namespace std;

////////string matching/////////
bool Check(string s1, string s2){
 vector<int> lps(s1.size());
 int i = 0;
 int j = 1;
 while(j < s1.size()){
    if(s1[i] == s1[j]){
        lps[j] = i+1;
        i++; j++;
    }else{
        if(i == 0){
            lps[j] = 0;
            j++;
        }else{
            i = lps[i-1];
        }
    }
 }

  i = 0; j = 0;
  while(i < s1.size() && j< s2.size()){
    if(s1[i] == s2[j]){
        i++; j++;
    }else{
        if(i == 0){
            j++;
        }else{
            i = lps[i-1];
        }
    }
  }


  return i == s1.size() ? true : false;


}


int main() {
    vector<string> arr = {"mass", "as", "hero", "superhero"};
    if(Check("hero", "leetcode")){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}