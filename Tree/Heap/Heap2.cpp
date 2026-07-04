#include <bits/stdc++.h>
using namespace std;


class Heapp{
    public:
    priority_queue<int> LeftMax;
    priority_queue<int, vector<int>, greater<int>> rightmin;

    void insertHeap(int &x){
        if(LeftMax.empty()){
            LeftMax.push(x);
            return;
        }

        if(x > LeftMax.top()){
            rightmin.push(x);
        }else{
            LeftMax.push(x);
        }

        BalanceHeap();
    }

    void BalanceHeap(){
    if(rightmin.size() > LeftMax.size()){
        LeftMax.push(rightmin.top());
        rightmin.pop();
    }else{
        //diffrence between left and right shoulf not be greater then 1
        if(rightmin.size() == LeftMax.size()-1){
            rightmin.push(LeftMax.top());
            LeftMax.pop();
        }
    }
    }

    double GetMedian(){
        if(LeftMax.size() > rightmin.size()){
            return LeftMax.top();
        }else{
            double ans = LeftMax.top() + rightmin.top();
            ans = ans/2;
            return ans;
        }
    }
};

void Heapify(vector<int> &a, int n, int index){
    int largest = index;

}

void MergetwoHeap(vector<int> &arr1, vector<int> &arr2, vector<int> &ans){
    ////mujhe ek merged heap banani hai dono max heaps ka toh mai kya kar sakti hu ki mai stl ka use karke, priority queue maintain kar sakte hai
    //dono array pe ek ek baar loop alagar queue mai insert kar denege toh, heap mai maintain rahega 
    ///complexity analysis --- arr1 se queue mai insert karne ki complexity nlogn hogi jaha n array ki size hai or logn push operation ka 
    //mai arr2 se queue mai insert karri hu toh mujhe mlog(m+n) lagea kyuki, mai queue se n+m elements ko ans array mai dalugngi toh uski complexit hogi (n+m)log(n+m);

    priority_queue<int> q;
    for(int x: arr1){
        q.push(x);
    }
    for(int x: arr2){
        q.push(x);
    }

    while(!q.empty()){
       ans.push_back(q.top());
       q.pop();
    }
}

///mai issi ko heapy method se bhi kar sakti hu --- mai dono array ko merge kardu rk aarraty mai or usko heapify kardu 
//heapipy


/////check if binary tree is max heap//////////////---count no. of nodes and go to every index to check its index and then also check if its parent is greater than childersa 

////BST to MAx Heap//////////////////


///Kth element in a MAtrix/////////
void KthsmallestinMAtrix(vector<vector<int>> mat, int n, int k){

vector<pair<int, pair<int, int>>> temp;
for(int i = 0; i< n; i++){
    temp.push_back(make_pair(mat[i][0], make_pair(i,0)));
}

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p (temp.begin(), temp.end()); 

int ans;
pair<int, pair<int, int>> Ele;
int i; int j;

while (k--)
{
    Ele = p.top();
    ans = Ele.first; //value
    i = Ele.second.first; //row number
    j = Ele.second.second; //col number
    if(j+1<n){
        p.push(make_pair(mat[i][j+1], make_pair(i, j+1)));
    }
}

}




int main() {
    vector<int> arr1 = {10, 5, 6, 2};
    vector<int> arr2 = {12, 7, 9};
    vector<int> ans;
    MergetwoHeap(arr1, arr2,ans);

    for(int x: ans){
        cout<<x<<" ";
    }
    return 0;
}
