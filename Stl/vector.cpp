#include <bits/stdc++.h>
using namespace std;

int main() {

      ///vector can go and shrink in size
      //INttialising vector
    //   vector<int> arr;
    //   vector<int>  brr(5,1);
    //   vector<int> c(brr.begin(), brr.end());
    //    vector<int> d{1,2,3,4,5};

    //    //itration over vector
    //    for(int i = 0; i<d.size(); i++){
    //     cout<<d[i]<<endl;
    //    }
       
       //another way
    //  for (auto it = d.begin(); it!= d.end();  it++)
    //  {
    //   cout<<*it<<" ";
    //  }

     //third way
    //  for(int x:d){
    //     cout<<x<<endl;
    //  }
     
    // vector<int> a;
    // int n;
    // cin>>n;
    // for(int i = 0; i<n; i++){
    //     int no;
    //     cin>>no;
    //     a.push_back(no); //add elemet at the end of vector also expaNDS the memory
    // }

    // for(int x: a){
    //     cout<<x<<endl;
    // }

    // cout<<a.capacity()<<endl; //size of underlying array 
    // cout<<a.max_size()<<endl; //max no of elemets a vectoer  can hold, according to system memery
      

    ////methodss
    // vector<int> a{1,2,3,4,5};
    // a.push_back(6);
    // a.pop_back(); //removes the ;ast method

    // ////Insert some elemet in the middle
    // a.insert(a.begin() + 3,4444); //insert after 3rd leemt\
    

    // ////erase some elemet form the moddle
    // a.erase(a.begin()+ 3);

    //  ////erase range of elemets
    // //  a.erase(a.begin()+ 2,a.begin()+5);

    // //we avoid shrink
    // a.resize(8);  //puts zero at rest places
    // cout<<a.size()<<endl;
    

    // //removes the elemts but doest dlete the memory
    // a.clear();



    // for(int x:a){
    //     cout<<x<<endl;
    // }

    //eleemt at the front
    // cout<<a.front();
    // //last elememnt
    // cout<<a.back();

    //REserve--
    vector<int> b;
    int n; cin>>n;

    b.reserve(10); //it does not change the capacity till you reach 10; it will remain same;
    for(int i  =0; i<n; i++){
        int no; cin>>no;
        b.push_back(no);
    }

    for(int i = 0; i<b.size(); i++){
        cout<<b[i]<<endl;
    }

      return 0;
}