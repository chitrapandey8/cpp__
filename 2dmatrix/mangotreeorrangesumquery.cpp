#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> matrixx = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int n = matrixx.size();
    int m  = matrixx[0].size();
    vector<vector<int>> matrix(n, vector<int> (m,0));
    

    for (int i = 0; i < matrixx.size(); i++)
    {
        for (int j = 0; j < matrixx[0].size(); j++)
        {
            int up  = i > 0 ? matrix[i-1][j] : 0;
            int down = j > 0 ? matrix[i][j-1] : 0;
            int dio = i > 0 && j > 0 ? matrix[i-1][j-1] : 0;
            matrix[i][j] = matrixx[i][j] + up + down - dio;
        }
    }


    ////////////queies///////////////////////
    int n1 = matrix.size();
    int m1 = matrix[0].size();
    int maxofmin = INT_MIN;
      for (int i = 0; i < matrix.size()-1; i++)
      {
        for (int j = 0; j < matrix[0].size()-1; j++)
        {
           int q1 = matrix[i][j];
           int q2 = matrix[i][m1-1] - q1;
           int q3 = matrix[n1-1][j] -  q1;
           int q4 = matrix[n1-1][m1-1] - (q1 + q2 + q3);
           int minn = min({q1,q2,q3,q4});
           maxofmin = max(minn,maxofmin);

        }
        
      }

      cout<<maxofmin<<endl;
      
    
    
     return 0;
}