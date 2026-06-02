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

Node* Create(int n){
    Node* newnode = new Node(1);
Node* head = newnode;
Node* curr = head;

for(int i = 2; i<=n; i++){
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


}

Node* InsertAtStart(Node* head){
    Node* newnode = new Node(0);
    newnode->next = head;
    head  = newnode;
    return head;
}

Node* InsertAtEnd(Node* head){
    if(head == nullptr){
        Node* newnode = new Node(1);
        head  =  newnode;
    }else{
        Node* curr =  head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new Node(11);
    }
    return head;
}


Node* InsertAtEndd(vector<int> arr){ //create and insert at end
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i <arr.size(); i++){
        if(head == nullptr){
            head = new Node(arr[i]);
            tail = head;
        }else{
        //     Node* curr =  head;
        // while(curr->next != nullptr){
        //     curr = curr->next;
        //}
        // curr->next = new Node(arr[i]);

        //u can also write this way
        tail->next =  new Node(arr[i]);
        tail =  tail->next;
        }
    }
    return head;
}

Node* createByRecursion(vector<int> arr, int index, int size){  ///we returing the address
    if(index == size){ //tc - O(n)
        return nullptr;
    }

    Node* temp;
    temp = new Node(arr[index]);
    temp->next = createByRecursion(arr, index+1, size); //jo bhi adres createbyrecursuion laake dega voh hum temp.next mai daal denge
    return temp;
}

Node* createbyrecuratstart(vector<int> arr, int index,int size, Node* prev){

      if(index == arr.size()){
        return prev;
      }

    Node* temp;
    temp = new Node(arr[index]);
    temp->next = prev;
    return createbyrecuratstart(arr, index+1, size, temp);
}

Node* InsertArpos(int pos, int data, Node* head){
Node* curr = head;
for(int i = 1; i<pos; i++){
    curr = curr->next;
}
Node* newnode = new Node(data);
newnode->next = curr->next;
curr->next = newnode;
return head;
}


Node* DeleteANode(Node* head){  //firstNode
if(head == nullptr){
    return nullptr;
}

//first way------------------------------
// Node* temp = head;
// head = head->next;
// temp->next = nullptr;

//another way-----------------------------
head = head->next;
return head;

}

Node* Deletetheend(Node* head){
    if(head->next == nullptr){
      head = nullptr;
      return nullptr;   
    }

    Node* curr = head;
    while(curr->next->next != nullptr){
      curr = curr->next;
    }
    curr->next = nullptr;
    return head;

}

Node* Deletebydata(Node* head, int data){


if(head == nullptr){
    return nullptr;
}

if(head->data == data){
    Node* temp = head;
    head  =  head->next;
    delete temp;
    return head;
}
Node* curr = head;
while(curr->next != nullptr &&  curr->next->data != data){
    curr = curr->next;
}

Node* temp = curr->next;
curr->next = temp->next;
delete temp;

return head;

}

Node* DeleteBypos(Node* head, int pos){
    //Delete first Node
    if(pos == 1){
        Node* temp  = head;
        head = head->next;
        delete temp;
        return head;
    }

    
     Node* curr =  head;
    for(int i =1; i<pos-1 && curr != nullptr; i++){
        curr=  curr->next;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}

Node* DeletebyRecursion(Node* curr, int x){
    
if(x == 1){
    Node* temp = curr->next;
    delete curr;
    return temp;
}

curr->next = DeletebyRecursion(curr->next, x-1);
return curr;

}



int main() {
    Node* List = Create(5);
    Node* poss = DeletebyRecursion(List, 3);
    PrintList(poss);
    return 0;
}