#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
     this->data = data;
     this->left = nullptr;
     this->right = nullptr;
    }
};


///Create a Binary Search Tree--- i will be adding node when i reach null, and when the node is smaller then the current node then i go to left, else i go right
TreeNode*  Create(TreeNode *root, int val){
  

    if(!root){
        TreeNode* temp = new TreeNode(val);
        return temp;
    }

    if(root->data < val){
       root->right =  Create(root->right, val);
    }else{
      root->left =   Create(root->left , val);
    }
    return root;
}

void inorder(TreeNode* root){
    if(!root){return;}

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

////////////////////Search in Tree////////////////////
bool Search(TreeNode* root, int target){
     if(!root){
        return 0;
     }
     
    if(root->data == target){
        return 1;
    }

    if(root->data < target){
    return   Search(root->right, target);
    }else{
      return   Search(root->left, target);
    }}


////////////////////Delete a Node//////////////////////////////////
      



int main() {
    vector<int> arr = {6,3,11,5,7,18,12,2};
    TreeNode* root = nullptr;
    for (int i = 0; i < arr.size(); i++)
    {
        root = Create(root, arr[i]);
    }
    
    if(Search(root, 100)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }

    
    return 0;
}