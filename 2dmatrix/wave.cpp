#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print(vector<vector<int>> &nums)
    {
        for (vector<int> x : nums)
        {
            for (int y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }

    void wave(vector<vector<int>> arr)
    {

        int n = arr[0].size();
        int m = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << arr[j][i] <<" ";
                }
            }
            else
            {
                for (int j = m - 1; j >= 0; j--)
                {
                    cout << arr[j][i] <<" ";
                }
            }
            cout<<endl;
        }

        print(arr);
    }
    
    void spiral(int n){
        vector<vector<int>> arr(n, vector<int>(n,0));
        int left = 0; int right = n-1; int top = 0; int bottom = n-1;
        int count= 1;
        
        while(left <= right && top <= bottom){
            for(int i = left; i<=right; i++){
             arr[top][i] = count;
             count++;
            }
            top++;
            

            for(int i = top; i<= bottom; i++){
                arr[i][right] = count;
                count++;
            }
            right--;
            

            if(top <=  bottom){
                for(int i =right; i>=left; i--){
                arr[bottom][i] =count;
                count++;
                }
                bottom--;
            }

            if(left<= right){
                for(int i = bottom; i>=top; i--){
                    arr[i][left] = count;
                    count++;
                }
            }
            left++;


        }
        print(arr);

    }
    void mangotress(vector<vector<int>> arr){
        int n =  arr.size();
        int m = arr[0].size();
        vector<vector<int>> presum(n,vector<int> (m,0));
        
        for(int  i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int  up = i > 0 ? presum[i-1][j] : 0;
                int down = j > 0 ? presum[i][j-1] : 0;
                int dio = i> 0 && j >0  ? presum[i-1][j-1] : 0;
                presum[i][j] = arr[i][j] + up + down - dio;
            }
        }

        print(presum);
         
        int ans = 0;
        for(int i  = 0; i<n-1; i++){
            for(int j = 0; j<m-1; j++){
                int q1 = presum[i][j];
                int q2 = presum[i][m-1] - q1;
                int q3 = presum[n-1][j] - q1;
                int q4 = presum[n-1][m-1] - (q1 +q2 + q3);
                int minoframu =  min({q1, q2, q3, q4});
                ans  = max(ans, minoframu);
                
            }
        }
        cout<<ans<<endl;

    }

    void rotateby90(){
        
    }

};

int main()
{
    vector<vector<int>> arr{{2,5}, {6,3}};
    int n = arr.size();
    Solution s;
    s.mangotress(arr);
    return 0;
}