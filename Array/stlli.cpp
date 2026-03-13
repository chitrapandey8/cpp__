//list is dll
//forward_list is sll;
//deque 

//conatainer adaptoers--queue,priority_queue,stack --provides a diffeerrnt interface

//associative container  set miltiset map multimap  impleted sorted data structure tahat can searc in logn

//unorederd map --unorded (set,multiset,map,multimap) -- implemewny unordered data structure taht can ne quickly searched



#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    
//     int arr[] = {1,2,3,3,3,3,4,4,5};

// int n = sizeof(arr)/sizeof(arr[0]);

// int key;
// cin>>key;


//liner
// auto it = find(arr,arr+n,key);
// int index = it - arr;
// cout<<index<<endl;

// bool present = binary_search(arr,arr+n,key);
// if(present){
//     cout<<"present";
// }else{
//     cout<<"absent";
// }

//lowerbound
// auto it   = lower_bound(arr,arr+n, key);
// ///cout<<(it-arr)<<endl;

// //upperbo
// auto up = upper_bound(arr,arr+n,key);

// cout<<(up-it)<<endl;

//string case not a data structue -- waraps charter array into string

// string s1;

// string s3(s2);

// string s4 = s3;

// char a[] = {'a','b','c'};
// string s5(a);

// cout<<s1;
// cout<<s2;
// cout<<s3;
// cout<<s4;
// cout<<s5;

// if(s2.empty()){
//     cout<<"Emty string"<<endl;
// }else{
//     cout<<"Not emoky";
// }

//remove
// cout<<s2.length()<<endl;
// s2.clear();
// cout<<s2.length()<<endl;

/////compare the strings
// string h = "Apple";
// string g = "hello";

//  cout<<h.compare(g) <<endl; // agar badr wale ko compare karra hu chote walr se toh 1 ayega warna -1;

//  if(h>g){
//     cout<<"Apple is greatet"<<endl;
//  }else{
//     cout<<"hellois greater";
//  }

// string s2("hello");
// cout<<s2[1];

////////find substring

// string s  = "I want to have apple juice";
// int ind  = s.find("apple");
// cout<<ind<<endl;


//remove a word from a string

// string word  = "apple";
// int len  = word.length();
// cout<<s<<endl;
// s.erase(ind,len+1);
// cout<<s<<endl;


/////////ITerratw over all tehhr charcyetrs int the string
string s1 = "chitranshi";
// for(int i = 0; i<s1.length(); i++){
// cout<<s1[i]<<endl;
// }


//ITerators
for(auto it  = s1.begin(); it!=s1.end(); it++){
cout<<(*it)<<",";
}
cout<<endl;

 return 0;
}


