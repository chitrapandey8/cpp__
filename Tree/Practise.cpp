////////////Tree is a non linear data structure that stores data in a heirarchy, like a parent child relation, there are various terminology.
#include<bits/stdc++.h>
using namespace std;

class BT{
    public:
    int data;
    BT* left;
    BT* right;

    BT(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


BT* createiterative(){
    ///make root at first
      queue<BT*> q;
 
    cout<<"Enter root value:"<<endl;
    int root; cin>>root;
    BT* newnode = new BT(root);
    q.push(newnode);
    while(!q.empty()){
        BT* node = q.front();
        q.pop();

        cout<<"Enter left child of"<<node->data<<" "<<endl;
        int left; cin>>left;
        if(left != -1){
            node->left = new BT(left);
            q.push(node->left);
            cout<<node->data<<" "<<"leftchild:"<<" "<<left<<endl;
        }
        cout<<"Enter right child"<<node->data<<" "<<endl;
        int right; cin>>right;
        if(right != -1){
           node->right =  new BT(right);
           q.push(node->right);
           cout<<node->data<<" "<<"rightchild:"<<" "<<left<<endl;
        }
    }

  return newnode;
}
BT* createiterativewithloop(vector<int> &arr){
    ///make root at first
      queue<BT*> q;
    int i = 0;
    BT* newnode = new BT(arr[i++]);
    q.push(newnode);
    while(!q.empty()){
        BT* node = q.front();
        q.pop();

        
        if(arr[i] != -1){
            node->left = new BT(arr[i++]);
            q.push(node->left);
        }
        
        if(arr[i] != -1){
           node->right =  new BT(arr[i++]);
           q.push(node->right);
        }
    }

  return newnode;
}

void Preorder(BT* root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void inorder(BT* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void levelorderTraversal(BT* root){
    queue<BT*> q;
    q.push(root);
    while(!q.empty()){
    BT* node = q.front();
    q.pop();
    cout<<node->data<<" ";

    if(node->left){
        q.push(node->left);
    }
    if(node->right){
        q.push(node->right);
    }

    }
}

bool isLeaf(BT* root){
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    return false;
}

void collectLeftnode(BT* root, vector<int> &res){
    //agar ye leaf node hai toh return , coz we dont have to count the leaf nodes
      if(root == nullptr || isLeaf(root)){
        return;
      }

      res.push_back(root->data);
      if(root->left){
         collectLeftnode(root->left, res);
      }else if(root->right){
        collectLeftnode(root->right, res);
      }
}
void collectrightnode(BT* root, vector<int> &res){
    //agar ye leaf node hai toh return , coz we dont have to count the leaf nodes
      if(root == nullptr || isLeaf(root)){
        return;
      }

      if(root->right){
          collectLeftnode(root->right, res);
        }else if(root->left){
            collectLeftnode(root->left, res);
        }
        res.push_back(root->data);
}
void collectRightnode(BT* root, vector<int> &res){
    //agar ye leaf node hai toh return , coz we dont have to count the leaf nodes
      if(root == nullptr || isLeaf(root)){
        return;
      }

      res.push_back(root->data);
      if(root->left){
         collectRightnode(root->left, res);
      }else if(root->right){
        collectRightnode(root->right, res);
      }
}


void collectLeaves(BT* root, vector<int> &res){
   if(root == nullptr){
    return;
   }
   if(isLeaf(root)){
    res.push_back(root->data);
   }

   collectLeaves(root->left, res);
   collectLeaves(root->right, res);
}


void BoundaryTraversal(BT* root, vector<int> &res){

    ///////collect left then all leaf nodes and then all right nodes
    if(root != nullptr || isLeaf(root)){
        res.push_back(root->data);
    }else{
        return;
    }

    //collect left
    collectLeftnode(root->left, res);
    //collect leaves
    collectLeaves(root, res);
    //collect right
    collectRightnode(root->right, res);

    ////TC - O(N) in worst case , O(H) for left, O(H) for rightm for leaf O(N) in worst
    //SC - O(H) for yhe recursion stack

}

///morris inorder traversal
void morrisTraversals(BT* root, vector<int> &res){
   
    BT* curr = root;
    while(curr != nullptr){
        
        if(curr->left == nullptr){
            res.push_back(curr->data);
            curr = curr->right;
        }else{
            BT* prev = curr->left;

            while(prev->right != nullptr && prev->right != curr){
                prev = prev->right;
            }
             
            if(prev->right == nullptr){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;

            }

        }
    }

}

void DiagonalTraversal(BT* root, vector<int> &res){

    queue<BT*> q;
    q.push(root);
    while (!q.empty())
    {
        BT* curr = q.front();
        q.pop();
        while (curr != nullptr)
        {
            if(curr != nullptr){
                res.push_back(curr->data);
            }

            if(curr->left){
                q.push(curr->left);
            }
            curr = curr->right;
        }}}

void DiagonalTraversalRecursion(BT* root, vector<vector<int>> &res , int level){
    
    if(root == nullptr){
        return;
    }

    if(level == res.size()){
      res.push_back({});
    }

    res[level].push_back(root->data);
    DiagonalTraversalRecursion(root->left, res, level+1);
    DiagonalTraversalRecursion(root->right, res, level);

}

///finding level of the target
int FindLevel(BT* root, int level, int target){
   if(root == nullptr){
    return -1;
   }
   if(root->data == target){ 
      return level;
   }

   int checkleft = FindLevel(root->left, level+1, target);    
   if(checkleft != -1){
    return checkleft;
   }
   return FindLevel(root->right, level+1, target);    
}

int FindParentofthechild(BT* root, int target){
  if(root == nullptr){
    return -1;
  }
  if(!isLeaf(root) && (root->left->data == target || root->right->data == target)){
    return root->data;
  }
  int res = FindParentofthechild(root->left, target);
  if(res != -1){
    return res;
  }
   return FindParentofthechild(root->right, target);
}

bool SearchNode(BT* root, int target){
    if(root == nullptr){
        return false;
    }
    if(root->data == target){
        return true;
    }

    bool res =  SearchNode(root->left, target);
    if(res != false){
      return res;
    }
     
    return SearchNode(root->right, target);
}


int main(int argc, char const *argv[])
{    
    vector<int> arr= {1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1};
    BT* root =  createiterativewithloop(arr);
    int target = 7;
    cout<<FindParentofthechild(root,target);

    
    return 0;
}

