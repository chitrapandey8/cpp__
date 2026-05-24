#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> num1 = {1,2,2,1};
    vector<int> num2 = {2,2};
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i < num1.size() && j < num2.size()){
        if(num1[i] < num2[j]){
            i++;
        }else if(num2[j] < num1[i]){
            j++;
        }else{
           ans.push_back(num1[i]);
           i++; j++;
        }
    }

    for(int x: ans){
        cout<<x<<" ";
    }
    return 0;
}