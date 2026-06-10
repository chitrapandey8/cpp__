#include <bits/stdc++.h>
using namespace std;

////create node for addind node
class Node{
    public:
    int index;
    Node* next;
    Node(int i){
        this->index = i;
        this->next = nullptr;
    }
};

class NStack{
///create members first
  public:
  int *arr; //Dyamic array of intergers
  Node **Top; ///Dyani=mic array of Node Pointers

  int size;  //size of array
  int n;  //no of stacks
  stack<int> st; //stack for free memories

  NStack(int n, int size){
    arr = new int[size];
    Top = new Node*[n];

    //Intialise the stack with all the indexs
    for(int i=0;i<size; i++){
        st.push(i);
    }

    //Intialise Top with nullptr, initailly it does not contain any address of any node

    for(int i = 0; i<n; i++){
        Top[i] = nullptr;
    }}


    ////Push the data in nth stack,--- data and the no of stack will be passed with he function
    bool Push(int data, int m){ // m is no of stack here
        if(st.empty()){
            return 0; ///stack mai koi index hi nhi hai data dalne ke liye array mai
        }
       ///agar index available hai toh data dalo pehele araay mia 
       arr[st.top()] = data;
       //new node banake node daalo
       Node* newnode = new Node(st.top());
       newnode->next = Top[m-1];
       Top[m-1] = newnode;
       cout<<"Done"<<endl;
       return 1;
       
    }
   
     void DisplayArray(){
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
     }

     //Now Pop the element, also return it
     int Pop(int m){
        if(Top[m-1] == nullptr){
            return 0;
        }
        
         st.push(Top[m-1]->index); //ye index aab khali hora hai
         int ele = arr[Top[m-1]->index];

         Top[m-1] = Top[m-1]->next;

         return ele;
     }
     

};




int main() {
    NStack t(3,10);
    cout<<t.Push(2,1)<<endl;
    cout<<t.Pop(1)<<endl;

    return 0;
}