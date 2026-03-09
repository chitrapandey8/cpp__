#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;

    }
};

Node* LinkedList(int n){
    Node* newnode = new Node(1);
    Node* head = newnode;
    Node* curr = newnode;
    for (int i = 2; i <= n; i++)
    {
       curr->next = new Node(i);
       curr = curr->next;
    }
    return head;
    
}

void PrintList(Node* head){
    Node* curr = head;
    while(curr != nullptr){
     cout<<curr->data<<"->";
     curr = curr->next;
    }  
  cout<< endl;
}

int findsize(Node* head){
Node* curr = head;
int count = 0;
while(curr != nullptr){
count++;
curr = curr->next;
}
return count;
}

int main(){
    Node* linklist = LinkedList(10);
    PrintList(linklist); 
    int len   = findsize(linklist);
    cout<<len<<endl;
    

}