#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> ans){
    int n = ans.size();
    sort(ans.begin(), ans.end());
for (int i = 0; i < n; i++)
{
  if(ans[i+1] != (ans[i]+1)){
        return ans[i]+1;
  }  
}
}

int hasset(vector<int> ans){
    int n = ans.size();
unordered_set<int> hs;
for(int x: ans){
    hs.insert(x);
}

for(int i = 1; i<=n; i++){
   if(!hs.count(i)){
     return i;
   }
}

}

int main() {
    vector<int> arr{1,2,3,5};
   int ann = hasset(arr);
   cout<<ann<<endl;
    return 0;
}