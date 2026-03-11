#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    
  vector<int> ans{1,3,4,7,6,2,8};
  vector<vector<int>> ANS;
  int s = 17;
  for(int i = 0; i<ans.size()-2; i++){
    int x = ans[i];
    
    int find = s-x;
    unordered_set<int> hs;
    for(int j  = i+1; j<ans.size(); j++){
        int y = ans[j];
        if(hs.count(find-y)){
            vector<int> arr {x,y,(find-y)};
             ANS.push_back(arr);
        }
        hs.insert(y);
    }
   
  }
   for (int i = 0; i < ANS.size(); i++)
   {
    for (int j = 0; j < ANS[0].size(); j++)
    {
        cout<<ANS[i][j];
    }
    cout<<endl;
    
   }
   

    return 0;
}
