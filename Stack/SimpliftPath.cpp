#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "/home/user/Documents/../Pictures";
    int i = 0;
    int n = s.size();
    string temp = "";
    stack<string> st;
    while( i < n){
        while( i < n && s[i] == '/'){
            i++;
        }
       
            int j = i;
            while(j< n && s[j] != '/'){
               temp += s[j];
               j++;
            }
        
        
        if(temp == "."){
            
        }else if(!st.empty() && temp == ".."){
            st.pop();
        }else if(!temp.empty()){
          st.push(temp);
        } 

        temp.clear();
        i = j;
    }
    
    
  
    string ans = "";
    while(!st.empty()){
         ans = "/"  + st.top() + ans;
         st.pop();   
    }

    if(ans.empty()){
        ans = "/";
    }
   
 
    cout<<ans<<endl;

    return 0;
}