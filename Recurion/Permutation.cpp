#include<bits/stdc++.h>
using namespace std;

bool permutation(vector<int> num, int i, int j){
    if(i>=j){
        return true;
    }

    if(num[i] == num[j] && permutation(num, i+1, j-1)){
        return true;
    }else{
        return false;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr{1,2,3,1};
    int start = 0;
    int end = arr.size()-1;
    cout<<permutation(arr, start, end);
    return 0;
}
