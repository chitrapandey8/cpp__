#include <bits/stdc++.h>
using namespace std;


void Sortvowels(string &s){
    vector<int> upper(26,0);
    vector<int> lower(26,0);
    
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||s[i] == 'o' || s[i] == 'u'){
             lower[s[i] - 'a']++;
            }
            
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
              upper[s[i] - 'A']++;
            }
           
        }
    }

    string st = "";
    for(int i = 0; i < upper.size(); i++){
      while(upper[i]){
        st += i + 'A';
        upper[i]--;
      }
    }

    for(int i = 0; i < lower.size(); i++){
      while(lower[i]){
        st += i + 'a';
        lower[i]--;
      }
    }

     int i = 0;
     int j = 0;
     while(i < s.size() && j < st.size()){
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            s[i] = st[j];
            j++;
        }
        i++; 
     }

    
}


int main() {
    string s = "lYmpH";
    Sortvowels(s);
    cout<<s<<endl;
    return 0;
}