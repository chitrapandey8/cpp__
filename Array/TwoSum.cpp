#include <bits/stdc++.h>
using namespace std;

class TwoSum{
   public:
   unordered_map<int, int> mp;
   

   void add(int number){
    mp[0] = 1;
     mp[number]++;
   }
   
   void Print(){
    for (auto &it: mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
   }

   bool Find(int number){
       for (auto &it: mp){
        int diff = number-it.first;
        if(diff != it.first){
            if(mp.count(diff)){
                return true;
            }
        }else{
            if(mp[it.first] > 1){
                return true;
            }
        }
        
       }
       return false;
   }

};

int main() {
    TwoSum t;
    t.add(2);
    t.add(3);
    
    cout<<t.Find(2)<<endl;
    t.Print();
    return 0;
}