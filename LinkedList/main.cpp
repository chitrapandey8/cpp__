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

Node* LinkedList(int n){

Node* newnode = new Node(1);
Node* head = newnode;
Node* curr = newnode;

for(int i = 2; i<=n; i++){
curr->next = new Node(i);
curr = curr->next;
}
return head;
}

void PrintLinkedList(Node* head){
Node* curr = head;
while(curr != nullptr){
    cout<<curr->data<<"->";
    curr = curr->next;
}

}

Node* Insertatbegin(Node* head){
Node* newnode = new Node(0);
newnode->next = head;
head = newnode;

return head;
}

Node* Insertatend(Node* head){
Node* newnode =  new Node(6);
Node* curr = head;
while(curr->next != nullptr){
    curr = curr->next;
}
curr->next = newnode;
return head;
}

Node* InsertAtPos(Node* head, int n){
    //what if the pos can be reached.
    //what if pos is 1.
      
    Node* curr = head;
    Node* newnode = new Node(100);
   
    for(int i = 1; i<n-1; i++){
         curr = curr->next;
    }
    
    newnode->next = curr->next;
    curr->next = newnode;

return head;

}

Node* DeletebyValue(Node* head, int val){
    Node* curr = head;
    while(curr->next != nullptr){
        if(curr->next->data == val){
            curr->next = curr->next->next;
        }curr = curr->next;}
    return head;
}

Node* InsertAtGivenData(Node* head, int val){
    Node* curr = head;
    while(curr != nullptr){
     if(curr->data == val){
      Node* newnode = new Node(101); //jab data mile tab hi new node create ho.   
      newnode->next = curr->next;
      curr->next = newnode;
     }
     curr  = curr->next;
    }
 return head;   
}

Node* Reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;

        head = prev;
    }

    return head;
}

int main() {
    
    Node* LL = LinkedList(5);
    Node* LL2 = Reverse(LL);
    PrintLinkedList(LL2);

    return 0;
}