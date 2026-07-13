#include <bits/stdc++.h>
using namespace std;

int main() {
    reverse(s.begin(), s.end());
     int i = 0;
    
    string ans = "";
    string temp = "";
    while(i<s.size()){
        while (s[i] == ' ')
        {
            i++;
        }
        
        int j = i;
            while (j< s.size() && s[j] != ' ')
            {   temp += s[j];
                j++;
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += " ";
            temp.clear();
            i = j+1;
    }
    cout<<ans<<endl;
    return 0;
}