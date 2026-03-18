#include <bits/stdc++.h>
using namespace std;

int main() {
vector<vector<int>> arr{{2,3,4,3},{2,0,7,1},{6,5,8,1},{1,1,0,9}};

unordered_set<int> row;
unordered_set<int> col;
 
for (int i = 0; i < arr.size(); i++)
{
   for (int j = 0; j< arr[0].size(); j++)
   {
   if(arr[i][j] == 0){
    row.insert(i);
    col.insert(j);
   }}}
 

   //making row zero, row fix rahegi , column chnage;
   for(int r: row){
    for(int i = 0; i<arr[0].size(); i++){
        arr[r][i] = 0;
    }
   }

   for(int c: col){
    for (int i = 0; i < arr.size(); i++)
    {
       arr[i][c] = 0;
    }
    
   }

   for (int i = 0; i < arr.size(); i++)
   {
    for (int j = 0; j < arr[0].size(); j++)
    {
      cout<<arr[i][j];
    }
    cout<<endl;
    
   }
   

    return 0;
}