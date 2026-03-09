#include<bits/stdc++.h>
using namespace std;

void sortstring(string str){
vector<int> arr(26,0);

for(int i = 0; i<str.size(); i++){
    arr[str[i] - 'a']++;
}

for(int i = 0; i<arr.size(); i++){
    while(arr[i] != 0){
        cout<<(char)(i+'a');
        arr[i]--;
    }
}

}

int main()
{
     string str = "chitranshi";
    // sort(str.begin(),str.end());

    // cout<<str<<endl;

    sortstring(str);


    return 0;
}
