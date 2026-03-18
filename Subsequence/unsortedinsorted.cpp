#include <bits/stdc++.h>
using namespace std;


vector<int> brute(vector<int> arr){
vector<int> num(arr.begin(), arr.end());
sort(num.begin(), num.end());
 
int n = arr.size();
int i = 0;
int j = n-1;

vector<int> ans;


    while(i< n && arr[i] == num[i]){
       i++;
    }
    
    while(j >= 0 && arr[j] == num[j]){
        j--;
    }



ans.push_back(i);
ans.push_back(j);

return ans;

}



bool outorder(int i, vector<int> arr){
    int n = arr.size()-1;
     if( i == 0){
        return arr[i] > arr[i+1];
     } else if(i ==  n){
        return arr[i] < arr[i-1];
     } else{
        return arr[i] > arr[i+1] || arr[i] < arr[i-1];
     }
}

int main() {
    
       vector<int> arr{1,2,3,7,10,5,4,16,20};
//     int n = arr.size();
//     int largest  = INT_MIN;
//     int smallest = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//      if(outorder(i,arr)){
//         largest = max(largest,arr[i]);
//         smallest = min(smallest,arr[i]);
//      }
//     }
//     cout<<smallest<<" "<<largest<<endl;

//    int left = 0;
//    int right = n-1;
//    while (arr[left] <= smallest)
//    {
//     left++;
//    }

//    while (arr[right] >= largest)
//    {
//    right--;
//    }
   
       
//     cout<<left<<" "<<right<<endl;
//     cout<<right-left+1<<endl;
    
     vector<int> hello = brute(arr);
     for(int x: hello){
        cout<<x<<" "<<endl;
     } 


    return 0;
}