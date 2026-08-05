#include <bits/stdc++.h>
using namespace std;

///single threaded cpu=---ek baar mai ek hi process excute karana
//cpu will do task with less processing task.
//  enqueueT , Processing time
//   1   2
//   2   4
//   3   2
//   4   1
// sabse pehele enqueue time ke basis pe soirt karo but sortint ki awaj se time complexity bhad jayegei so will use min heap.so i will keep in heap basis of mini processing time.
//logic
//sort the aaraay on the basis of enqueue time
//timer intilize with fist time enqeueue time
    //push all the task into min heap whose enqueue time is leass then eual to timer.
    //if min heap is empty timer == enqueue of next task se intial krdo.
    //or agar kuch pada hai toh elemeent ko pop karo, timer increase karo , timer+= processing time.

void Solvee(vector<vector<int>> &Task){
    vector<int> ans;
    int n = Task.size();
    for(int i = 0; i<n; i++){
        Task[i].push_back(i);
    }

    //sort the task on the basis of enqueue time.
    sort(Task.begin(), Task.end());
    long long  timer = Task[0][0]; //ene]quee time se initial kardo.
    int i = 0;

    //put all the task into min hrap whose eneueeu time is less than equaal to timer.
    //if min heap is empty or not empty.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    while(!q.empty() && i < n){

        while(i < n && timer >= timer[i][0]){
            q.push({Task[i][1] , Task[i][2]});
            i++;
        }   
    
        //if min heap is empty
        if(!q.empty()){
            time =  Task[i][0];
        }
        //not empty
        else{
            ans.push_back(q.top().second); //index hai secpnf value
            timer += q.top().first;
            q.pop();
        }
    }
    cout<<ans<<endl;
}



///////////////Factional Knapsack//////////////////

//value - [60,100,120]
//weight - [10,20,30]  , w=50 of bag.
//mai usko rakhugi jiski value/weight sabse jayada hogi.
//mujhe sabse pehel value/weight ke basis pe sort karna hai, decesnding order.
struct Item{
    int value;
    int weight;
}


bool comp(){
    return a.value*b.weight > b.value*a.weight;
}

void Fractional(int w, vector<int> arr, int n){
sort(arr.begin(), arr.end(), comp);

int profit = 0;
int i = 0;
while(w&&i<n){
  if(w>=arr[i].weight){
    profit += arr[i].value;
    w -= arr[i].weight;
  }else{
    double temp = arr[i].value;
    temp /= arr[i].weight;
    profit += temp*w;
    w = 0;
  }
  i++;
}

}

////////////Non - overlaping interval/////////////
//agar ksis ka strat time kisi ke end time se chota at ahi toh overlappiinh hai, so i have to remove overlaping interval taki sare non overlapping ho jaye.
//hum ismai end time dekhte hai ki jo pehele khatm ho jaye  usko lo.
bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

void Erase(vector<vector<int>> &intervals){
sort(intervals.begin(), intervals.end());

int end = INT_MIN;
int remove = 0;

for(int i = 0; i<intervals.size(); i++){
    if(end <= intervals[i][0]){ //end chita hia starttimese 
        end = intervals[i][1]; 
    }else{
        remove++;
    }
}

}

///////////insert interval//////////////////
//[1,3], [6,9], [10,20] | [2,5]


vector<vector<int>> Insertintervl(vector<vector<int>> &interval, vector<int> &newI){
    vector<vector<int>> ans;

    int i = 0, n = interval.size();
    while(i<n && newI[0] > interval[i][1]){
        ans.push_back(interval[i]);
        i++;
    }
    if(i == n){
        ans.push_back(newI);
        return ans;
    }

    while(i < n && newI[1] >= interval[i][0]){
        newI[0] = min(newI[0], interval[i][0]);
        newI[1] = max(newI[1], interval[i][1]);
        i++;
    }
    ans.push_back(newI);
    while(i<n){
        ans.push_back(interval[i]);
        i++;
    }
  return ans;

}


//Tasl Schedular/////////////////
//1. AAABBC, n=2;
//agar A ko excute kaaraya toh i have to wait n = 2 then i can, anothwr A, but i can excute B. or mujhe min time batana taki sare tsk excute kara pau mai.

//AAAA BBBCC D ,n =2
// A _ _ A _ _ A _ _ A
// A B C A B C A B D A = 10 cycle mai hoajyega // sabse jayada freq . (count-1) * (n+1)+1
//AAABBB, n = 2, is case mai jiski freq highest ke barara bar ko uske liye bhi +1 karna hia

//AAAA BBBB CCCC, n = 3
//A _ _ _ A _ _ _ A _ _ _ A
//A B _ _ A B _ _ A B _ _ A B
//A B C _ A B C _ A B C _ A B C

// (4-1) * (3+1) + 3 = 

///AAAA BBBB CCC DDD E, n = 2
//A _ _ A _ _ A _ _ A
//A B _ A B _ A B _ A B
//A B C A B C A B C A B 
// (4-1) * (2+1) + 2 = 11 but actuial ans is 15 so how? so i will comapre (11, size of string) , max(11, 15) = 15.

int TaskSechuler(vector<char> &Task, int n){
//calculate the frequcnty of each char
vector<int> freq(26,0); int count = 0;
for(int i = 0; i< Task.size(); i++){
    freq[Task[i] - 'A']++;
    count = max(count, freq[Task[i] - 'A']);
}

int ans = (count-1)*(n+1);
for(int i = 0; i<26; i++){
    if(freq[i] == count){
        ans++;
    }
}

return ans> Task.size() ? ans : Task.size();
}

///Huff Man Coding
//har ek charchater = 8bit lega or total input mia kitne characcters hia for explae = 100 so bits will be 800. it willbe huge so can i decrese the size.
//so instrad of following ascii i will make my own, like 000, 001, 010, 011, 100, 101 for every charcher like a, b , c, d, e, f
//jo sabse jayda baar aaye uski value or kam kardege 
// a = 5
// b = 9
// c  =12
// d = 13
// e = 16
// f = 45              


class Node{
public:
int freq;
char c;
Node *left;
Node *right;

Node(int freqency, char name){
    freq = freqency;
    c = name;
    left = right =  nullptr;
}

}

class comp {
    public:
    bool operator()(Node *a, Node *b){
      return  a->freq  > ->freq; //heap ke case mai ye logic ulta kaam akrta hia
    }
}

void Preorder(Node* root, string &temp, vector<string> &ans){
if(!root){
    return;
}

if(!root->left  && !root->right){
  ans.push_back(temp);
  return;
}

temp.push_back('0');
Preorder(root->left, temp, ans);
temp.pop_back();
temp.push_back('1');
Preorder(root->right, temp, ans);
temp.pop_back();
}

vector<string> HuffmanCoding(string s , vector<int> f, int N){

    //build the hoffman tree
    //build the min heap on the bassi of frequncy.
    priority_queue<Node* , vector<Node*> , comp> q;
    for(int i =0; i<N; i++){
        q.push(new Node(f[i], s[i])); // freq or uska char

    }
    while(q.size() > 1){
        Node *first = q.top();
        q.pop();
        Node *second = q.top();
        q.pop();
        
        Node *root = new Node(first->freq, second->freq, '$');
        root->left = first;
        root->right = second;
        q.push(root);
    }
  Node *root = q.top();
  q.pop();

  //////preorder niklaa 
  vector<string> ans;
  string temp;
preorder(root, temp, ans);
return ans;

}
    
int main() {

    return 0;
}