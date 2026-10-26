#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
   int data;
   Node *left;
   Node *right;
   Node(int val){
     data = val;
     left = nullptr;
     right = nullptr;
   }  
};

Node* Create(Node* root, int val){
  if(root == nullptr){
    Node* temp = new Node(val);
    return temp;
  }

  

  if(val != -1 &&  root->data > val){
    root->left =  Create(root->left, val);
  }else if(val != -1 &&  root->data < val){
   root->right =  Create(root->right, val);
  }

  return root;
}


void Inorder(Node* root){
    if(root == nullptr){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int InorderSucessor(Node* root){
    if(root->left == nullptr){
        return root->data;
    }
    return InorderSucessor(root->left);
}

Node* Searchthekey(Node* root,int val){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == val){
        return root;
    }

    Node* temp = Searchthekey(root->left, val);
    if(temp != nullptr){
        return temp;
    }
    return Searchthekey(root->right, val);
}

int main() {
    vector<int> arr = {2,1,3};
    int key = 2;
    Node* root = nullptr;
    for(int i = 0; i< arr.size(); i++){
        root = Create(root, arr[i]);
    }
    Node* temp = Searchthekey(root, key);
    cout<<InorderSucessor(temp->right)<<endl;
    return 0;
}