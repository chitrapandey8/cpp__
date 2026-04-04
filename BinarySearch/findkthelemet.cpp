#include <bits/stdc++.h>
using namespace std;

int Count(vector<int>  arr, int num){  //find elements equal or less than num
    int no = 0;
    for(int x: arr){
       if(x <= num){
        no++;
       }
    }
    return no;

}

int main() {
    vector<int> arr{2, 8, 3, 11, 14};
    int k =  2;
    int ans  = 0;
    int start = *min_element(arr.begin(), arr.end());
    int end  = *max_element(arr.begin(), arr.end());

    cout<<start<<" "<<end<<endl;

    while(start <= end){
        int mid  = start + (end -  start)/2;

        int cnt  =  Count(arr, mid);

        if(cnt < k){
          start = mid +1;
        }else{
            ans = mid;
            end =  mid-1;
        }
    }

    cout<<ans<<endl;

    return 0;
}