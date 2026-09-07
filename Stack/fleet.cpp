#include<bits/stdc++.h>
using namespace std;
 
int main(int argc, char const *argv[])
{
    vector<int> pos = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    int target = 12;
    vector<double> stack;
    vector<pair<int,int>> arr;
    for(int i = 0;i < pos.size(); i++){
        arr.push_back({pos[i], speed[i]});
    }

    sort(arr.rbegin(), arr.rend());
   
    for (auto it: arr){
        stack.push_back((double)(target - it.first)/it.second);
        if(stack.size() >= 2 && stack.back() <= stack[stack.size()-2] ){
            stack.pop_back();
        }
    }
    
    cout<<stack.size()<<endl;
    return 0;
}
