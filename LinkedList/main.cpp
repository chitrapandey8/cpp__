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

Node* Reverse(Node* head){
    vector<int> arr;
    Node* curr = head;
    while(curr != nullptr){
      arr.push_back(curr->data);
      curr = curr->next;
    }

    Node* temp =  head;
    for(int i = arr.size()-1; i>=0; i--){
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
    
}

Node* Reverseee(Node* head){
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* curr = head;
  
    while(curr != nullptr){
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
    
    
    }
    head = prev;
    return head;
}
Node* ReversebyRecursion(Node* curr, Node* prev){
 if(curr == nullptr) {
    return prev; //new head of revser linked list;
 }

 Node* fut = curr->next;
 curr->next = prev;
 return ReversebyRecursion(fut, curr);


}

Node* RemovebyNth(Node *head, int x){
////count total nodes
int cnt = 0;
Node* temp = head;
while(temp != nullptr){
    cnt++;
    temp = temp->next;
}

cnt -= x;
if(cnt == 0){ //agar frist wala delete karna ho
temp = head;
head = head->next;
delete temp;
return head;

}
Node* curr = head;
Node* prev = nullptr;
while(cnt--){
prev = curr;
curr = curr->next;
}

prev->next = curr->next;
delete curr;

return head;
}

int MiddleofLL(Node* head){
  Node* slow = head;
  Node* fast = head;
  while(fast != nullptr && fast->next != nullptr){ //ya toh last node pe rok do ya phir null pe rok do
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

Node* DeleteNthNode(Node* head, int x){
return nullptr;
}

Node* RotateNode(Node* head, int x){
    if(head == nullptr || head->next == nullptr){
   return head;
    }

Node* curr = head;
//count total nodes
int cnt = 0;
while(curr){
 cnt++;
 curr = curr->next;
}
cnt -= x;

x = x%cnt;  // agar k bohot bada hai 
if(x == 0){ //agar x == 0 hai toh roatae hi nhi karna 
    return head;
}
Node* temp = head;
Node* prev = nullptr;
while (cnt--)
{
    prev = temp;
    temp = temp->next;
}

prev->next = nullptr;
Node* tt = temp;
while(tt->next != nullptr){
    tt = tt->next;
}
tt->next = head;
head = temp;
return head;

}

bool CheckPalinfrom(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }

    count = count/2;
    Node* curr = head;
    Node* prev = nullptr;
    
    while(count--){
        prev = curr;
        curr  =curr->next;
    }
    prev->next = nullptr;
    prev = nullptr;

    Node* next = nullptr;
    while(curr != nullptr){
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
    }

    Node* one  = head;
    Node* two = prev;
    while(one){
        if(one->data != two->data){
            return 0;
        }

        one = one->next;
        two  = two->next;
    }
    return 1;
}

Node* soer123(Node* head){
int count0 = 0;
int count1= 0;
int count2 = 0;

Node* curr  = head;

while(curr != nullptr){
    if(curr->data == 0){
        count0++;
    }else if(curr->data == 1){count1++;
    }else{
        count2++;
    }
    curr = curr->next;
}

curr = head;

while(count0--){
    curr->data = 0;
    curr = curr->next;
}

while(count1--){
    curr->data = 1;
    curr = curr->next;
}

while(count2--){
    curr->data = 2;
    curr = curr->next;
}


return head;
}

///////////////////////////Circular Linked List//////////////
bool detectloop(Node* head){
unordered_map<Node*,int> mp;

Node* curr = head;
while(curr != nullptr){
    if(mp[curr] == 1){
        return 1;
    }

    mp[curr] = 1;
    curr = curr->next;
}
return 0;
}


int intono(Node* head){
        Node* curr = head;
        string s = "";
        while(curr){
          s += to_string(curr->data);
          curr = curr->next;
        }
        int n = s.size();
        int i = 0; long long pow = 1; int ans = 0;
        while(i<n){
         int  no = s[i] - '0';
         ans = no * pow + ans;
         pow = pow*2;
         i++;
        }
        return ans;
}

Node* Add(Node* head, int k){
Node* first = new Node(0);
first->next = head;
head = first;


int x;
Node  *second, *prev, *curr, *front; 
while(first->next){
   x = k;
   second = first->next;
   prev = first;
   curr = first->next;

   while(x &&curr){
    front   =curr->next;
    curr->next = prev;
    prev = curr;
    curr = front;
    x--;
   }
   first->next  =prev;
   second->next = curr;
   first = second;
}

///deleet deummu node
first = head;
head = head->next;
delete first;
return head;

}

Node* Recursion(Node* head, int k){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    while(curr && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
}

head->next = Recursion(curr, k);
return prev;

}



Node* Evenodd(Node* head){
    vector<int> Odd;
    vector<int> Even;
   
    //find the length of nodes:
    Node* curr = head;
    int cnt = 0;
    while(curr){
        cnt++;
        curr = curr->next;
    }

    ///agar length odd hui toh kua or agar even hui toh kya
   
    if(cnt%2 != 0){
      Node* l1 = head;
      Odd.push_back(head->data);
      while(l1 && l1->next){
        Odd.push_back(l1->next->next->data);
        Even.push_back(l1->next->data);
        l1 = l1->next->next;
      }
    }
    else{
        Node* l2 = head->next;
        Odd.push_back(head->data);
        Even.push_back(head->next->data);
        while(l2 && l2->next){
       Even.push_back(l2->next->next->data);
       Odd.push_back(l2->next->data);
       l2 = l2->next->next;
        } 
    }

    //put odd first
    Node* curr1 = head;
    int n = Odd.size();
    int i = 0;
    while(i<n){
       curr1->data = Odd[i];
       curr1 = curr1->next;
       i++;
    }
    
     Node* curr2 = curr1;
     int j = 0;
     while(j<Even.size()){
        curr2->data = Even[j];
        curr2  = curr2->next;
        j++;

     }

    return head;
   }

   







int main() {
    vector<int> arr = {2,1,3,5,6,4,7};
    Node* ll = createByRecursion(arr, 0, arr.size());
    Node* Even = Evenodd(ll);
   
    PrintList(Even);
    
    
    return 0;
}