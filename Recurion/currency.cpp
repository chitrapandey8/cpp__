#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> nums, int money){  ///find smaller than money
    int smaller = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
      if(nums[i] > smaller && nums[i] <= money){
          smaller = nums[i];
      }
    }
    return smaller;
    
}

int recursion(vector<int> arr, int money){
 if(money == 0){
    return 0;
 }
 
 int note = largest(arr, money);
 int total_note = 1 + recursion(arr, (money - note));
 return total_note;

}

int main() {
    vector<int> arr{1,2,5,10,20,50,100,200,500,2000};
    int ans = recursion(arr,5000);
    cout<<ans<<endl;
    return 0;
}