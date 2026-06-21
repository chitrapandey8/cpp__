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

///i can create tree iteratively and recursively
Node* MTree(){ //this makes the tree level wise, and when we make tree level wise i need to use queue
    queue<Node*> q;
    //create root node and put in the queue 
    cout<<"Enter root:"<<endl;
    int x; cin>>x;
    Node* root = new Node(x);
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        //input left child and create left node
        cout<<"Enter"<<" "<<temp->data<<" "<<"left"<<endl;
        int left; cin>>left;
        if(left != -1){
        temp->left = new Node(left);
        q.push(temp->left);
        }
        //input right child and create right node
        cout<<"Enter"<<" "<<temp->data<<" "<<"right"<<endl;
        int right; cin>>right;
        if(right != -1){
        temp->right = new Node(right);
        q.push(temp->right);
    }
}
    return root;
}

//when i create tree recursively, i go as left as possible and ifn i encounter -1 i return and create right root
Node* MtreeR(){
    cout<<"enter dtaa"<<endl;
int x; cin>>x;
if(x == -1){
    return nullptr;
}

Node* newnode = new Node(x);
newnode->left = MtreeR();
newnode->right = MtreeR();
return newnode;
}

//creating an by passong an array
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
    i++;
    
}
return root;
}

///preorder Recursivley
void Preorder(Node* root){
    if(root == nullptr){return;}
    cout<<root->data<<endl;
    Preorder(root->left);
    Preorder(root->right);
}

void Levelorder(Node* root,vector<int> &ans){
queue<Node*> q;
ans.push_back(root->data);
q.push(root);
while(!q.empty()){
    Node* temp = q.front();
    q.pop();

    if(temp->left){
        ans.push_back(temp->left->data);
        q.push(temp->left);
    }
    if(temp->right){
        ans.push_back(temp->right->data);
        q.push(temp->right);
    }
}
}

//Leetcode 102
void BinaryTree(Node* root, vector<vector<int>> &ans){
queue<Node*> q;
q.push(root);

while(!q.empty()){
    int n = q.size();
    
    vector<int> insideL;
    for(int i = 0; i<n; i++){
        Node* temp = q.front();
        q.pop();
        insideL.push_back(temp->data);

        //left child ko queue mai dalo, right child ko queue mai dalo
        if(temp->left){q.push(temp->left);}
        if(temp->right){q.push(temp->right);}

    }
    ans.push_back(insideL);
}

}

int main() {
    vector<int> arr = {3,9,20,-1,-1,15,7,-1,-1,-1,-1};
    Node* root =  MTreeA(arr);
    vector<vector<int>> ans;
    BinaryTree(root, ans);

    for(vector<int> a: ans){
        for(int x: a){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}