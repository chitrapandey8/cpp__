#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    public:
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class StackL{
   Node *top;
   int size;

   public:
   StackL(){
    top = nullptr;
    size = 0;
   }

   void push(int data){

    Node* newnode = new Node(data);
    if(newnode == nullptr){
        cout<<"Stack overFlow"<<endl;
        return;
    }else{
    newnode->next = top;
    top = newnode;
    size++;
    }
   }

   void pop(){
    if(top == nullptr){
     cout<<"Stack UnderFlow"<<endl;
     return;
    }else{
    Node* temp = top;
    top = top->next;
    delete temp;
   }}

   int peek(){
    if(top == nullptr){
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
     return top->data;
   }

    bool isEmpty(){
        if(top ==nullptr){
            return 1;
        }
        return 0;
    }

    int issize(){
        return size;
    }
};

int main() {
   StackL s;
   s.push(2);
   cout<<s.peek()<<endl;
   cout<<s.isEmpty()<<endl;
   cout<<s.issize()<<endl;
    return 0;
}