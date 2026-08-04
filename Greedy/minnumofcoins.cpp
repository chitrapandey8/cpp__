#include<bits/stdc++.h>
using namespace std;

///Shop in candy store
void CandyStore(vector<int> candies, int n, int k, vector<int> &ans){
    //buy all  candies with min cost , at evey buy u can k free candies 
    //n is lenght if array , k = 2, kisi bhi 2 candy ko free mai le sakti hu
    sort(candies.begin(), candies.end());
    int min_amaout = 0, max_amount= 0;
    int i = 0; j = n-1;
    while(i <= j){
        min_amaout += candies[i];
        i++;
        j -= k;
    }

    i = n-1, j=0;
    while (i>=j)
    {
        max_amount += candies[i];
        i--;
        j += k;
    }
 ans.push_back(min_amaout);
 ans.push_back(max_amount);
    
} 

/////////Assigns mice to holes --- ek array hai position ka for ex: [4, -4, 2] or mujhe holes ka araray bhi diya [4,0,5] mujhe min time ke andar sab chuhe ko bill ke andar dalna hai, or jab min time legega mujhe usse return karna hai
void micandholes{
    //i will sort both araray and i will send the mic into the same index holes.

}

void MinRoatationtoUnloackacircularLock(long long R, long long D){
    //min karke dekho
    int ans = 0;
    int first, second  = 0;
    while(R){
        first  = R%10;
        second = D%10;
        R = R/10;
        D = D/10;
        ans += min(abs(first-second), 10-abs(first-second));
    }
}

//N meeting in one room.
//mujhe meeting ka start or end time de rakha hia, do arrays mai.
//agar end time chota hai strat time se i can orgainsie a meeting.
//sabse ophele hamse voh meeting ka dekha jo sabse pehel chalu hogi ye kaam nhi kara 
///toh aab ham end time dekhege ki sabse pheel kon khatm hogi.
bool comp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;

}

void meeting(vector<int> start, vector<int> end, int n){
    vector<pair<int, int>> timer;
    for(int i = 0; i<n; i++){
        timer.push_back({start[i], end[i]});
    }

    sort(timer.begin(), timer.end(), comp);
    int total = 0;
    int ending = -1;
    for(int i = 0; i<n; i++){
        if(timer[i].first > ending){
            total++;
            ending = timer[i].second;
        }
    }
    cout<<total<<endl;

}

//job sequxncing problem
//im given job, deadline, profit
//          1      4      20
//          2      1      10
//          3      1      40
//          4      1      30
//max dealine  = 4, dealine array = [0,0,0,0] also i want to amximaize profit so i will do task whcih will have higest profit, usko jaker fill karo agar filled hai toh usse pehele dkeho agar khali h toh waha bhardo, or agar kahi bhi hali nhi hai toh voh ho hi nhi skata
//so what if i sort basis of profit
struct job
{
    int id;
    int dead; 
    int profit;
};
bool comp(job a, job b){
return a.profit > b.profit;
}

int find(int num, vector<int> &parent){
  if(num == parent[num]){
    return num;
  }
  return parent[num]  =  find(parent[num], parent);
}

void Jobsequcning(vector<int> job, int n){
sort(job.begin(), job.end());

int deadline = 0;
for(int i = 0; i<n; i++){
    deadline = max(deadline, job[i].dead);
}
vector<int> Parent(deadline+1);
for(int i =0; i<=deadline; i++){
    Parent[i] = i;
}
vector<bool> Task(deadline+1, 0);
vector<int> ans(2,0);

for(int i = 0; i<n; i++){
    int slot =  find(arr[i].dead, parent);
    if(slot>0){
        ans[0]++;
        ans[1] += arr[i].profit;
        Parent[slot] = slot-1;
    }
}
//time - 

// for(int i = 0; i<n; i++){ // lya mai dealine ya usse phele complete kar sakti hu
//     for(int j = arr[i].dead; j > 0; j--){
//         if(!Task[j]){
//            Task[j] = 1;
//            ans[0]++;
//            ans[i] += arr[i].profit;
//            break;
//         }
//     }
// }

}


int main{
    return 0;
}