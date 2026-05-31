#include <bits/stdc++.h>
using namespace std;

int brute(int n, int k){
vector<int> arr;
for(int i=1;i<=n;i++){
    arr.push_back(i);
}

int index = 0;
while (arr.size() > 1)
{
    index = (index + k-1)%arr.size();

    arr.erase(arr.begin()+index);
}

 
 return arr[0];
}


int Recursive(int n, int k){
    if(n == 1){
        return 0;
    }

    return (Recursive(n-1,k)+k)%n;
}


int main() {
    int ans = Recursive(5,2)+1;
    cout<<ans<<endl;
    return 0;
}