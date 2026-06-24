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
queue<Node*> q;
Node* root = new Node(arr[0]);
q.push(root);

int i = 1;
while(!q.empty() && i<arr.size()){
    //agar arr[i] -1 nhi h toh left ya right child banao
    Node* temp = q.front();
    q.pop();

    if(arr[i] != -1){
        temp->left = new Node(arr[i]);
        q.push(temp->left);
        
    }
    i++;
    if(arr[i] != -1){
        temp->right = new Node(arr[i]);
        q.push(temp->right); 
    }
    i++;}
return root;
}



int height(Node* root){
    if(!root){return 0;}

    return 1 + max(height(root->left), height(root->right));
}


void Find(Node* root, int target, Node* &BurnNode){
    if(!root){return;}

    if(root->data == target){
        BurnNode = root;
        return;
    }
    
    Find(root->left, target, BurnNode);
    Find(root->right, target, BurnNode);

}

int Burn(Node* root, int &timer, int target){
    if(!root){return 0;}
  
    if(root->data == target){
        return -1;
    }
    int left = Burn(root->left,timer,target);
    int right = Burn(root->right,timer,target);
    
    if(left < 0){
        timer = max(timer, abs(left)+right);
        return left -1;
    }

    if(right < 0){
        timer = max(timer, left+abs(right));
        return right-1;
    }
    return 1+ max(left, right);

} 
void Inorder(Node* root, vector<int> &ans) {

    while(root){
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }else{
            Node* curr = root->left;
            ///jab tak current ka right exist karta hai ya phir current ke riht mia root h ya nhi
            while (curr->right && curr->right != root)
            {
                curr = curr->right;

            }

            if(curr->right == nullptr){
                curr->right = root;
                root = root->right;
            }else{
                curr->right  = nullptr;
                ans.push_back(root->data);
                root = root->right;
            }
            
        }
    }

}

int main() {
    int time = 0;
    vector<int> arr = {1,5,3,-1,4,10,6,9,2};
    Node* root = MTreeA(arr);
    int target = 3;
    Burn(root, time,target);
    
    Node* BurnNode = nullptr; 
    ///find Burning Node
    Find(root,target, BurnNode);
    int heightt = height(BurnNode)-1;
    cout<<max(time, heightt);
        return 0;
}