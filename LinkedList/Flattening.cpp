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

class fll{
    public:
    int data;
    fll *next;
    fll *bottom;
    fll(int data){
     this->data= data;
     this->next= nullptr;
     this->bottom=nullptr;
    }
};

Node* createByRecursion(vector<int> arr, int index, int size){  ///we returing the address
    if(index == size){     //tc - O(n)
        return nullptr;
    }

    Node* temp;
    temp = new Node(arr[index]);
    temp->next = createByRecursion(arr, index+1, size); //jo bhi adres createbyrecursuion laake dega voh hum temp.next mai daal denge
    return temp;
}

fll* createfll(fll* head){
fll* root = new fll(5);
root->bottom = head;
}

int main() {
    return 0;
}