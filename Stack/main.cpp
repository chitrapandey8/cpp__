#include <bits/stdc++.h>
using namespace std;

/////////////////////IMPLEMENTATION????????????????
class Stack{
    int *arr;
    int top;
    int size;
    
    public:
    bool flag;

    Stack(int s){
        top = -1;
        size = s;
        arr = new int[s];
        flag = 1;

    }

    void push(int data){  
    if(top == size-1){
        cout<<"Stack OverFlow"<<endl;
        return;
    }else{
        top++;
        arr[top] = data;
        flag = 1;
    }}

    void pop(){
        if(top == -1){
            cout<<"Stack UnderFlow"<<endl;
            return;
        }else{
            top--;
            if(top == -1){
                flag = -1;
            }
        }  
    }

    int peek(){
        if(top == -1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
           return arr[top];
        
        
    }
    
    bool isEmpty(){
        return top == -1;
    }

     int isSize(){
        return top+1;
     }
};

int main() {
    Stack s(5);
    s.push(-2);
    cout<<s.peek()<<endl;

    return 0;
}