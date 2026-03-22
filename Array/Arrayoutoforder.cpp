#include <bits/stdc++.h>
using namespace std;


int outoforder(int i, vector<int> arr){
int n = arr.size();
if(i == 0){
    return arr[i] > arr[i+1];
}else if(i == n-1){
    return arr[i] < arr[i-1];
} else{
    return arr[i] > arr[i+1] || arr[i] < arr[i-1];
}

}

int main() {

    vector<int> arr{1,2,3,7,10,5,4,16,20};
    
    int largest = INT_MIN;
    int smallest  = INT_MAX;
    for(int i = 0; i<arr.size(); i++){

      if(outoforder(i,arr)){
      largest = max(largest,arr[i]);
      smallest = min(smallest,arr[i]);
      }

      
    }
    
    int n = arr.size();
    int i = 0;
    int j  = n-1;
    
    while (arr[i] < smallest)
    {
        i++;
    }
    

    while (arr[j] > largest)
    {
       j--;
    }
    
    cout<<i<<endl;
    cout<<j<<endl;

    return 0;
}