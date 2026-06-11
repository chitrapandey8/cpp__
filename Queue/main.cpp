#include <bits/stdc++.h>
using namespace std;
///////////////Implamention queue with array//////////////

class Queue{
public:
int *arr;
int rear;
int front;
int size;

Queue(int n){
    arr = new int[n];
    front = -1;
    rear = -1;
    size = n;
}


bool isEmpty(){
    return front == -1; //isempty
}

bool isFull(){
    return rear == size-1;
}

////push //to check empty front == -1 and to checkn full rear == n
void Push(int x){
    if(isEmpty()){
        front = rear= 0;
        arr[0] = x;
    }else if(isFull()){
     cout<<"Queue OverFlow"<<endl;
     return;
    }else{
        rear = (rear+1)%size;
        arr[rear] = x;
    }
}

void Pop(){
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
        return;
    }else{
       
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
             front= (front+1)%size;
        }
    }
}

int start(){
if(isEmpty()){
    cout<<"queue is Empty"<<endl;
    return -1;
}
    return arr[front];

}

};

int main() {
    Queue q(10);
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Pop();
    cout<<q.start()<<endl;

    return 0;
}