#include <bits/stdc++.h>
using namespace std;

///class of a node in a Tree
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val){
       this->data = val;
       this->left = nullptr;
       this->right = nullptr;
       this->height = 1;
    }
};

int getHeight(Node* root){
    if(!root){return 0;}

    return root->height;
}

int getBalance(Node* root){
    if(!root){return 0;}

    return getHeight(root->left) - getHeight(root->right);
}

Node* RightRotation(Node* root){
Node* child = root->left;
//save the right child 
Node* rightchild = child->right;

//abb changes karo;
child->right = root;
//child ke rightki value root se choti hofi toh hum ussee root ke left mai daal sakte hai 
root->left = rightchild;

///root or child change hua hai toh uski height bhi change hui hogi

root->height = 1 + max(getHeight(root->left), getHeight(root->right));
child->height = 1+ max(getHeight(child->left), getHeight(child->right));


return child;
}

Node* LeftRotation(Node* root){
    Node* child = root->right;
    Node* leftchild = child->left;

    child->left = root;
    root->right = leftchild;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node* insert(Node* root, int key){
    ////hum jab null point aata hai tab insert krte hai
    if(!root){
        return new Node(key);
    }

    ///agar null nhi h toh check ki key kis side insert ho sakti hia
    if(key >  root->data){
        root->right =  insert(root->right, key);
    }else if(key < root->data){
        root->left =  insert(root->left, key);
    }else{
        return root;
    }

    ///aaba jab return hoga tab hum har node ki hegith update karege 
    root->height = 1+max(getHeight(root->left), getHeight(root->right));

    //abb inmabclance chekc karo jab naya node add karke return hoga tab return hote warkt  hum check kakrege ki aab imbalance toh nhi ho gaya

    int imbalance = getBalance(root);

    //check karo ki chari case yahi ll, rr, lr, rl mai se kon sa csse ho sakta 
    //LL case tab hoga jab imbalnce +2 ko or key ki value root->left se choti ho
    if(imbalance > 1 && key < root->left->data){
        return RightRotation(root);
    }
    
    //RR case tab hota hia jab imbace -2 ko or key ki value root-rightb se badi ho
    else if(imbalance < -1 && key > root->right->data){
        return LeftRotation(root);
    }

    //lr rotation
    else if(imbalance > 1 && key > root->left->data){
        root->left = LeftRotation(root->left);
        return RightRotation(root);
    }
    
    //rl rotation
    else if(imbalance < -1 && key && key < root->right->data){
        root->right = RightRotation(root->right);
        return LeftRotation(root);
    }else{

    

    return root;
    }


}


void inorder(Node* root, vector<int> &ans){
    if(!root){
        return;
    }

   inorder(root->left, ans);
   ans.push_back(root->data);
   inorder(root->right, ans);    

}

int main() {
  
     Node* root = nullptr;
     root = insert(root,10);
     root = insert(root,5);
     root = insert(root,100);
     root = insert(root, 35);
     root = insert(root, 22);
     root = insert(root, 45);

     vector<int> ans;
     
     inorder(root, ans);
     for(int x: ans){
        cout<<x<<" ";
     }

    return 0;
}