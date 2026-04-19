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

int main() {
    
    Node* LL = LinkedList(5);
    Node* LL2 = Insertatend(LL);
    PrintLinkedList(LL2);

    return 0;
}