#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    
    }

    //find min or max elemet and then their indexx
    int maxele = *max_element(arr.begin(),arr.end());
    int minele = *min_element(arr.begin(), arr.end());

    int maxindex = -1;
    int minindex = -1;

    for(int i = 0; i<arr.size(); i++){
        if(arr[i] == maxele){
          maxindex = i;
          break;
        }
    }

    for(int i = 0; i<arr.size(); i++){
        if(arr[i] == minele){
            minindex = i;
            
        }
    }
    
    int len = arr.size()-1;
    int swaps = maxindex +  len - minindex;

    if(maxindex > minindex){
        swaps  = swaps-1;
    }

    cout<<swaps<<endl;

 

    return 0;
}