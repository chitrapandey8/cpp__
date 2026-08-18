#include <bits/stdc++.h>
using namespace std;

void Print(int n){
    if(n == 0){
        return;
    }

    Print(n-1);
    cout<<n<<" ";
}

int sum(int n){
    if(n == 1){
        return n;
    }

    return  n + sum(n-1);
}

int factorial(int n){
  if(n == 1){
    return n;
  }
   return  n * factorial(n-1); 
}

int countdigits(int n){
    if(n == 0){
        return 0;
    }
    int no = n%10;
    n = n/10;
    return no + countdigits(n);
}

int Pow(int a, int n){
    if(n == 1){
        return a;
    }
    return a * Pow(a, n-1);
}

void ReverseaNumber(int num, int &ans){
  if(num == 0){
    return;
  }
   
  int rem = num%10;
  ans = ans*10 + rem;
  
  num = num/10;
  ReverseaNumber(num, ans);
  

}

int sumofArray(vector<int> &arr, int index){
    if(index == arr.size()){
        return  0;
    }
    
    return arr[index] + sumofArray(arr, index+1);
}

int maxii(vector<int> &arr, int index){
  if(index == arr.size()){
    return INT_MIN;
  }

  return max(arr[index], maxii(arr, index+1));
}

bool Check(string &s, int i){
   if(i > s.size()-1-i){
    return true;
   }
   if(s[i] != s[s.size()-1-i]){
    return false;
   }
   return Check(s, i+1);
}

bool Is(char s){
    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'){
    return true;}

    return false;
}

int countVowels(string s, int index){
   if(index == s.size()){
     
        return 0;
     
   }

   if(Is(s[index])){
    return 1 + countVowels(s, index+1);
  }else{
    return 0 + 
    countVowels(s, index+1);
  }

}

void ReverseString(string &s, int i){
    if(i > s.size()-1-i){
        return;
    }
    swap(s[i], s[s.size()-1-i]);
    ReverseString(s, i+1);
}


void Subseqences(string &s, int index, string &temp, vector<string> &ans){
  if(index == s.size()){
    ans.push_back(temp);
    return;
  }

  Subseqences(s, index+1, temp, ans);
  temp += s[index];
  Subseqences(s, index+1, temp, ans);  
  temp.pop_back();
  
}


int main() {
    string s = "abc";
    vector<string> ans;
    int index = 0;
    string temp = "";
    Subseqences(s, index, temp, ans);
    

    for(string s: ans){
        cout<<s<<" ";
    }
    return 0;
}