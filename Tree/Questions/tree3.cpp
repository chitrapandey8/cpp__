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
void TopView(Node* root, vector<int> &ans){
//mai kya karugi ki mai level by leval traversal karugi taki mai har level ka top view lelu, ismai mai ordered map ka bhi use karuhgi mai same y axis pe ane wale elemets ka sabse top wala elment ans mai push karuhgi ye mia map ki help se karugi for O(1) check map pe mai cordinate->or node ka data rahugi jo orders way mia rahega, or mai har level ke node ke cordinate ko check karugi agar voh map mai nhi hoga toh usse daal dungi or agr hua toh igniore

//mai ek queue lungi jismai mai pair dalugi
queue<pair<Node*, int>> q;
map<int, int> mp; 

//root ko dalo queue mai
q.push({root, 0});

while (!q.empty())
{
auto it = q.front();
q.pop();

Node* curr = it.first;
int cordinate = it.second;

//chrck the cordinate in map first;
if(mp.find(cordinate) == mp.end()){
    mp[cordinate] = curr->data;
}

///left child exist kare toh left ko dalo and like wise 
if(curr->left){
    q.push({curr->left, cordinate-1});
}

if(curr->right){
    q.push({curr->right, cordinate+1});
}

}

for(auto it : mp){
    ans.push_back(it.second);
}}

/////////////array se same cheez kese kare , hum ek array le sakte hia 2n+1 size ka, jismai hum intianlly -1 store kar salte hia
void Topviewwitharray(Node* root,vector<int> &ans){
int N = 1000; // max size an tree can be 
vector<int> arr(2*N+1,-1);

int min_cord = INT_MAX;
int max_cord = INT_MIN;
//make queue and insert root; 
queue<pair<Node* , int>> q;
q.push({root,0});

////queue mai iterate karugi, or har node ka cordinate ki vlaue check kruhgi array mai agar voh -1 hohi toh array mai uss node ki value daal dungi
while (!q.empty())
{
    ///node niklao, uska cordiante niklao
    auto it = q.front();
    q.pop();

    Node* curr = it.first;
    int cordinate = it.second;

    //update min or max cordinate
    min_cord = min(min_cord, cordinate);
    max_cord = max(max_cord, cordinate);

    int index = cordinate + N;

    if(arr[index] == -1){
        arr[index] = curr->data;
    }

     ///left child exist kare toh push karo , or right bhi wise versa
     if(curr->left){
        q.push({curr->left , cordinate-1});
     }
     if(curr->right){
        q.push({curr->right , cordinate+1});
     }
}

///insert ans 
for(int x: arr){
    if(x != -1){
        ans.push_back(x);
    }
}


}
///////////////Botthom view//////////////////
void Bottomviewmp(Node* root, vector<int> &ans){
queue<pair<Node*, int>> q;
map<int, int> mp; 

//root ko dalo queue mai
q.push({root, 0});

while (!q.empty())
{
auto it = q.front();
q.pop();

Node* curr = it.first;
int cordinate = it.second;

//chrck the cordinate in map first;

    mp[cordinate] = curr->data;

///left child exist kare toh left ko dalo and like wise 
if(curr->left){
    q.push({curr->left, cordinate-1});
}

if(curr->right){
    q.push({curr->right, cordinate+1});
}

}

for(auto it : mp){
    ans.push_back(it.second);
}
}


/////////////////Bothhom view of Tree with array/////////////////////

void BottomView(Node* root, vector<int> &ans){

    int N = 1000; // max size an tree can be 
vector<int> arr(2*N+1,-1);

int min_cord = INT_MAX;
int max_cord = INT_MIN;
//make queue and insert root; 
queue<pair<Node* , int>> q;
q.push({root,0});

////queue mai iterate karugi, or har node ka cordinate ki vlaue check kruhgi array mai agar voh -1 hohi toh array mai uss node ki value daal dungi
while (!q.empty())
{
    ///node niklao, uska cordiante niklao
    auto it = q.front();
    q.pop();

    Node* curr = it.first;
    int cordinate = it.second;

    //update min or max cordinate
    min_cord = min(min_cord, cordinate);
    max_cord = max(max_cord, cordinate);

    int index = cordinate + N;

    
        arr[index] = curr->data;
    

     ///left child exist kare toh push karo , or right bhi wise versa
     if(curr->left){
        q.push({curr->left , cordinate-1});
     }
     if(curr->right){
        q.push({curr->right , cordinate+1});
     }
}

///insert ans 
for(int x: arr){
    if(x != -1){
        ans.push_back(x);
    }
}



}


int main() {
    vector<int> arr = {20, 8, 22, 5, 3, 4, 25, -1, -1, 10, 14, -1, -1, 28, -1};
    Node* root = MTreeA(arr);
    vector<int> ans;

    
    Bottomviewmp(root, ans);

    for(int x:ans){
        cout<<x<<" ";
    }

    return 0;
}