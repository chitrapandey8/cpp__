#include <bits/stdc++.h>
using namespace std;


///string tokeninxzer
int main() {
  char s[100] = "Today is a rainy day";

  char *str = strtok(s," "); //it givest the first string, creates an aaray and puts a token today at firrrst

  cout<<str<<endl;
  
//   str = strtok(NULL, " "); //it gives thr next word, at ever funtion call
//   cout<<str<<endl;

while(str != nullptr){
    str = strtok(NULL, " ");
    cout<<str<<endl;
}

    
    return 0;
}