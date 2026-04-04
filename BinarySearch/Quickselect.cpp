#include <bits/stdc++.h>
using namespace std;

int PivotElement(vector<int> arr, int start , int end){
    int pivot =  arr[end];
    int i = start;

    for(int j = start; j <end; j++){

        if(arr[j] <= pivot){
           
           swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i] , arr[end]);
    return i;
}

int quickSelect(vector<int> arr, int start , int end, int k){
    if(start <= end){
        int p = PivotElement(arr, start, end);

        if(p == k-1){
            return arr[p];
        }else if(p>k-1){
            return quickSelect(arr, start , p-1, k);

        }else{
            return quickSelect(arr, p+1, end, k);
        }
    }
  return -1;
}

int main() {
    vector<int> arr{7, 3, 9, 3, 5, 8, 3, 1};
    int start = 0;
    int end = arr.size()-1;
    int k = 4;

    cout<<quickSelect(arr, start, end, k);
    


    return 0;
}