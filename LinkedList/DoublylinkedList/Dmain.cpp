#include <bits/stdc++.h>
using namespace std;

class DLL{
  public:
  int data;
  DLL* prev;
  DLL* next;
  
  DLL(int data){
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
  }

};

DLL* Create(vector<int> arr){
//crete the first node
// DLL* newnode = new DLL(arr[0]);
// DLL* head = newnode;
// DLL* curr = newnode;

// for(int i = 1; i<arr.size(); i++){
//     DLL* temp = new DLL(arr[i]);

//     curr->next = temp;
//     temp->prev = curr;

//     curr =  temp;
// }
//  return head;

DLL* head = nullptr;
DLL* tail = nullptr;
for(int i =  0; i<arr.size(); i++){
if(head == nullptr){
    head = new DLL(arr[i]);
    tail  =head;
}else{
    DLL* newnode = new DLL(arr[i]);
    tail->next  = newnode;
    newnode->prev = tail;
    tail = newnode;
}
}
return head;
}

void PrintDLL(DLL* head){
    DLL* curr = head;
    while(curr){
        cout<<curr->data<<"<->";
        curr = curr->next;
    }
    
}

DLL* Insertionatbeging(DLL* head, int value){
if(head == nullptr){
head = new DLL(value);
}else{
    DLL* temp = new DLL(value);
    temp->next = head;
    head->prev = temp;
    head =  temp;
}
return head;

}

DLL* Insertionatend(DLL* head, int value){
DLL* curr = head;
while (curr->next != nullptr)
{
    curr = curr->next;
}
DLL* temp = new DLL(value);
temp->prev = curr;
curr->next = temp;
return head;

}

DLL* recursion(vector<int> arr, int index, int size, DLL* last){
    if(index == size){
        return nullptr;
    }

    DLL* temp = new DLL(arr[index]);
    temp->prev = last;
    temp->next = recursion(arr, index+1, size, temp);
    return temp;
    
}

DLL* InsertAtpos(DLL* head, int pos, int val){
   
    //insert at start
    if(pos == 0){
        //ll exist na kare
       if(head == nullptr){
       head = new DLL(val);
       }else{ //exist kare 
        DLL* temp = new DLL(val);
        temp->next = head;
        head->prev = temp;
        head  = temp;

       }
    }else{
       DLL* curr = head;
       ///go tothe pos

       while(--pos){
        curr = curr->next;
       }

       if(curr->next == nullptr){ //insert at end
        DLL* temp = new DLL(val);
        temp->prev = curr;
        curr->next = temp;
       }else{
        DLL* temp = new DLL(val);
         temp->next = curr->next;
         temp->prev = curr;

         curr->next = temp;
         temp->next->prev = temp;
       }
    }
    return head;
    
}

DLL* DeleteAtstart(DLL* head){
    if(head != nullptr){
       if(head->next == nullptr){
        delete head;
        head = nullptr;
       }else{
        DLL* temp = head;
        head = head->next;
        delete temp;
        if(head){
            head->prev = nullptr;
        }
       }

        
    }
    return head;
}


DLL* DeleteAtend(DLL* head){
    if(head){
        ///if only one head exist
        if(head->next == nullptr){
delete head;
        head = nullptr;
        }else{

         DLL* curr = head;
         while(curr->next != nullptr){
           curr = curr->next;
         }
          curr->prev->next = nullptr;
            delete curr;
        }
        
    }
    return head;
}

DLL* DeleteAtpos(DLL* head, int pos){

if(pos == 1){
    if(head->next == nullptr){
        delete head;
        head = nullptr;
       }else{
        DLL* temp = head;
        head = head->next;
        delete temp;
        if(head){
            head->prev = nullptr;
        }
       }
}else{

//dleete at end
DLL* curr = head;

for(int i = 1; i < pos; i++) {
        curr = curr->next;
    }


if(curr->next == nullptr){

curr->prev->next = nullptr;
delete curr;


}else{    //middlee
curr->prev->next = curr->next;
curr->next->prev = curr->prev;
delete curr;
}

}
return head;
}



////Remove Deuplicates elememts from list
DLL* RemoveDuplicate(DLL* head){
vector<int> arr;
arr.push_back(head->data);
DLL* curr  = head->next;

while(curr){

    if(arr[arr.size()-1] != curr->data){
        arr.push_back(curr->data);        
    }
    curr = curr->next;
    
}

curr  = head;
int index = 0;
DLL* prev  =nullptr;

while(index < arr.size()){
    curr->data =  arr[index];
    prev = curr;
    index++;
    curr = curr->next;
}

prev->next = nullptr;
return head;

// int size  = arr.size(); //3
// curr = head;

// while(size--){
//     curr = curr->next;
// }
// curr->next = nullptr;
// return head;

}

//another method
DLL* Remove(DLL* head){
    DLL* prev = head;
    DLL* curr = head->next;

    while(curr){

      //duplicates found
      if(prev->data == curr->data){
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
      }else{
        prev = prev->next;
        curr = curr->next;
      }

    }
    return head;
}

////merge two sorted list::
DLL* Mergetwolist(DLL* head1, DLL* head2){
DLL* curr1 = head1;
DLL* curr2 = head2;

DLL* Dummpy = new DLL(0);
DLL* tail = Dummpy;

while(curr1 != nullptr && curr2 != nullptr){
    if(curr1->data <= curr2->data){
    tail->next = curr1;
    curr1 = curr1->next;
    tail = tail->next;
    }else{
        tail->next = curr2;
        curr2 = curr2->next;
        tail = tail->next;
    }
}

if(curr1){
    tail->next = curr1; // we are merging the node list at once we dont need to iterate further becoz the list is already 
}

if(curr2){
    tail->next = curr2;
}


return Dummpy->next;
}



int main() {
    vector<int> arr = {2,4,5,7};
    vector<int> arr2 = {3,4,4,6,8,10};
    DLL* ll1 = recursion(arr, 0, arr.size(), nullptr);
    DLL* ll2 = recursion(arr2, 0, arr2.size(), nullptr);
    DLL* poss = Mergetwolist(ll1,ll2);
    PrintDLL(poss);

    return 0;
}