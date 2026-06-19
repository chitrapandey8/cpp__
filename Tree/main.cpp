#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
}
};

Node* Createiterative(){
    queue<Node*> q;
    
    cout<<"Enter Root Node:"<<endl;
    int x; cin>>x;
    Node* root = new Node(x);
    root->data = x;
    q.push(root);
    
    
    int first; int second;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        ///left mia insert karo
        
        cout<<"Enter"<<temp->data<<"left Node:"<<endl;
        cin>>first;
        if(first != -1){
           temp->left  = new Node(first);
           q.push(temp->left);
        }
        
        cout<<"Enter"<<temp->data<<"Second Node:"<<endl;
        cin>>second;
        if(second != -1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
    return root;

}

Node* createbyrecursion(){
    cout<<"Enter data"<<endl;
    int x; cin>>x;
    
    if(x == -1){
        return nullptr;
    }

    Node *newnode = new Node(x); 
    newnode->left = createbyrecursion();
    newnode->right = createbyrecursion();
    return newnode;
}

Node* sumodBT(int &sum){
cout<<"Enter data"<<endl;
    int x; cin>>x;
    
    if(x == -1){
        return nullptr;
    }

    Node *newnode = new Node(x); 
    sum = sum+newnode->data;
    newnode->left = sumodBT(sum);
    newnode->right = sumodBT(sum);
    return newnode;
}

void Preorder(Node* root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<endl;
    Preorder(root->left);
    Preorder(root->right);
}

void Inoder(Node* root){
    if(root == nullptr){
        return;
    }

    
    Inoder(root->left);
    cout<<root->data<<endl;
    Inoder(root->right);
}

void Postorder(Node* root){
    if(root == nullptr){
        return;
    }

    
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<endl;
 }

int Total(Node* root){
   if(root == nullptr){
    return 0;
   }
    return root->data + Total(root->left) + Total(root->right);
}



int main() {
    Node* root = createbyrecursion();
    int ans = Total(root);
    cout<<ans<<endl;
    return 0;
}




