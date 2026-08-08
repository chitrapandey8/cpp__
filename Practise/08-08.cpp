#include <bits/stdc++.h>
using namespace std;

void Valid(){
    string s = " ";
    int n = s.size();
    int i = 0;
    int j = n-1;
    while(i <= j){
       if(s[i] == ' '){
          i++;
       }else if(s[j] == ' '){
        j--;
       }else if(!isalpha(s[i])){
         i++;
       }else if(!isalpha(s[j])){
          j--;
       }else{
        char c = tolower(s[i]);
        char t = tolower(s[j]);
        if(c != t){
            cout<<"false"<<endl;
            break;
        }
        i++; j--;

       }
       
       
      
    }
    cout<<"True"<<endl;
}

int main() {
    Valid();
    return 0;
}