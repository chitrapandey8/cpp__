#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
      this->data = data;
      this->next = nullptr;
      this->prev = nullptr;
    }
};

class Dequeue{
     
    Node *front, *rear;
    public:
    Dequeue(){
        rear = front = nullptr;
    }

    void push_front(int x){
        if(front == nullptr){
            front = rear = new Node(x);
            return;
        }
    }

};


int main() {
    return 0;
}