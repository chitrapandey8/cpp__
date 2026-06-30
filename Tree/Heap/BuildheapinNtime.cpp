#include <bits/stdc++.h>
using namespace std;

////heapy mai hum last parent nikalte hai or usko child se comapre akrte hai agar child bada aaye toh bade childe swap 
void Heapify(vector<int> &arr, int n, int i){
    
    while(true){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            Heapify(arr, n, largest);
        }else{
            break;
        }

    }}

void BuildmaxHeap(vector<int> &arr, int n){
    for(int i = (n/2)-1; i >=0; i--){
        Heapify(arr, n, i);
    }
}    

    


void Print(vector<int> arr, int n){
    for(int i = 0;i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

///how do i insert new elemeent in the heap
void insertinHeap(vector<int> &arr, int val){
    ///last mai hum array mai pushback krte hai elelemt ko phir uske parent se compare krte jate hai jab tak ya voh voh zero par na pohoch gye ya phir loop break na ho ajye agar voh already apbi sahi positionpe hai
    arr.push_back(val);

    int index = arr.size()-1;
    
    while (index>0)
    {
        int parent  = (index-1)/2;
         if(arr[index] > arr[parent]){
            swap(arr[index], arr[parent]);
            index = parent;
         }else{
            break;
         }

    }
}

int DeleteinHeap(vector<int> &arr){
    int n = arr.size();
    int maxx = arr[0];

    arr[0] = arr[n-1];
    arr.pop_back();
    n = arr.size();

    int i = 0;
    while (true)
    {
        ///man lere ki jo largest hum left or right child mai dhoodhn rahe hai voh already apni position pe hai
        int largest = i;
        //abb iske left or right child dhidho
        int left = 2*i+1;
        int right =  2*i+2;
        //ab check karo ki left ya right child mai se koi bada hai 
        if(left  < n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }

         if(largest != i){ ///agar largest change hogaya toh swap karo mtlb bada mil gaya hame
            swap(arr[largest], arr[i]);
            i = largest;
         }else{
            break;
         }
    }
    return maxx;

}


///Heap sort/////////-- heap sort mai hum last or first element ko swap kar deter hai phir 0 se leke n-1 bache elemeents pe hepify  lagate hai



int height(vector<int> arr){ //u have to count number of edgess
int n = arr.size(); 
if(n ==  1){return 1;} ///time complexity would be logn
int h = 0;
while (n>1)
{
 n = n/2;
 h++;   
}

return h;}

/////minimum cost of ropess//////////////
void minicost(vector<int> &arr){
    priority_queue<int, vector<int>, greater<int>> p;

    for(int i = 0; i<arr.size(); i++){
        p.push(arr[i]);
    }

    int cost = 0;
    while(p.size() > 1){
        int rope = p.top(); //do ko lo add karo sum karo phir usse queue mai push bhi kakrdo
        p.pop();
        rope += p.top();
        p.pop();
        cost += rope;
        p.push(rope);
    }
    cout<<cost<<endl;

}

void Maxchochlate(vector<int> &arr, int ntime){ ////ntime*logn
    priority_queue<int> p;
    for(int x: arr){
        p.push(x);
    }
    int ans = 0;
    while (ntime && !p.empty())
    {
        ntime--;
        int maxx = p.top();
        p.pop();
        ans += maxx;
        p.push(maxx/2);

    }
    
    cout<<ans<<endl;

}
void LastStoneWight(vector<int> &arr){
    priority_queue<int> p;
    for (int i = 0; i < arr.size(); i++)
    {
        p.push(arr[i]);
    }

    while(p.size() > 1){
        int max1 = p.top();
        p.pop();
        int max2 = p.top();
        p.pop();
        int left = abs(max1-max2);
        if(left>0){

            p.push(left);
        }
    }
    cout<<p.top()<<endl;}



void ProfitMaximixation(vector<int> &arr, int time){
    priority_queue<int> p;
    for(int x: arr){
        p.push(x);
    }

    int profit = 0;
    while (time && !p.empty())
    {   time--;
        int top = p.top();
        p.pop();
        profit += top;
        if(top-1){

            p.push(top-1);
        }
        
    }
    cout<<profit<<endl;
    
}

void KthSmallest(vector<int> &arr, int k ){ ///tc--(n +  klogn) --min hwap se , max heap se nlogk (which is more optimised), heap ka size isami k hai isliye nlogk but klogn  mai n size ki heap banri ahii
    // priority_queue<int, vector<int>, greater<int>> p;
    // for(int x: arr){
    //     p.push(x);
    // }
    // while(k > 1){
    //     p.pop();
    //     k--;
    // }
    // cout<<p.top()<<endl;


    ///by max heap
    priority_queue<int> p;
    for(int i = 0; i<k; i++){
        p.push(arr[i]);
    }

    for(int i = k; i<arr.size(); i++){
        if(arr[i]<p.top()){
            p.pop();
            p.push(arr[i]);
        }
    }
    cout<<p.top()<<endl;
}



int main() {
    //  vector<int> arr  = {10,20,30,40,13,15,18,3,4};
    // vector<int> arr = {4, 7, 9, 10}; //maxchocclate
    // vector<int> arr = {2,7,4,1,8,1}; 
    // vector<int> arr = {6,4,2,3}; profit maximization
    vector<int> arr = {10,3,7,4,8,9,2,6};
    int n = arr.size();
    // BuildmaxHeap(arr,n);
    Print(arr,n);
    KthSmallest(arr, 4);
    return 0;
}