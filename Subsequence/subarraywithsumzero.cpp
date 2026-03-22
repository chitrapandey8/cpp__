#include <bits/stdc++.h>
using namespace std;

bool brute(vector<int> arr){

    int n = arr.size();
    for(int i  = 0; i< n; i++){
        for(int j = i; j<n; j++){
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
              sum += arr[k];
            }
            if(sum == 0){
                return true;
                break;
            }
            
        }

    }
    return false;
    
}

bool presum(vector<int> ans){
    int n  = ans.size();
    vector<int> presum(n,0);
    presum[0] = ans[0];
    for (int i = 1; i < n; i++)
    { 
        presum[i] = presum[i-1] + ans[i];
    }

    for (int i = 0; i < n; i++)
    {

       for (int j = i; j < n; j++)
       {
        int sum = 0;
        if(i == 0){
            sum =  presum[j];
        }else{
        sum =  presum[j] - presum[i-1];
        }
        if(sum == 0){
            return true;
        }      
       }
       
    } 
    return false;
    
    
}

bool optimal(vector<int> arr){
  int n  = arr.size();
  unordered_set<int> hs;
  hs.insert(0);
  
   
  
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];


    if(hs.count(sum)){
        return true;
    }

    hs.insert(sum);
  }
  

  return false;
  

}

bool optimalll(vector<int> ans){
    int n = ans.size();
    unordered_set<int> hs;

    int sum = 0;
    for(int x: ans){
        sum += x;
        
        if(hs.count(sum)){
            return true;
        }

        hs.insert(sum);


    }
}




int main() {
    vector<int> arr{1,-1};
    if(optimalll(arr)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO";
    }


    return 0;
}