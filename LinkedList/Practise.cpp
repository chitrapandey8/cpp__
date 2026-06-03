#include <bits/stdc++.h>
using namespace std;

class Listnode{
    public:
    int val;
    Listnode* next;
    Listnode(int val){
        this->val = val;
        this->next = nullptr;

    }
};

class Practise{
    public:
    Listnode* createByRecursion(vector<int> arr, int index, int size){  ///we returing the address
    if(index == size){ //tc - O(n)
        return nullptr;
    }

    Listnode* temp;
    temp = new Listnode(arr[index]);
    temp->next = createByRecursion(arr, index+1, size); //jo bhi adres createbyrecursuion laake dega voh hum temp.next mai daal denge
    return temp;
   } 

   void PrintList(Listnode* head){
    Listnode* curr = head;
    while(curr != nullptr){
        cout<<curr->val<<"->";
        curr = curr->next;
    }


}

    Listnode* Reversei(Listnode* head){
      Listnode* curr = head;
      Listnode* prev = nullptr;
      Listnode* next = nullptr;
    while(curr){
     next = curr->next;
     curr->next =  prev;
     prev = curr;
     curr = next;
    }
    head  = prev;
    return head;
    }

    
Listnode* Reverser(Listnode* curr, Listnode* prev){
            if(curr == nullptr){
                return prev;
            }
            Listnode* forword =  curr->next;
            curr->next = prev;
            return Reverser(forword, curr);
    }

    bool LinkedListCycle(Listnode* head, Listnode* slow, Listnode* fast){

     if(fast == nullptr || fast->next == nullptr){
        return false;
     }

     slow = slow->next;
     fast = fast->next->next;  

    /// base case
    if(slow == fast){
        return true;
    }
    
    LinkedListCycle(head, slow, fast);
    }
};

void MergeTwoSortedList(Listnode* dummy, Listnode* l1, Listnode* l2){
     ///base1
     if(l1 == nullptr && l2 == nullptr){
        return;
     }
     
     if(l1 == nullptr){
        dummy->next = l2;
        return;
     }

     if(l2 == nullptr){
        dummy->next = l1;
        return;
     }

    if(l1->val <= l2->val){
        dummy->next = l1;
        l1 = l1->next;
    }else{
        dummy->next = l2;
        l2 = l2->next;
    }

    dummy = dummy->next;
    MergeTwoSortedList(dummy, l1, l2);
}


int main() {
    Practise p  = Practise();
    vector<int> arr = {1,2,3};
    vector<int> arr1 = {1,3,4};
     Listnode* l1 = p.createByRecursion(arr,0,arr.size());
     Listnode* l2 = p.createByRecursion(arr1,0,arr1.size());
    Listnode* dummy = new Listnode(0);
    MergeTwoSortedList(dummy, l1, l2);

    p.PrintList(dummy->next);
    return 0;
}