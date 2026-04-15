#include <bits/stdc++.h>
using namespace std;

int main() {
    string num1 = "26583";
    string num2 = "698";
    int carry = 0;
    string ans = "";
    int n = num1.size(); //badi string
    int m = num2.size(); //choti string
    int i = n-1;
    int j = m-1;
    while(j >= 0){
    int no = (num1[i] - '0') + (num2[j] - '0') + carry;
    carry = no/10;
    char c  =  '0' + no%10;
    ans +=  c;
    i--;
    j--;  
    }

    while(i >= 0){
    int no = (num1[i] - '0') + carry;
    carry = no/10;
    char c  =  '0' + no%10;
    ans +=  c;
    i--;  
    }

    if(carry){
        ans += carry;
     }

     reverse(ans.begin(), ans.end());
     cout<<ans<<endl;


    return 0;
}