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

Node* findMid(Node* head){

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

Node* reversebk(Node* head, int k){
//base baSE
if(findsize(head) < k){
    return head;
}

//reverse
Node* curr = head;
Node* prev = nullptr;
Node* next  = nullptr;
int count = 0;
while(count < k){
    next = curr->next;
    curr->next = prev;
    
    prev = curr;
    curr = next;

    count++;

}
//recursion
if(curr != nullptr){
    head->next  = reversebk(curr, k);
}
  
return prev;

}

 
int getKthdata(Node* head, int k){   ///5th node ka data chahiye toh pehel mai check karugi ki  jo node h vph uss linked list ke size ko exceed toh nhi krra hai, age karr h toh return -1, warna leeo laha ke data nikal

if(k > findsize(head)){
    return -1;
}

Node* curr = head;
   while(k>1){
    curr = curr->next;
    k--;
   }
   return curr->data;

}


int search(Node* head, int target){
  if(head == nullptr){
    return -1;
  }

  if(head->data == target){
    return 1;
  }else{
    int subindex = search(head->next, target);

    if(subindex  == -1){
        return -1;
    }else{
        return subindex+1;
    }
  }
}

int kformend(Node* head, int k){
 

    // Node*curr = head;
    // for(int i = 1; i<=n; i++){
    //   curr = curr->next;
    // }
    //  return curr->data;
    Node* slow = head;
    Node* fast = head;
  for(int i = 1; i<=k; i++){
    fast = fast->next;
  }

  while(fast != nullptr){
    slow = slow->next;
    fast =  fast->next;
  }
      
  
  return slow->data;

}

Node* merge(Node* a, Node* b){

}


Node* mergesort(Node* head){
Node* mid  = findMid(head);
mid->next = nullptr;

Node* a =mergesort(head);
Node* b = mergesort(mid->next);


return merge(a,b);
if(a == nullptr){
    return b;
}

if(b == nullptr){
    return a;
}

if(a->data < b->data){
    head = a;
    a->next = merge(a->next,b);

}else{
    head = b;
    b->next = merge(a, b->next);
}

return head;

}



int main(){
    Node* linklist = LinkedList(10);
    
    int ans = kformend(linklist,3);
        cout<<ans<<endl;


    

}