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

/////////////Spiral level order traversal/////////////////////
void SpiralOrderT(Node* root, vector<vector<int>> &ans){
stack<Node*> RtoL;
stack<Node*> LtoR;
LtoR.push(root);

while (!RtoL.empty() || !LtoR.empty())
{
    vector<int> level;
    ////left to right se pop karo or dusre stack mai dalo
    if(!LtoR.empty()){
        //ismai mia pehel left ko dalugi phir right ko
        while(!LtoR.empty()){
          Node* temp = LtoR.top();
          LtoR.pop();

          level.push_back(temp->data);

          if(temp->left){RtoL.push(temp->left);}
          if(temp->right){RtoL.push(temp->right);}
}
    }else{
        while(!RtoL.empty()){
          Node* temp = RtoL.top();
          RtoL.pop();

          level.push_back(temp->data);

          if(temp->right){LtoR.push(temp->right);}
          if(temp->left){LtoR.push(temp->left);}
}}
    ans.push_back(level);}}


///Check if two nodes are Cousins meaning , they be from same level and their parents should be different.
bool CheckCousins(Node* root, int x,int y){ //level order traversal
    queue<Node*> q; q.push(root); int xx = -1; int yy = -1;

    ////mai har level pe trevrse karugi or sath mai ye check kareti jaungi ki ki kisi node ke childer kahi x ya y toh nhi hai, phir mai level chekc karugi
    while (!q.empty())
    {
        int n = q.size();
        for(int i = 0; i<n; i++){
          Node* temp = q.front();
        q.pop();

        ///check the parent
        if((temp->left->data == x && temp->right->data == y) || (temp->left->data == y && temp->right->data == x)){
            return 0;
        }

        if(temp->data == x){
            xx = 1;
        }
        if(temp->data == y){
            yy = 1;
        }

        }
        if((xx == 1 && y == -1) || (xx == -1 && yy == 1)){
            return 0;
        }

    }
    
   return 1;

}

/////////////////find left view of the tree
void FindLeftView(Node* root,vector<int> &ans){
queue<Node*> q;
q.push(root);
while(!q.empty()){
    int n = q.size();
    bool flag = true;
    for(int i = 0; i<n; i++){
        Node* temp = q.front();
        q.pop();
        if(flag){
            ans.push_back(temp->data);
            flag = false;
        }

        if(temp->left){q.push(temp->left);}
        if(temp->right){q.push(temp->right);}

    }
}
}

void findLeftViewRecusilvey(Node* root, vector<int> &ans, int level){
   if(root == nullptr){
    return;
   }

    if(level == ans.size()){
        ans.push_back(root->data);
    }
    findLeftViewRecusilvey(root->left, ans, level+1);
    findLeftViewRecusilvey(root->right,ans, level+1);
}

/////////////////////Find Top View of Tree////////////////////////////////////////////////////


int main() {
    vector<int> arr = {3,9,20,-1,-1,15,7};
    Node* root = MTreeA(arr);
    vector<int> ans;

    findLeftViewRecusilvey(root, ans,0);


    for(int x:ans){
        cout<<x<<" ";
    }

    return 0;
}