// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s = "abcde";
//     string t = "a";
//     int n = s.size(); int m = t.size();
//         int i = 0; int j = 0;
//         while(i<n && j < m){
//              if(s[i] == t[j]){
//                 i++;
//                 j++;
//              }else if(s[i] != t[i]){
//                 i++;
//              }
//         }
//         int size = m-j;
//         cout<<size<<endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
     vector<vector<int>> arr;
     arr.push_back({1});
     arr.push_back({1,1});
      int numrow= 5-2;
           while(numrow--){

               int n =  arr.size();
               int size = arr[n-1].size();
               cout<<n<<" "<<size<<" ";
               vector<int> arr1(size+1, 1);
    
               for(int j = 1; j<arr1.size()-1; j++){
                  cout<<arr[n-1][j-1] + arr[n-1][j]<<endl;
                 arr1[j] = arr[n-1][j-1] + arr[n-1][j];
               }
    
            arr.push_back(arr1);
           }
     

     for(vector<int> a: arr){
        for(int aa: a){
            cout<<aa<<" ";
        }
        cout<<endl;
     }
    return 0;
}