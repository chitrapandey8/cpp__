#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string str){
int i = 0;
int j = str.size()-1;

while(i< j){
    if(str[i] != str[j]){
        return false;
    }
    i++;
    j--;
}
return false;

}

int expandanslen(string str, int i, int j){
int n  = str.size();
while((i>= 0  && j<n) &&str[i] == str[j]){
    i--; j++;
}

return j-i-1;

}


int main(int argc, char const *argv[])
{
    string s = "dcbaxabcf";
    int len  = 0;
    for(int i = 0; i<s.size(); i++){
     int len1 = expandanslen(s,i, i);
     int len2 = expandanslen(s,i,i+1);
     len = max({len,len1, len2});
    }
    
   cout << len << endl;
    return 0;
}
