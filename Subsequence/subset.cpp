#include <bits/stdc++.h>
using namespace std;

void tellme(int no, vector<int> num){
    int j = num.size()-1;
    vector<int> ans;
    
    //ye zero or one ke basis pe batayeg ki konsa no ans mai push krna hai or konsa nhi
    while(no>0){
    int last_digit = no&1;
    if(last_digit == 1){
        ans.push_back(num[j]);

    }
    j--;
    no = no>>1;
    }

     

    for(int x: ans){
        cout<<x<<" ";
    }
    cout<<endl;


    int sum =  0;
    for(int x : ans){
   sum += x;
    }
    
    cout<<"this is sum";
    cout<<sum<<endl;



    
}

int tellsum(int no, vector<int> numm){
    int j = numm.size()-1;
    vector<int> ans;
    
    //ye zero or one ke basis pe batayeg ki konsa no ans mai push krna hai or konsa nhi
    while(no>0){
    int last_digit = no&1;
    if(last_digit == 1){
        ans.push_back(numm[j]);

    }
    j--;
    no = no>>1;
    }

    
    int sum =  0;
    for(int x : ans){
   sum += x;
    }

    return sum;
}


int main() {

     vector<int> arr{1,2,3};
     int n = arr.size();
     int totalsum = 0;
    for (int i = 0; i < (1<<n); i++)
    {
       tellme(i, arr);
       totalsum  += tellsum(i,arr);

    }

    cout<<totalsum<<endl;
    
    return 0;
}