#include<bits/stdc++.h>
using namespace std;



vector<int> shifting(vector<int> arr, int i){
 for(int j = i; j<arr.size()-1; j++){
    arr[j] = arr[j+1];
 }
  return arr;
}





int main()
{
    // vector<int> arr{4,3,2,7,6,-2};
    // int cnt  = 0;
    // for(int i = 0; i< arr.size(); i++){
    //  vector<int> a  = shifting(arr,i);

    //   int even  = 0;
    //   int odd = 0;
      
    //   cout<<endl;
      
    //  for(int j = 0; j<a.size()-1; j++){
    //     if(j%2 == 0){
    //         even += a[j];
    //     }else{
    //         odd += a[j];
    //     }
    //  }

    //   if(even == odd){
    //  cnt++;
    //  }
    // }
    // cout<<cnt<<endl;

    vector<int> arr{4,3,2,7,6,-2};
    
    vector<int> presumeven(arr.size(),0);
    presumeven[0] = arr[0];

    for(int i = 1; i<arr.size(); i++){
      if(i%2 != 0){
        presumeven[i] = presumeven[i-1];
      } else{
        presumeven[i] = presumeven[i-1] + arr[i];
      }
    }
    
    vector<int> presumodd(arr.size(),0);
    presumodd[0] = 0;
    
    for(int i = 1; i<arr.size(); i++){
        if(i%2 != 0){
            presumodd[i] = presumodd[i-1] + arr[i];
        }else{
            presumodd[i] = presumodd[i-1];
        }
    }

   
    
    int cnt  = 0;
    int n  = arr.size();
    for(int i = 0; i<arr.size(); i++){
     int even = 0;
    int odd = 0;

     if(i == 0){
        even = presumeven[n-1] - presumeven[i];
        odd = presumodd[n-1] - presumodd[i]; 
     }else if(i == n-1){
        even = presumeven[n-2];
        odd = presumodd[n-2];
     }else{
      even  = presumeven[i-1] + presumodd[n-1] - presumodd[i];
      odd   = presumodd[i-1] + presumeven[n-1] - presumeven[i];
     }
      
    if(even == odd){
      cnt++;
    }

    }

    cout<< cnt<<endl;
     
    




     


    return 0;
}


