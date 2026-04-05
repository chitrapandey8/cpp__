#include<bits/stdc++.h>
using namespace std;
class DynamicArray {

    private:
    int* arr;  //memory allocation ke liye.
    int sz;
    int cap; 

    public:

    DynamicArray() : cap(4), sz(0) {
        arr =  new int[cap];
    }

    ~DynamicArray(){
        delete[] arr;

    }

    int get(int i){
        if(i < 0 || i >= sz) throw out_of_range("Index out of range");
        return arr[i];
    }

    void set(int i, int val){
        if(i < 0 || i >= sz) throw out_of_range("Index out of range");
        arr[i] = val;
    }

    void push_back(int val){
        if(sz == cap){
            cap = cap*2;

            int* newArr = new int[cap];

            for(int i = 0; i<sz; i++){
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }

        arr[sz++] = val;
    }

    int back(){
        return arr[sz-1];
    }

    int size(){ return sz;}

    int capof(){
        return cap;
    }

};

int main(){

    DynamicArray DA;
    DA.push_back(3);
    
    cout<<DA.back();
     return 0;
}