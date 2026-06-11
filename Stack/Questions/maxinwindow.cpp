#include <bits/stdc++.h>
using namespace std;


void Brute(vector<int> arr, vector<int> &ans){
  int n = arr.size();
   for(int i = 0; i<n; i++){ //konse konse window size hai (1 se size of array tak);
      for(int j = 0; j<n-i; j++){ //no of windows, konsi window pe mai currently hu, for example j == 0 is first window of n no of window, j == 1 if second window of n no of windows
         int num = INT_MAX;
         for(int k = j; k < j+i+1; k++){
             num = min(num, arr[k]);}
         ans[i] = max(ans[i], num);
      }}
   
}

//makaing arraya of next smaller in right and left
void Better(vector<int> arr, vector<int> &ans){
    int n= arr.size();

    ////find next smaller int right
    vector<int> Right(n,n);
    stack<int> st;

    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            Right[st.top()] = i;
            st.pop();
        }
       st.push(i);
    }


    while(!st.empty()){
        st.pop();
    }
    ///find next smaller in left;
    vector<int> Left(n,-1);
    for(int i = n-1; i >=0; i--){
      while(!st.empty() && arr[st.top()] > arr[i]){
          Left[st.top()] = i;
          st.pop();
      }
     st.push(i);
    }

    ////now finding the window sizes for every element and updating the ans array
    for(int i = 0; i<n; i++){
        int windowsize = ((Right[i] - Left[i])-1);
        for(int j = 0; j<windowsize; j++){
            ans[j] = max(ans[j],arr[i]);
        }
    }}


void Optimized(vector<int> arr, vector<int> &ans){

    stack<int> st;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int index = st.top();  ///iski window size mujhe dhundnui hai, ye minimum eleemt hai jisko mujhe window size ke asscording update karna hai
            st.pop();
            if(st.empty()){   
               int range = i; //(i-(-1)-1) jab left exits nhi karta toh hum left ko -1 lete hai or meri ranhe 0 se i ho jati hai
               ans[range-1] = max(ans[range-1], arr[index]);
               
            }else{
                int range = i-st.top()-1;
                ans[range-1] = max(ans[range-1], arr[index]);
            }
        }
        st.push(i);
    }

    while(!st.empty()){
       int index = st.top();  ///iski window size mujhe dhundnui hai
            st.pop();
            if(st.empty()){   
               int range = n;
               ans[range-1] = max(ans[range-1], arr[index]);
               
            }else{
                int range = n-st.top()-1;
                ans[range-1] = max(ans[range-1], arr[index]);
            }
    }

    for(int i = n-2; i>= 0; i--){
        ans[i] = max(ans[i], ans[i+1]);
    }
}


int main() {
    vector<int> arr = {10,20,15,50,10,70,30};
    vector<int> ans(arr.size(),0);
     Optimized(arr, ans);

    for(int x: ans){
        cout<<x<<" ";
    }


    return 0;
}