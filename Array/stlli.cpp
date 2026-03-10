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
    
    int arr[] = {1,2,3,3,3,3,4,4,5};

int n = sizeof(arr)/sizeof(arr[0]);

int key;
cin>>key;


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
auto it   = lower_bound(arr,arr+n, key);
///cout<<(it-arr)<<endl;

//upperbo
auto up = upper_bound(arr,arr+n,key);

cout<<(up-it)<<endl;

 return 0;
}


