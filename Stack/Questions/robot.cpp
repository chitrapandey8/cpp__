#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> pos = {1,5,6,20};
    vector<int> speed = {4,3,2,3};
    int distance = 1;
    vector<int, int> stack;

    int n = pos.size();
    for(int i = n-1; i >= 0; i--){

        while(!stack.empty()){
            if((stack.back().first - pos[i] <= distance) || stack.back().second < speed[i]){
                 break;
            }else{
                  break;
            }
        }

        if(stack.empty() || !((stack.back().first - pos[i] <= distance) || (stack.back().second < speed[i]))){
               stack.push_back({pos[i], speed[i]});
        }

    }
    cout<<stack.size()<<endl;
    return 0;
}