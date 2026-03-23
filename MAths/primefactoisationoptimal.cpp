#include <bits/stdc++.h>
using namespace std;

int main() {
    int  n = 10;
vector<int> arr(n+1,0);

for (int i = 0; i < arr.size(); i++)
{
    arr[i]  = i;
}


for (int i = 2; i*i < arr.size(); i++)
{
    if(arr[i] == i){
       for (int j = i*i; j < arr.size(); j = j+i)
       {
        if(arr[j] == j){ //agar nhi mark hus hu atoh mark karna
            arr[j] = i;
        }
       }
       
    }
}

vector<int> ans;
int  num = n;
while(num>1){
    ans.push_back(arr[num]);
    num  = num/arr[num];
}

for(int x: ans){
    cout<<x<<endl;
}




    return 0;
}