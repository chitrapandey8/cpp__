#include <bits/stdc++.h>
using namespace std;

string AddString(string no1, string no2){
    int i = no1.size()-1;  int j = no2.size()-1;
    int carry = 0;
    string  ans = "0";
    int place = 1;
    int var  =  1;
    while( i >= 0 && j >= 0){
        int sum = (no1[i] - '0') + (no2[j] - '0')  + carry;
        carry = sum/10;
        int addtostring = sum*place + (stoi(ans))%var;
        ans = to_string(addtostring);
        place = place*10;
        var = var*10;
        i--; j--;
        
    }
    while(i >= 0){
        int sum = (no1[i] - '0') + carry;
        carry = sum/10;
        int addtostring = sum*place + (stoi(ans))%var;
        ans = to_string(addtostring);
        place = place*10;
        var = var*10;
        i--;
    }
    while(j >= 0){
        int sum = (no2[j] - '0')  + carry;
        carry = sum/10;
        int addtostring = sum*place + (stoi(ans))%var;
        ans = to_string(addtostring);
        place = place*10;
        var = var*10;
        j--;
    }
    return ans;
    
}

string ADDSTRING(string no1, string no2){
    int index1 = no1.size()-1;
    int index2 = no2.size()-1;
    string ans = "";
    int carry  = 0;
    
    while(index1 >= 0 && index2 >=  0){
    int sum = (no1[index1] - '0') + (no2[index2] - '0') + carry;
     carry = sum/10;
     char c = '0' + (sum%10);
     ans += c;
     index1--;
     index2--;
    } 

    while(index1 >= 0){
     int sum = (no1[index1] - '0') + carry;
     carry = sum/10;
     char c = '0' + (sum%10);
     ans += c;
     index1--;
     
    } 
    while(index1 >= 0 && index2 >=  0){
     int sum = (no2[index2] - '0') + carry;
     carry = sum/10;
     char c = '0' + (sum%10);
     ans += c;
     index2--;
    } 


    if(carry){
        char c = '0' + carry;
        ans += c;
    }
    reverse(ans.begin(), ans.end());
   return ans;

}


int Tellint(char r){
   if(r == 'I'){
    return 1;
   }else if(r == 'V'){
    return 5;
   }else if(r == 'X'){
     return 10;
   }else if(r == 'L'){
     return 50;
   }else if(r == 'C'){
    return 100;
   }else if(r == 'D'){
    return 500;
   }else if(r == 'M'){
    return 1000;
   }
   return 0;
}

int RomantoInteger(string s){
    int i = 0;
    int ans = 0;
    while(i < s.size()){
           if(Tellint(s[i]) < Tellint(s[i+1])){
               ans += abs(Tellint(s[i]) - Tellint(s[i+1]));
               i++;
           }else{
            ans += Tellint(s[i]);
           }

        i++;
    }
    return ans;
}

int LSWRC(string s){
  unordered_map<char, int> hm;
  int i = 0;
  int maxlen = INT_MIN;
  for(int j = 0; j< s.size(); j++){
    hm[s[j]]++;
    while((j-i+1) != hm.size()){
      hm[s[i]]--;
      if(hm[s[i]]){
        hm.erase(s[i]);
      }
      i++;
    }

    
    maxlen = max(maxlen, j-i+1);
    
  }
  return maxlen;
}

int main() {
    string s = "pwwkew";
    int ans = LSWRC(s);
    cout<<ans<<endl;
    return 0;
}