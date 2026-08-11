#include <bits/stdc++.h>
using namespace std;


 int calcu(vector<int> arr, int start , int end){
    int sum = 0;
    for(int i = start; i <= end; i++){
     sum += arr[i];
    }
    int maxvalue = *max_element(arr.begin()+start, arr.begin()+end+1);
    int ans = sum-maxvalue;
    return ans;
 }
 void ballons(){
string s = "aabaa";
    vector<int> arr = {1,2,3, 4, 1};
    int cnt = 0;
    bool flag = false;
    int ans = 0;
    int j = -1;
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
       if(s[i] == s[i+1]){
        if(!flag){
             j = i;
            flag =  true;
        }
       }else{
        if(flag){
            ans += calcu(arr, j, i);
            flag = false;
        }
       }
    }
    
    if(flag){
        ans += calcu(arr, j, n-1);
    }
    cout<<ans<<endl;
 }

void Tokens(){
    vector<int> arr = {100, 200, 300, 400};
    sort(arr.begin(), arr.end());
    int power = 200;
    int minval = -1;
    int score = 0;
    int n = arr.size();
    int index = -1;
    for(int i = 0; i<n; i++){
       if(arr[i] > minval && arr[i] <= power){
        minval = arr[i];
        break;
       }
    }
    arr.erase(arr.begin()+index+1);
    power  -= minval;
    score++;
    if(minval == -1){
        cout<<score<<endl;
    }

    for(int x: arr){
        cout<<x<<" ";
    }
    if(arr.size() == 1){
        if(arr[0] <= power){
            score = 1;
            cout<<score<<endl;
        }
    }else{
        int j = 0; 
        int maxvalue = -1;
        while(j<n){
            if(arr[j] <= power && arr[j] != maxvalue){
                score++;
            }else{
                power += arr[n-1];
                score--;
            }
            j++;
        }
    }
    
cout<<score<<endl;

    
}

void minlength(){
    string s = "aabccabba";
    int n = s.size();
    
    vector<int> p1(3,0);
    vector<int> p2(3,0);
    
    for(int i = 0; i<n/2; i++){
         
    }
 
    for(int x: p1){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int x: p2){
        cout<<x<<" ";
    }
    
    int cnt = 0;
    for(int i = 0; i<3; i++){
        if(p1[i] > 0 && p2[i] > 0){
            cnt += p1[i] + p2[i];
        }
    }
    int ans =  s.size() - cnt;
    cout<<ans<<endl;
}

int main() {
    
    minlength();
    return 0;
}