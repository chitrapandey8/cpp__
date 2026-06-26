#include <bits/stdc++.h>
using namespace std;

class Person{
    public:
    int age;
    string name;
    
    ///object comparision ke liye 
    bool operator < (const Person &other) const{
        return age <other.age;
    } 
};

int main() {
    ////////pair
    // pair<string, int> p;
    // //method first to insert
    // p = make_pair("chitranshi", 45);
    // //method second to insert
    // p.first = "cjnfnr";
    // p.second = 4;


    // /////List
    // list<int> dll;
    // dll.push_back(30);
    // dll.push_back(40);
    // dll.push_back(50);
    // dll.push_back(60);

    // while (!dll.empty())
    // {
    //     cout<<dll.front()<<"->";
    //     dll.pop_front();
    // }

    ////iterator
    // for(auto it=  dll.begin(); it != dll.end(); it++){
    //     cout<<*it<<"<->";
    // }
    // for(auto it=  dll.rbegin(); it != dll.rend(); it++){ //last se start hoga 
    //     cout<<*it<<"<->";
    // }
    


     ////set---time complexity -- logn in insertion, deletion, search
     //set ki implementation avl tree se hoti h, sorted ordered mai store karke rakhta hai
    //  set<int> set;
    //  set.insert(2);
    //  set.insert(5);
    //  set.insert(1);
    //  set.insert(56);
    //  set.insert(23);
    //  set.insert(28);
    //  set.insert(18);



    //  if(set.find(2300) != set.end()){
    //     cout<<"Present"<<endl;
    //  }else{
    //     cout<<"NOt"<<endl;
    //  }

    //  for(auto it = set.begin(); it != set.end(); it++){
    //     cout<<*it<<" ";
    //  }

//    Person p1,p2,p3;
    
//    p1.age = 5;
//    p1.name = "CP";
//    p2.age = 10;
//    p2.name = "DP";
//    p3.age = 15;
//    p3.name = "EP";

//    set<Person> s;
//    s.insert(p1);
//    s.insert(p2);
//    s.insert(p3);

//    for(auto it = s.begin(); it != s.end(); it++){
//        cout<<it->age<<" "<<it->name<<endl;
//    }

   //multiset-- sorted but not unique
   
   ///MAp--implemented by avl tree -- time complexity of insertkon, deletion, searching is logn 
//    vector<int> arr = {3,2,4,2,3,3,2,4};
//    map<int, int> mp;
// //    for(int x: arr){
// //     mp[x]++; //inserts and updates
// //    }

//    for(auto it = mp.begin(); it != mp.end(); it++){
//     cout<<it->first<<" "<<it->second<<endl;
//    }

 //multimap ami unordered hoga or duplicates keys hogi

    return 0;
}