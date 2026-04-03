#include <bits/stdc++.h>
using namespace std;
//english, quant, logical reasnong, automata, persaonality, compiuter neyworks, op,coq, dbms, wittien english

int main() {
    vector<int> arr{4,2,0,3,2,5};

    int leftmax = 0;
    int rightmax = 0;
    int left = 0;
    int right = arr.size()-1;
    int water  = 0;

    while(left <= right){
        if(arr[left] <= arr[right]){
            if(arr[left] >= leftmax){
                leftmax =  arr[left];

            }else{
               water += leftmax - arr[left];
            }
            left++; 
        }else{
            if(arr[right] >= rightmax){
                rightmax =  arr[right];
            }else{
                water +=  rightmax -  arr[right];
            }
            right--;
        }
    }

    cout<<water<<endl;
    return 0;
}