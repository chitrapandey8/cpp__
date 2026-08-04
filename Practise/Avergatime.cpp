#include <bits/stdc++.h>
using namespace std;

void AverageTime(){
 cout<<fixed<<setprecision(5)<<endl;
    vector<vector<int>> cus = {{5,2}, {5,4}, {10,3}, {20, 1}};
    int startT = cus[0][0];
    int endT = startT + cus[0][1];
    double WT = endT-startT;
    double size = cus.size();
    for(int i = 1; i<cus.size(); i++){
        if(cus[i][0] < endT){
           endT += cus[i][1];
           WT += endT - cus[i][0];
        }else{
            WT += cus[i][1];
        }  
    }
    cout<<WT<<endl;
    double ans = WT/size;
    cout<<ans<<endl;
}
bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}



void CountVowel(vector<int> &ans){
    vector<string> words = {"a","e","i"};
    vector<vector<int>> queries = {{0,2}, {0,1}, {2,2}};
    
    for(int i = 0; i<queries.size(); i++){
        int start = queries[i][0];
        int end = queries[i][1];
        int cnt = 0;
        for(int j = start; j<=end; j++){
            char c1 = words[j][0];
            char c2 = words[j][words[j].size()-1];
            if(isVowel(c1) && isVowel(c2)){
                cnt++;
            }
        }
        ans.push_back(cnt);
    }

    
 }

 void Optimised(vector<string> words, vector<vector<int>> queries, vector<int> &ans){
   vector<int> presum(words.size());
     char c1 = words[0][0];
     char c2 = words[0][words[0].size()-1];
     if(isVowel(c1) && isVowel(c2)){
        presum[0] = 1;
     }else{
        presum[0] = 0;
     }
   for(int i = 1; i<words.size(); i++){
      c1 = words[i][0];
      c2 = words[i][words[i].size()-1];
     if(isVowel(c1) && isVowel(c2)){
        presum[i] = presum[i-1]+1;
     }else{
        presum[i] = presum[i-1];
     }
   }

   for(int i= 0; i<queries.size(); i++){
     int s = queries[i][0];
     int e = queries[i][1];
     if(s == 0){
        ans.push_back(presum[e]);
     }else{
        ans.push_back(presum[e]-presum[s-1]);
     }
   }

 }

void CustomSort(){
    string order = "bcafg";
    string s = "abcd";

    vector<int> arr(26,0);
    for(int i = 0; i<s.size(); i++){
        arr[s[i] - 'a']++;
    }
    
    string ans = "";
    for(int i = 0; i<order.size(); i++){
        if(arr[order[i] - 'a'] > 0){
            ans += string(arr[order[i] -'a'],order[i]);
            arr[order[i] -'a'] = 0;
        }
    }
   for(int i = 0; i<arr.size(); i++){
     if(arr[i] > 0){
        ans += (i + 'a');
     }
   }
   cout<<ans<<endl;
}
int main() {
    // vector<string> words = {"aba","bcb","ece","aa","e"};
    // vector<vector<int>> queries = {{0,2}, {1,4}, {1,1}};
    // vector<int> ans;
    // Optimised(words, queries, ans);

    // for(int x: ans){
    //     cout<<x<<" ";
    // }
    CustomSort();
    return 0;
}