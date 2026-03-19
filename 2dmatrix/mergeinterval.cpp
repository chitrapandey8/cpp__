#include <bits/stdc++.h>
using namespace std;

int main() {
   vector<vector<int>> arr{{1,3},{2,6},{8,10},{15,18}};
   //checking if the interval is empty of not 
   if(arr.empty()){
    return {};
   }

   //sort the arr on the basis of start
   sort(arr.begin(),arr.end(),[](vector<int>& a, vector<int>& b){
    return a[0]<b[0];
   });

   ////writitng the condition, and inserting in new array
  vector<vector<int>> ans;
  for(auto& i:arr){
   if(ans.empty() || ans.back()[1] < i[0]){
    ans.push_back(i);
   }else{
    ans.back()[1] = max(ans.back()[1],i[1]);
   }
  }


  //printing
for (int i = 0; i < ans.size(); i++)
{
   for (int j = 0; j <ans[0].size() ; j++)
   {
   cout<<ans[i][j]<<" ";
   }
   
}



    return 0;
}