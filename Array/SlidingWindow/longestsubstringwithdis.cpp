// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s = "pwwkew";
//     int d = 0;
//     vector<int> dis(26,0);
//     for(int i = 0; i<s.size(); i++){
//         if(dis[s[i] - 'a'] == 0){
//             d++;
//              dis[s[i]-'a']++;
//         }else{
//              dis[s[i]-'a']++;
//         }
//     }

//     vector<int> vis(26,0);
//     int maxlen = INT_MIN;
//     int left = 0;
//     int index  = -1;

//     for(int right = 0; right < s.size(); right++){


//         while (vis[s[right] - 'a'])
//         {
//             vis[s[left] - 'a'] = 0;
//             left++;
//         }

//         vis[s[right] - 'a'] = 1;
//         maxlen = max(maxlen, right-left+1);
//         index = left;
//         }
        
    
//         string ans = s.substr(index , maxlen);
        
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,1,2,2,3,4};
    int target = 7;
    int n = arr.size();
    int i = 0; int j = n-1;
    int cnt  = 0;
    while(i <= j){
        if(arr[i] + arr[j] >= target ){
            cnt += j-i;
            j--;
        }else{
            i++;
        }
    }
cout<<cnt<<endl;

    return 0;
}