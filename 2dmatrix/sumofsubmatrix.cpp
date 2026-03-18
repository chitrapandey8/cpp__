#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> input{{3,1},{-1,-2},{2,4}};


//    int totalsum = 0;
//     for (int rs = 0; rs < input.size(); rs++)
//     {
//        for (int cs = 0; cs < input[0].size(); cs++)
//        {
//            for (int re  = rs; re < input.size(); re++)
//            {
//             for (int ce = cs; ce < input[0].size(); ce++)
//             {
//                /////calculation sum 
//                 int sum = 0;
//                for (int i = rs; i <= re; i++)
//                {
//                 for (int j = cs; j <= ce; j++)
//                 {
//                  sum += input[i][j];
//                 }
                
//                }
//                totalsum  += sum;
               
//             }
            
//            }
           
//        }
       
//     }
//     cout<<totalsum<<endl;

       

//////optimal -------------------mai array ke har elemet pe ajungi or ye  check karungi ki ye ekemet sub matrix mai as a first element kitni baat aaya h (n-1-(i-1)), and ye hi eleemt as a last elemt kini sub mstrix mai aayaa h i+1 mai dono row or col wise check karugii
int sum = 0;
int n = input.size();
int m = input[0].size();
for (int i = 0; i < input.size(); i++)
{
   for (int j = 0; j < input[0].size(); j++)
   {
    sum += input[i][j]*(n-i)*(i+1)*(m-j)*(j+1);
   }
   
}
cout<<sum<<endl;


    
    return 0;
}