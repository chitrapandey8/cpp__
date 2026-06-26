#include <bits/stdc++.h>
using namespace std;
int mindiff = INT_MAX;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
     this->data = data;
     this->left = nullptr;
     this->right = nullptr;
    }
};


///Create a Binary Search Tree--- i will be adding node when i reach null, and when the node is smaller then the current node then i go to left, else i go right
TreeNode*  Create(TreeNode *root, int val){
  

    if(!root){
        TreeNode* temp = new TreeNode(val);
        return temp;
    }

    if(root->data < val){
       root->right =  Create(root->right, val);
    }else{
      root->left =   Create(root->left , val);
    }
    return root;
}

void inorder(TreeNode* root){
    if(!root){return;}

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

////////////////////Search in Tree////////////////////
bool Search(TreeNode* root, int target){
     if(!root){
        return 0;
     }
     
    if(root->data == target){
        return 1;
    }

    if(root->data < target){
    return   Search(root->right, target);
    }else{
      return   Search(root->left, target);
    }}


////////////////////Delete a Node//////////////////////////////////
TreeNode* Deletenode(TreeNode* root, int target){
if(!root ){return nullptr;}


//root ko jake dekho kaha ho sakta hai
if(root->data < target){
    root->right = Deletenode(root->right, target);
}else if (root->data > target){
    root->left = Deletenode(root->left, target);
}else{
    ///abb cases dekho ki node kesa hai leaf hai ya single child ya dono child hia
    if(!root->left && !root->right){
      delete root;
    }else if(!root->right){ // agar sirf left chil hai toh rightr null hoga 
        TreeNode* temp = root->left;
        delete root;
        return temp;
    }else if(!root->left){
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }else{
        ////agar dono child hai toh mai left ka greated elemet dhuhugi

        TreeNode* parent = root;
        TreeNode* child = root->left;

        while (child->right)
        {
            parent = child;
            child = child->right;
        }
          
        if(root != parent){
         ///save the predecessors left 
          parent->right = child->left;
          child->left = root->left;
          child->right = root->right;
          delete root;
          return child;

        }else{
        ///agar root ka just left ki next predesessort hai toh 
        child->right = root->right;
        delete root;
        return child;
        }



    }


}
return root;

}
////////////check if BST////////////////
bool Checkisitisbst(TreeNode* root, int min, int max){

    // if(!root){return true;}

    // //check range ke bahar toh nhi h
    // if(root->data <= min || root->data >= max){
    //     return false;
    // }

    // return Checkisitisbst(root->left, min, root->data) && Checkisitisbst(root->right, root->data, max);
return 0;
}



////////////MIn differnece in the tree/////////////////

void CompareWithAll(TreeNode* tobeCompared, TreeNode* root, int &minDiff){
    ////ye function pure tree mai traverse karke differnece nikaltata hai
    if(!root){
        return;
    }

    if(tobeCompared != root){
        int d  = abs(tobeCompared->data - root->data);
      mindiff = min(minDiff, d);
    }

    CompareWithAll(tobeCompared, root->left, minDiff);
    CompareWithAll(tobeCompared, root->right, minDiff);
}

void Traverse(TreeNode* current, TreeNode* root, int &minDiff){
 if(!root){
        return;
    }
    ///har ek node ko leke baki sab se compare karne bhej do
    CompareWithAll(current, root, minDiff);

     Traverse(current->left, root, minDiff);
    Traverse(current->right, root, minDiff);


}

void sum(TreeNode* root, int &k, int &summ){
if(!root){
    return;
}
sum(root->left, k, summ);
k--;

if(k >= 0){
    summ += root->data;
}
if(k <= 0){
    return;
}
sum(root->right, k, summ);

}

void kthlargestinarray(TreeNode* root, int &k, int &ans){
if(!root){return;}

kthlargestinarray(root->right, k, ans);
k--;
if(k == 0){
    ans = root->data;
    return;
}
kthlargestinarray(root->left,k, ans);


}

///given a sorted array create a balannced Binary tree
TreeNode* DivideAndConquer(vector<int> arr, int start, int end){
    if(start > end){
        return nullptr;
    }
    
    int mid = start + (end- start)/2;

    TreeNode* newnode = new TreeNode(arr[mid]);

    newnode->left = DivideAndConquer(arr, start, mid-1);
    newnode->right =  DivideAndConquer(arr, mid+1, end);
    return newnode;

}


int main() {
    vector<int> arr = {1,2,3,4,5,6};
    
    // for(int x: arr){
    //     root = Create(root, x);
    // }

     TreeNode* root = DivideAndConquer(arr, 0, arr.size()-1);
     inorder(root);
    return 0;
}