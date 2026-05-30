#include <bits/stdc++.h>
using namespace std;

void Permuatations(vector<int> arr, vector<vector<int>> &ans, vector<bool> &visited, vector<int> temp){
   if(arr.size() == temp.size()){
    ans.push_back(temp);
    return;
   }


    for(int i = 0; i<arr.size(); i++){
        if(visited[i] == 0){
            visited[i] = 1;
            temp.push_back(arr[i]);
            Permuatations(arr, ans, visited, temp);
            visited[i] = 0;
            temp.pop_back();

        }
    }
}

int main() {
    vector<int> arr = {1,2,3};
    int n = arr.size();
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(n,0);

    Permuatations(arr, ans, visited, temp);


    for(vector<int> i:ans){
       for(int a: i){
        cout<<a<<" ";
       }
       cout<<endl;
    }

    return 0;
}