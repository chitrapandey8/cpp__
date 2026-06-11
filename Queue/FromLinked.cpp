#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data){
     this->data = data;
     this->next = nullptr;
    }
};

class Queue{
    Node *Front;
    Node *Rear;

    public:
    Queue(){
        Front = Rear =  nullptr;
    }

    bool isEmpty(){
        return Front == nullptr;
    }

    void Push(int x){
        if(isEmpty()){
            Front = new Node(x);
            Rear = Front;
            return;
        }else{
          Rear->next = new Node(x);
          Rear = Rear->next;
        }
    }

    void Pop(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return;
        }else{
            Node* temp = Front;
            Front = Front->next;
            delete temp;
        }
    }

    int Start(){
        if(isEmpty()){
            cout<<"isEmoty"<<endl;
            return -1;
        }else{
           return Front->data;
        } 
    }
};

int main() {
    Queue ll;
    ll.Push(2);
    ll.Push(3);
    ll.Pop();
    cout<<ll.Start()<<endl;
    return 0;
}