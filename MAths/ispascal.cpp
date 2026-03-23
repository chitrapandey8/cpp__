#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> arr(n);
    
    for (int i = 0; i < n; i++)
    {
       arr[i].resize(i+1);
       for (int j = 0; j <= i; j++)
       {
         if(j == 0 || j == i){
            arr[i][j] = 1;
         }else{
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
         }
       }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    


    
 
    return 0;
}