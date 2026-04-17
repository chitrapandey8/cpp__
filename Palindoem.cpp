#include <bits/stdc++.h>
using namespace std;
int main(){
string s = "aaaotcaakr";
string t = s;
int nn = t.size();
reverse(t.begin(), t.end());
s += '$';
s += t;
int  n = s.size();
vector<int> arr(n,0);
int i = 0;
int j = 1;
while(j<n){
if(s[i] == s[j]){
arr[j] = i+1; i++; j++;
}else{
if(i == 0){
arr[j] = 0; j++;
}else{
i = arr[i-1];
}
}
}
cout<<nn<<endl;
cout<<s<<endl;
cout<<nn-arr[arr.size()-1];
return 0;}
