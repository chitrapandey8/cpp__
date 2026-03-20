#include <bits/stdc++.h>
using namespace std;

int main() {
    //list is like doubly linked list in java,//push_back, pop_back, pop front

    list<int> l;
    ////init
    list<int> l1{1,2,3,4,5};
    ///diffrent datatype
    list<string> l2{"apple","guave","mango","bananan"};
     
    //reverse
    l2.reverse();
    l2.push_back("pjkdnf");

    ////pop_front
    cout<<l2.front()<<endl;
    l2.pop_front();
 
    //add to the front of the list
    l2.push_front("chitee");


    // for(auto it = l2.begin(); it != l2.end(); it++){
    //     cout<<(*it)<<endl;
    // }

    ///some more funcions in the list::::
    l2.push_back("carrot");
    l2.push_back("tejasvi");
    

    //removing
    // string f;
    // cin>>f;
    // l2.remove(f);

    //removing one or more elememt
    auto it = l2.begin();
    it++;it++; ///second elemt will be removed;
    l2.erase(it);

    //we can insert elemets int he lsit
    it = l2.begin();
    it++;
    l2.insert(it,"ddddddd");


    for(auto s: l2){
        cout<<s<<"-->";
    }
    return 0;
    

}