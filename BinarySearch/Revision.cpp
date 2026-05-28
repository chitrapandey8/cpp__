#include <bits/stdc++.h>
using namespace std;


class Revision{
public:
int BinarySearch(vector<int> arr, int target){
int start = 0;
int end = arr.size()-1;
while (start <= end)
{
    int mid = start + (end-start)/2;
    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] > target){
        end = mid-1;
    }else{
      start = mid+1;
    }}
return -1;
}


      int Fistandlast(vector<int> arr, int target){
        int lower = -1;
        int upper = -1;

        ///find lowerBound
        int start = 0; int end = arr.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(arr[mid] == target){
                lower = mid;
                end = mid -1;
            }else if(arr[mid] > target){
                 end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        
        int start1 = 0;
        int  end1 = arr.size()-1;
        while(start1 <= end1){
            int mid = start1 +(end1 - start1)/2;

            if(arr[mid] > target){
                upper = mid;
                end1 = mid-1;
            }else if(arr[mid] == target){
              start1 = mid+1;
            }
            else{
               start1 = mid +1;
            }
        }
        
        
        return upper-lower;
      }

    int Squareroot(int n){
        int start = 1;
        int end = n;
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(mid*mid == n){
                return mid;
            }else if(mid*mid < n){
               ans = mid;
               start = mid+1;
            }else{
                end =  mid-1;
            }
        }
        return ans;
    }
    
    int peakindex(vector<int> arr){
        int start = 0;
        int end = arr.size()-1;
        while(start<= end){
            int mid =  start + (end- start)/2;

            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }else if(arr[mid] < arr[mid+1]){
               start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return -1;
    }

};

int main() {
    Revision r = Revision();

    //First and last occurance:
    // vector<int> arr = {5,6,7,7,7,7,8,9,10};
    // cout<<r.Fistandlast(arr, 7);
    

    //squareroot
    // cout<<r.Squareroot(0);

    //peak Index
    vector<int> arr = {2,5,7,11,15,14,10,6,1};
    cout<<r.peakindex(arr);
    
    
    


    return 0;
}