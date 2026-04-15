#include <bits/stdc++.h>
using namespace std;

int numtell(char s){
  if(s == 'I'){
    return 1;
  }else if(s == 'V'){
    return 5;
  }else if(s == 'X'){
     return 10;
  }else if(s == 'L'){
     return 50;
  }else if(s == 'C'){
    return 100;
  }else if(s == 'D'){
    return 500;
  }else if(s == 'M'){
    return 1000;
  }
}

int main() {
    string  s = "MCMXCIV";
    int sum = 0;
    for(int i = 0; i<s.size()-1; i++){
        if(numtell(s[i]) < numtell(s[i+1])){
            sum += -numtell(s[i]);
        }else{
            sum += numtell(s[i]);
        }
    }
    sum += numtell(s[s.size()-1]);

    cout<<sum<<endl;
    return 0;
}