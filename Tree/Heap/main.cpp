#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    int *arr;
    int size;
    int total_size;
    public:
    MaxHeap(int n){
         arr = new int[n];
         size = 0;
         total_size = n;
    }

    ///insert into the heap;
    void insert(int val){
        //check if heap size is available
        if(size == total_size){
            cout<<"Heap Size not availabale"<<endl;
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        ////put tht element in its correct position, comapre it with its parent
        while(index > 0 && arr[(index-1)/2] < arr[index]){
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        };
        cout<<val<<" "<<"Element inserted"<<endl;
    }

      void print(){
        for(int i = 0; i< size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
      }

      void Heapify(int index){
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        
        //largets will store  the index of  the eleemt which is greater then left or right child
        if(left < size && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < size && arr[right] > arr[largest]){
            largest = right;
        }
        
        if(largest != index){ //aagar larger child mile toh
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }

        

      }

      void Delete(){
        if(size == 0){
            cout<<"Heap underflow"<<endl;
            return;
        }

        cout<<arr[0]<<"deleted from the HEap"<<endl;
        arr[0] = arr[size-1]; //replace the last element;
        size--;

        if(size == 0){
            return;
        }
        Heapify(0);
      }

};



int main() {
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(3);
    H1.insert(10);
    H1.insert(20);
    H1.insert(200);
    H1.insert(250);
    H1.print();
    H1.Delete();
    H1.print();
    return 0;
}
