#include <bits/stdc++.h>
using namespace std;
//size, sum 

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

///size of Binary Tree--Total no of nodes in a BinaryTree
void SizeiofBT(Node* root, int &cnt){
 if(root == nullptr){return;}
    cnt++;
    SizeiofBT(root->left, cnt);
    SizeiofBT(root->right, cnt);
}

int Sizebyrecursion(Node* root){
    if(root == nullptr){
        return 0;
    }
    return 1 + Sizebyrecursion(root->left) + Sizebyrecursion(root->right);
}

//sum of BinaryTree-- iteratively and recursivley
void SumodBT(Node* root, int &sum){
     if(root == nullptr){return;}
    sum += root->data;
    SumodBT(root->left, sum);
    SumodBT(root->right, sum);
}

int Sumrecursively(Node* root){
    if(root == nullptr){
        return 0;
    }

    return root->data + Sumrecursively(root->left) + Sumrecursively(root->right);
}


//CountLeafNodes
void CountLN(Node* root, int &cnt){
    if(!root){return;} 

    if(root->left == nullptr && root->right == nullptr){
        cnt++;
    }
    CountLN(root->left, cnt);
    CountLN(root->right, cnt);
}

int CountLNRecursive(Node* root){
if(!root){return 0;}

if(!root->left && !root->right){
    return 1;}

    return CountLNRecursive(root->left) + CountLNRecursive(root->right);

}

///CountNonleafNodes
void CountNLN(Node* root, int &cnt){
if(!root){return;}

if(root->left && root->right){
cnt++;    
}

    if(!root->left && !root->right){
    return;}

    CountNLN(root->left, cnt);
    CountNLN(root->right, cnt);
}

int CountNLNr(Node* root){
    if(!root){return 0 ;}


    if(!root->left && !root->right){
    return 0 ;}

    return 1 + CountNLNr(root->left) + CountNLNr(root->right);
}

//////count Height of Tree -- recursively, iterativly
int Height(Node* root){
    if(!root){return 0;}

    return 1 + max(Height(root->left), Height(root->right));
}

int HeightIterative(Node* root){ //har level ka count rakhugi mai
    queue<Node*> q;
    q.push(root);
    int ans = 0;
    
    while(!q.empty()){
        int size = q.size();
        ans++;

        for(int i = 0; i<size; i++){
         Node* temp = q.front();
        q.pop();

        if(temp->left){q.push(temp->left);}
        if(temp->right){q.push(temp->right);}
        }
        


    }
    return ans;
}

/////Largest value at each level
void LargestAtEach(Node* root,vector<int> &ans){
queue<Node*> q;
q.push(root);


while (!q.empty())
{
     int n = q.size();
    int maxx = INT_MIN;
 
    for(int i = 0; i<n; i++){
    Node* temp = q.front();
    maxx = max(maxx, temp->data);
    q.pop();

    if(temp->left){q.push(temp->left);}
    if(temp->right){q.push(temp->right);}
   }
    ans.push_back(maxx);
}
}


/////////////////////Find if two roots are identical or not/////////
bool TwoMirror(Node* root1, Node* root2){
//mia level by level jake do nodes ki value ko compare kar sakti hu or dono nodes ko bhi

queue<Node*> q1;
queue<Node*> q2;
q1.push(root1);
q2.push(root2);

if(q1.size() != q2.size()){return false;}

while(!q1.empty() && !q2.empty()){
int n1 = q1.size();
int n2 = q2.size();

if(n1 != n2){return false;}

for(int i = 0; i<n1; i++){
Node* temp1 = q1.front();
Node* temp2 = q2.front();
q1.pop(); q2.pop();

if(temp1->data != temp2->data){return false;}

if((temp1->left && !temp2->left) || (!temp1->left && temp2->left)){return false;}
if((temp1->right && !temp2->right) || (!temp1->right && temp1->right)){return false;}

if(temp1->left){q1.push(temp1->left);}
if(temp1->right){q1.push(temp1->right);}

if(temp2->left){q2.push(temp2->left);}
if(temp2->right){q2.push(temp2->right);}
}}

return true;
}

bool CheckmirrorRecursive(Node* root1, Node* root2){

    //check they both are leaf nodes
   if(root1 == nullptr && root2 == nullptr){return 1;}
   //check if any one of them is missing
   if((!root1&& root2) || (root1 && !root2)){
    return 0;
   }
   if(root1->data != root2->data){return 0;}


    return CheckmirrorRecursive(root1->left, root2->left) && CheckmirrorRecursive(root1->right , root2->right);
}

/////////////find mirror image of a tree/////////////////////////////////
void findMirror(Node* root){ //recursivley
if(!root){return;}

Node* temp = root->left;
root->left = root->right;
root->right = temp;

findMirror(root->left);
findMirror(root->right);
}

//iteravly---level order  ka use karugi or ek node ko lungi phir use swap kar dungi
void FindMirror(Node* root){
queue<Node*> q;
q.push(root);

while (!q.empty())
{
    Node* temp = q.front();
    q.pop();
    
    Node* temp = root->left;
root->left = root->right;
root->right = temp;

if(temp->left){q.push(temp->left);}
if(temp->right){q.push(temp->right);}
    
}}

/////////////check if tree is balanced or not
bool CheckIterative(Node* root){
queue<Node* > q;
q.push(root);

while (!q.empty())
{
    Node* temp = q.front();
    q.pop();

    int leftH = Height(temp->left);
    int rightH = Height(temp->right);

    if(abs(leftH - rightH) > 1){return false;}
    
    if(temp->left){q.push(temp->left);}
    if(temp->right){q.push(temp->right);}
}

return false;
}

int CheckBalancedRecursive(Node* root, bool valid){
    if(root == nullptr){return 0;}

    int leftt = CheckBalancedRecursive(root->left, valid);
    int rightt = CheckBalancedRecursive(root->right, valid);

    if(abs(leftt - rightt)){
        valid = false;
    }
    return 1 + max(leftt , rightt);
} 

///////////////////////spiral Level order traversal///////////////
void SpiralLevelOrder(Node* root){
   
}


int main() {
    // vector<int> arr = {3,9,20,-1,-1,15,7,-1,-1,-1,-1};
    // vector<int> arr1 = {3,9,20,-1,-1,15,7,-1,-1,-1,-1};
    vector<int> arr = {1,-1,2};
    vector<int> arr1 = {1,-1,2};
    Node* root = MTreeA(arr);
    Node* root1 = MTreeA(arr1);
    

    if(CheckmirrorRecursive(root, root1)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    

    
    return 0;
}