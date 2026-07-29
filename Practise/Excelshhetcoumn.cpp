// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s = "AB";
//     int n = s.size();
//     int ans = 0;
//     int pow = 1;
//     while(n){
//         int nn = s[n-1] - 'A';
//         nn++;
//         ans = ans+nn*pow;
//         pow = pow*26;
//         s.pop_back();
//         n--;
//     }
//     cout<<ans<<endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 14;
    unordered_set<int> hs;
    hs.insert(2);
    hs.insert(3);
    hs.insert(5);
    for(int i = 2; i <n ;i++){
        if(n%i == 0){
            if(!hs.count(i)){
                cout<<"false"<<endl;
            }else{
                if(!hs.count(n/i)){
                    cout<<"false"<<endl;
                }
            }
        }
    }
    cout<<"True"<<endl;
    return 0;
}