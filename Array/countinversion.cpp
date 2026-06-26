#include <bits/stdc++.h>
using namespace std;

int insersionn(vector<int> a, vector<int> b){
    int cnt = 0;
    int i = 0; int j = 0;
    while (i < a.size() && j < b.size())
    {
     if(a[i] > 2*b[j]){
        cnt += a.size() - i;
        j++;
     }else{
       i++;
     }
    }
    return cnt;
    
}

void Merging(vector<int> a1, vector<int> b1, vector<int> &arr){
    
    int i = 0;
    int j = 0;
    int k = 0;

    while (i<a1.size() && j< b1.size())
    {
        if(a1[i] <= b1[j]){
            arr[k++] = a1[i++];
        }else{
            arr[k++] = b1[j++];
        }
    }

    while(i < a1.size()){
        arr[k++] = a1[i++];
    }
    while(j < b1.size()){
        arr[k++] = b1[j++];
    }

}


int MergeSort(vector<int> &arr){
///mere pass ek array ayega or mai uskko do array mai divide karugi phir usse merging ke liye bhje dungi
int count= 0;
int n = arr.size();
if(n == 1){
    return 0;
}

int n1  = n/2;
int n2 = n - n1;

vector<int> a1(n1);
vector<int> b1(n2);

for(int i = 0; i<n1; i++){
    a1[i] = arr[i];
}

for(int i = 0; i<n2; i++){
    b1[i] = arr[i+n1];
}



count += MergeSort(a1);
count += MergeSort(b1);

count +=  insersionn(a1,b1);


Merging(a1,b1, arr);
return count;

}

int main() {
    
    vector<int> arr = {2,4,3,5,1};
    cout<<MergeSort(arr)<<endl;
    

    return 0;
}