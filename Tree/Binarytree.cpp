#include <bits/stdc++.h>
using namespace std;

struct BT
{
    int data;
    BT* left;
    BT* right;

    BT(int d){
    data = d;
    left = nullptr;
    right = nullptr;
    }
};

class BinaryTree{
    //data;
     BT* root;

     public:


    //methods;
    BinaryTree(){
    root = BuildTree();
    }
   
    BT* BuildTree(){
      int data;
      cin>>data;

    if(data == -1){
    return nullptr;
    }

      BT* temp = new BT(data);
      temp->left = BuildTree();
      temp->right = BuildTree();

      return temp;
    }


    void preoder(BT* root){
        if( root == nullptr){
            return;
        }

        cout<<root->data<<" ";
        preoder(root->left);
        preoder(root->right);

    }
    void inorder(BT* root){
        if( root == nullptr){
            return;
        }

       
        inorder(root->left);
         cout<<root->data<<" ";
        inorder(root->right);

    }
    void Postorder(BT* root){
        if( root == nullptr){
            return;
        }

       
        Postorder(root->left);
       
        Postorder(root->right);
          cout<<root->data<<" ";

    }

    int height(BT* root){
        if(root == nullptr){
            return 0;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);

        return max(h1,h2)+1;
    }

    int sum(BT* root){
        if(root == nullptr){
            return 0;
        }

        return sum(root->left) + sum(root->right) + root->data;
    }
    
    int getsum(){
     sum(root);
    }

    

    void print(){
        height(root);
    }
};


int main() {
     BinaryTree tree;
     int ans = tree.sum();
     cout<<ans<<endl;
     
     

    
    return 0;
}