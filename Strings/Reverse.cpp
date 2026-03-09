#include<bits/stdc++.h>>
using namespace std;

void reversE(string str){
   int ptr1 = 0;
   int ptr2 = str.size()-1;


   while(ptr1 < ptr2){
    swap(str[ptr1],str[ptr2]);
    ptr1++;
    ptr2--;
   }
   cout<< str<< endl;
}

void REVER(string str){
reverse(str.begin(),str.end());

int i = 0;
int j = 0;

while(j<str.size()){

    while(j< str.size() &&str[j] != ' '){j++;}
    int start = i;
    int end = j-1;
    while(start<end){
        swap(str[start] , str[end]);
        start++;
        end--;
    }

    i = j+1;
    j = i;

}

 cout<< str << endl;

}

int main()
{
    string str = "I like apple";
    // reverse(str.begin(),str.end());
    // cout<< str<< endl;
    REVER(str);
    
    return 0;
}
