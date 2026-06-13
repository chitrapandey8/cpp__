#include <bits/stdc++.h>
using namespace std;

int Brute(vector<vector<int>> arr){
///jisbhi row ka sum 0 ho mtlb voh person kisi ko nhi janta, 

int col = -1;
bool flag  =false;
for(int i = 0; i< arr.size(); i++){
 int sum = 0;
 for(int j = 0; j<arr[0].size(); j++){
    sum += arr[i][j];
 }
 if(sum == 0){
  flag = true;
  col = i;
 }
}

if(flag){
int cnt = 0;
for(int i = 0; i <arr.size(); i++){
   cnt += arr[i][col];
}

if(cnt == arr.size()-1){
    return col;
}
}

return 0;

}

int Better(vector<vector<int>> arr){
//is aproach mai mai sare insaano ko stack mai daalungi or phir dod logo ko nikalke check karugi ki indono mai se celebrity kon ho sakta hai, jo ho sakta usko waaps stack mai daal dungi or dusre ko elemintae
stack<int> st;
for(int i = 0; i<arr.size(); i++){
st.push(i); //sabko stack mai dalo
}

int first, second;
while(st.size() > 1){
    first = st.top();
    st.pop();
    second = st.top();
    st.pop();

    //check karo kon celebrity ho skata
    if(arr[first][second] == 1 && arr[second][first] == 0){
        st.push(second);
    }else if(arr[first][second] == 0 && arr[second][first] == 1){
        st.push(first);
    }
}

if(st.empty()){
    return -1;
}

/////check celebritys row and col
int row = 0;
int col = 0;
for(int i = 0; i < arr.size(); i++){
    row += arr[st.top()][i];
    col += arr[i][st.top()];
}

if(row == 1 && col == arr.size()){
    return st.top();
}

return -1;
};

int TwoPointer(vector<vector<int>> arr){

    int top = 0;
    int down = arr.size()-1;

    while(top < down){
        if(arr[top][down] == 1){
            top++;
        }else{
            down--;
        }
    }

    int num = top;
    int row = 0;
    int col = 0;
    for(int i = 0; i < arr.size(); i++){
    row += arr[num][i];
    col += arr[i][num];
}

if(row == 1 && col == arr.size()){
    return num;
}
return -1;
}

int main() {
    vector<vector<int>> arr = {{1,1,0},{0,1,0},{0,1,1}};
    cout<<TwoPointer(arr);

    return 0;
}