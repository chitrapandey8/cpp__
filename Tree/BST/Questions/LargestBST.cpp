#include <bits/stdc++.h>
using namespace std;


class Node{
   public:
   int data;
   Node* left;
   Node* right;

   Node(int val){
    data = val;
    left = nullptr;
    right = nullptr;
   }
};

Node* MTreeA(vector<int> arr){
if(arr.empty() || arr[0] == -1){
    return nullptr;
}

queue<Node*> q;
Node* root = new Node(arr[0]);
q.push(root);

int i = 1;
while(!q.empty() && i<arr.size()){
    //agar arr[i] -1 nhi h toh left ya right child banao
    Node* temp = q.front();
    q.pop();

    if(i< arr.size() && arr[i] != -1){
        temp->left = new Node(arr[i]);
        q.push(temp->left);
        
    }
    i++;
    if(i < arr.size() && arr[i] != -1){
        temp->right = new Node(arr[i]);
        q.push(temp->right); 
    }
    i++;}
return root;
}

////create Box first
class Box{
    public:
    bool BST;
    int size,min,max;

    Box(int data){
      BST = 1;
      size = 1;
      min = data;
      max = data;
    }
    
};

Box* Find(Node* root, int &totalsize){
    
    //leaf node hai toh
    if(!root->left && !root->right){
        totalsize = max(totalsize,1);
        return  new  Box(root->data);
        //agar right exist kare sirf
    }else if(!root->left && root->right){
      Box* head = Find(root->right, totalsize);

      ///chck ki jo return hua h voh bst hai ya nhi
      if(head->BST && head->min > root->data){

        
        head->size += head->size;
        head->min = root->data;
        totalsize = max(totalsize, head->size);
        return head;
      }else{
        head->BST = 0;
        return head;
      }
    }
    /////////left exist kare bas
    else if(root->left && !root->right){
       Box* head  = Find(root->left, totalsize);

       if(head->BST && head->max <root->data){
        head->size++;
        head->max = root->data;
        totalsize = max(totalsize, head->size);
        return head;
       }else{
        head->BST = 0;
        return head;
       }
       ///////////If both exist/////////////////////////
    }else{
        Box* lefthead = Find(root->left , totalsize);
        Box* righthead = Find(root->right, totalsize);
        
        if(lefthead->BST &&righthead->BST && lefthead->max<root->data && righthead->min > root->data){
            Box *head  = new Box(root->data);
         
            head->size += lefthead->size + righthead->size;
            head->min = lefthead->min;
            head->max = righthead->max;
            totalsize = max(totalsize, head->size);
            return head;

        }else{
            lefthead->BST = 0;
            return lefthead;
        }

    }

}



int main() {
    vector<int> arr = {6, 7, 3, -1, 2, 2, 4};
    Node* root = MTreeA(arr);

    int totalsize = 0;
    Find(root, totalsize);
    cout<<totalsize<<endl;
        return 0;
}