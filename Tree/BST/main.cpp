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
////////////////////check karo ki preorder aaya jo diya hai voh valid h ya nhi///////////
bool Check(vector<int> arr){
    //har root ko leke check karte hai hi valid hai ya nhi, preorder mai first eleemt root hota hai ot uske aage sare chote eleemt left m,ai aat4 hai or jab pehela bada eleemt aaya  toh uske aage aane wale sare eleemt bade honge aagr koi bhi chota ayaa toh invalid
    
    for(int i = 0; i<arr.size(); i++){
        int root = arr[i];

        int j = i+1;
        while (j<arr.size() && arr[j] < root)
        {
            j++;
        }

        for(int k = j; k<arr.size(); k++){
            if(arr[k] < root){
                return false;
            }
        }}
    return true;
}

///////iskki ko humstakc se bhi kar sakte hia
bool Checkk(vector<int> arr){
    //hum kys ksrke hsi ki stack rakhte hai or or pehela max aane ke baad agar koi chota aata hai toh return false concept toh wahi hai
    stack<int> s;
      int root = INT_MIN;
      for (int i = 0; i < arr.size(); i++)
      {
        if(arr[i] < root){
            return false;
        }

        while (!s.empty() && arr[i] > s.top())
        {
            root = s.top();
            s.pop();
        }
        s.push(arr[i]);
        
      }
      
    
   return true;
}


///////////////////////find lowest commkom ancestor of bst/////////////
TreeNode* findlowestCommon(TreeNode* root, int n1, int n2){
if(!root){return nullptr;}

if(root->data > n1 && root->data > n2){
   return  findlowestCommon(root->left, n1, n2);
}else if(root->data < n1 && root->data < n2){
   return  findlowestCommon(root->right, n1, n2);
}else{

    return root;
}
}

/////same as this question i have to find the lowest commom ancestor
TreeNode* LowestCommon(TreeNode* root, TreeNode* p, TreeNode* q){
  if(root == nullptr || root == p || root == q){
     return root;
  }

  TreeNode* left = LowestCommon(root->left, p, q);
  TreeNode* right = LowestCommon(root->right, p, q);

  if(left != nullptr && right != nullptr){
    return root;
  }
  if(left == nullptr){
    return right;
  }
   
    return left;
}

//////////////////////CHECK WHETHER a tree contains a dead end or not
//when willl a tree have an dead end when we are not able to insert a child to a parent when that node is already present in tree.

bool CheckforDE(TreeNode* root, int min, int max){

    if(!root){return false;} ///root nulltak pohoch gaya iske amtln abhi tak koi dead end nhi mila mujjhe

    if(min == max){ //agar aagr range mai min or max value same aaagyi iska mtlb  ye dead endhai
        return true;
    }

    return  CheckforDE(root, min, root->data-1) || CheckforDE(root, root->data+1, max);

}

//////////////find common nodes in two bsts

void Searchh(TreeNode* root, int target){
     if(!root){
        return ;
     }
     
    if(root->data == target){
        cout<<root->data<<endl;
        return;
    }

    if(root->data < target){
            Search(root->right, target);
    }else{
            Search(root->left, target);
    }}


void FindinBst1(TreeNode* root1,  TreeNode* root2){
    if(!root1){return ;}

    FindinBst1(root1->left, root2);
    Searchh(root2, root1->data);
    FindinBst1(root1->right, root2);

}

////////issi question ko mai set see bi kar skti hu -- kese agar ek  bst pe traverse krke set mai daal du or dusre bst pe traverse karke ye dekhu ki uski value already set mai hai ya nhi

void FindCommon(TreeNode* root, unordered_set<int> hs, vector<int> &ans){
    if(!root){return;}

    FindCommon(root->left, hs, ans);
    if(hs.count(root->data)){
        ans.push_back(root->data);
    }
    FindCommon(root->right, hs, ans);



}

///isis question ko hum two pointer approach se bhi kar sakte hai, jaise hum two soreted array pe traverse karte the b=vese hi ismai bhihum two pointer approach hi laagyege, hum sorted order mai print karne keliye left as possible or tree mai jayege,  phir checxk karege phir hum righr mai jayege
void FindCommonn(TreeNode* root1, TreeNode* root2, vector<int> &ans){
    stack<TreeNode* > s1;
    stack<TreeNode* > s2;

    TreeNode* curr1 = s1.top();
    TreeNode* curr2 = s2.top();

    while (true)
    {
      ////insert in stack and go left as posssible
      while(curr1 != nullptr){
        s1.push(curr1);
        curr1 = curr1->left;
      }
      while(curr2 != nullptr){
        s2.push(curr2);
        curr2 = curr2->left;
      }

      ///ab check karo ki top par kon hai usse pehele dono top ko save karlo
      TreeNode* top1  = s1.top();
      TreeNode* top2 = s2.top();

      /////////////////////cases//////////////////////
      if(s1.top()->data  == s2.top()->data){
        ans.push_back(s1.top()->data);
        s1.pop();
        s2.pop(); 
        curr1 = top1->right;
        curr2 = top2->right;

      }else if(s1.top()->data < s2.top()->data){
         s1.pop();
         curr1 = top1->right;
         curr2 = nullptr;
      }else{
         s2.pop();
         curr2 = top2->right;
         curr1 = nullptr;
      }



    }
    

}




int main() {
    vector<int> arr = {5, 4, 6, 3, -1, -1, 7, -1, -1, -1, 8};
    TreeNode* root = nullptr; int n1 = 7; int n2 = 8;
    for(int x: arr){
        root = Create(root, x);
    }

    
    TreeNode* ans = root;
    cout<<ans->data<<endl;
     
    return 0;
}