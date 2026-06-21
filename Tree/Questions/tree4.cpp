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


////max of special nodes/////////////////
int SpecialNode(Node* root, int &sum){
///sabse pehle hum leaf node tak jate hai, agar hume leaf node milt hai toh hum uska data return karte hai coz uske left or right null hote hai, or agar koi esa node mila jiske left or right koi value leke aaye hai toh max sum left or right ko use karke nikal sakti hu, toh mai left right ko consider karke jo bhimax pth hoga usko return kr deti hu uske upar wale parent ko, or agar ek hi ya left ya right exist karte hai toh , data ko add karke parent ko return kar deti

//if i encounter null
if(!root){return 0;}

//if i encounter leafnode
if(!root->left && !root->right){return root->data;}

//calculate left and right for calculating sum
int left  = SpecialNode(root->left, sum);
int right = SpecialNode(root->right, sum);

//if both node exit then only i can calulate one special node to another special node max sum
if(root->left && root->right){
    sum = max(sum, root->data + left + right);
    return root->data + max(left, right);
}

////if only one of the node exist then i just return
if(root->left){
    return root->data + left;
}

if(root->right){
    return root->data + right;
}



return 0;
}


int main() {
    vector<int> arr = {-15, 5, 6, -8, 1, 3, 9, 2, -3, 0, 4, -1, 10};
    Node* root = MTreeA(arr);
    int sum = INT_MIN;

    SpecialNode(root, sum);
    cout<<sum<<endl;

    return 0;
}