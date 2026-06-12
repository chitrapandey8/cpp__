#include <bits/stdc++.h>
using namespace std;


int Check(queue<int> q){
    while(!q.empty()){
        if(q.front() < 0){
            return q.front();
        }
        q.pop();
    }
    return 0;
}

vector<int> brtute(){
    vector<int> arr = {2,-3,-4,-2,7,8,9,-10}; int k = 3;
    //push k-1 elemets in queuee
     vector<int> ans;
    queue<int> q;
    for(int i = 0; i<k-1; i++){
        q.push(arr[i]);
    }

    for(int i = k-1; i<arr.size() ; i++){
        q.push(arr[i]);
        ans.push_back(Check(q));
        q.pop();
    }

    for(int x: ans){
        cout<<x<<endl;
    }
    return ans;
}

int main() {
    vector<int> arr = {2,-3,-4,-2,7,8,9,-10}; int k = 3;
   queue<int> q;
     
   for(int i =0 ;i <k-1; i++){ ///k-1 elemets ko push karao
     if(arr[i] <0 ){
        q.push(i);
     }
   }

   vector<int> ans;
   for(int i =k-1; i<arr.size(); i++){ 
        if(arr[i] <0){  //push only enagtive
        q.push(i);
     }
      ////agar queue empty hai toh psuh 0 in ans
      if(q.empty()){
        ans.push_back(0);  //store in ans, idf emoty toh zero
      }else{     //mainpush se pehlee check ki first windoe mia aat bhi h kua nhi ///check akro ki pop karkna hai kau nhi i-k
        if(q.front() < i-k){
            q.pop();
        }

        if(q.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(arr[q.front()]);
        }
    }
   }

   for(int x: ans){
    cout<<x<<" ";
   }
 
    return 0;
}