#include <bits/stdc++.h>
using namespace std;


void  Threesum(vector<int> arr){
sort(arr.begin(), arr.end());
 int n =  arr.size();

 set<vector<int>> A;
 for(int i = 0; i<arr.size(); i++){
    int target = -arr[i];
     unordered_set<int> hs;
    for(int j  = i+1; j<n; j++){
        int num = target - arr[j];
        if(hs.count(num)){
            vector<int> a = {arr[i], num, arr[j]};
            A.insert(a);
        }
        hs.insert(arr[j]);
    }

}
for(vector<int> x: A){
    for(int a: x){
        cout<<a<<" ";
    }
    cout<<endl;
}

}

void TwoPointer(vector<int> arr){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n  = arr.size();
    for(int i = 0; i<n-2; i++){
        if(i > 0 && arr[i] == arr[i-1]){continue;}
    int j = i+1; int k = n-1;
    while(k < j){
        
        int sum = arr[i] + arr[j] + arr[k];
        if(sum == 0){
            while(j < k && arr[j] ==  arr[j+1]){j++;}
            ans.push_back({arr[i], arr[j], arr[k]});
         j++; k--;

        }else if(sum  > 0){
           k--;
        }else{
            j++;
        }
    }
}

for(vector<int> &x: ans){
    for(int a:x){
        cout<<a<<" ";
    }
    cout<<endl;
}
}

int main() {
    vector<int> arr = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    TwoPointer(arr);
    
    return 0;
}