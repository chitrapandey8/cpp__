#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int* arr; 
    int front;
    int rear;
    int cs;
    int maxsize;
    Queue(int size){
        arr = new int[size];
        maxsize = size;
        front = 0;
        rear = 0;
        cs = 0;
    }

    void push(int data){
        if(!full()){
      arr[rear]  = data;
      rear  = (rear+1)% maxsize;
      cs++;
        }
        if(full()){
            cout<<"queue is full"<<endl;
        }
        

    }
    void pop(){
        if(!isempty()){
        front = (front+1)%maxsize;
        cs--;
        }
        
        
    }

    bool isempty(){
        return cs == 0;
    }
    bool full(){
        return cs == maxsize;
    }
    
    int top(){
        if(!isempty()){
            return arr[front];
        }
        
    }

};

int main() {

    Queue Q(5);
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(6);
    Q.push(8);

    while(!Q.isempty()){
    cout<<Q.top()<< " ";
    Q.pop();

    }

    return 0;
}