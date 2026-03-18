#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr){
sort(arr.begin(), arr.end());
int len = 1;
int maxlen = 0;
for (int i = 0; i < arr.size(); i++)
{
    if(arr[i+1] == (arr[i]+1)){
        len++;
        maxlen = max(maxlen,len);
    }else if(arr[i] == arr[i+1]){
   continue;
    }
    else{
        len = 1;
    }
}
return maxlen;

}

int optimal(vector<int> arr){
unordered_set<int> hs;
for(int x: arr){
   hs.insert(x);
}

int len = 0;
int maxlen = 0;
int no = 0;
for(int x: arr){
if(!hs.count(x-1)){
   len = 1;
   no = x+1;
   while (hs.count(no))
   {
      len++;
      no++;
      
   }
   maxlen = max(maxlen,len);
   
}
}
return maxlen;
}


int main() {
    vector<int> arr{3,5,7,7,4,1,2,6,9,10,12,11,13,20};
    int ans = optimal(arr);
    cout<<ans<<endl;

    return 0;
}