#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    public:
    ListNode(int val){
        this->val = val;
        this->next = nullptr;

    }
};

ListNode* LinkedList(int n){
    ListNode* newListNode = new ListNode(1);
    ListNode* head = newListNode;
    ListNode* curr = newListNode;
    for (int i = 2; i <= n; i++)
    {
       curr->next = new ListNode(i);
       curr = curr->next;
    }
    return head;
    
}

ListNode* findMid(ListNode* head){

    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void PrintList(ListNode* head){
    ListNode* curr = head;
    while(curr != nullptr){
     cout<<curr->val<<"->";
     curr = curr->next;
    }  
  cout<< endl;
}

int findsize(ListNode* head){
ListNode* curr = head;
int count = 0;
while(curr != nullptr){
count++;
curr = curr->next;
}
return count;
}

ListNode* reversebk(ListNode* head, int k){
//base baSE
if(findsize(head) < k){
    return head;
}

//reverse
ListNode* curr = head;
ListNode* prev = nullptr;
ListNode* next  = nullptr;
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

 
int getKthdata(ListNode* head, int k){   ///5th ListNode ka val chahiye toh pehel mai check karugi ki  jo ListNode h vph uss linked list ke size ko exceed toh nhi krra hai, age karr h toh return -1, warna leeo laha ke val nikal

if(k > findsize(head)){
    return -1;
}

ListNode* curr = head;
   while(k>1){
    curr = curr->next;
    k--;
   }
   return curr->val;

}


int search(ListNode* head, int target){
  if(head == nullptr){
    return -1;
  }

  if(head->val == target){
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

int kformend(ListNode* head, int k){
 

    // ListNode*curr = head;
    // for(int i = 1; i<=n; i++){
    //   curr = curr->next;
    // }
    //  return curr->val;
    ListNode* slow = head;
    ListNode* fast = head;
  for(int i = 1; i<=k; i++){
    fast = fast->next;
  }

  while(fast != nullptr){
    slow = slow->next;
    fast =  fast->next;
  }
      
  
  return slow->val;

}

ListNode* merge(ListNode* a, ListNode* b){

}


ListNode* mergesort(ListNode* head){
ListNode* mid  = findMid(head);
mid->next = nullptr;

ListNode* a =mergesort(head);
ListNode* b = mergesort(mid->next);


return merge(a,b);
if(a == nullptr){
    return b;
}

if(b == nullptr){
    return a;
}

if(a->val < b->val){
    head = a;
    a->next = merge(a->next,b);

}else{
    head = b;
    b->next = merge(a, b->next);
}

return head;

}

ListNode* addnumber(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(0);
       ListNode* tail = dummy; 
       
        ListNode* a = l1;
        ListNode* b = l2;
       int carry  = 0;
       int dataa = 0;

       while(a != nullptr & b != nullptr){
        
        dataa = (a->val  + b->val + carry) % 10;
        
        carry = (a->val + b->val + carry) /10;

        tail->next = new ListNode(dataa);
        tail = tail->next;

        a = a->next;
        b = b->next;
       }
       
      

       while(a !=  nullptr){
       
        dataa = (a->val + carry) % 10;
        carry = (a->val + carry) /10;
        tail->next = new ListNode(dataa);
        tail = tail->next;
        a = a->next;
       }
        while(b !=  nullptr){
           
        dataa = (b->val + carry) % 10;
         carry = (b->val + carry)/10;
        tail->next = new ListNode(dataa);
        tail = tail->next;
        b = b->next;
       }


        if(carry > 0){
        tail->next = new ListNode(carry);
       }
     
    return dummy->next;
}




int main(){
    ListNode* linklist1 = LinkedList(6);
    ListNode* linklist2 = LinkedList(6);  
    
    ListNode* ans =  addnumber(linklist1, linklist2);
    PrintList(ans);

    

}