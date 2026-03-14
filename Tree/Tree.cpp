#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void  inorder(Node* root){
    if(root == nullptr){
         return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void  postorder(Node* root){
    if(root == nullptr){
         return;
    }
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}



int main(){

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);

    root->right->left->left = new Node(12);

    root->left->left->left->left = new Node(13);

     inorder(root);
    return 0;
}