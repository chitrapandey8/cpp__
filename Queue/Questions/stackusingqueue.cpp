#include <bits/stdc++.h>
using namespace std;

class stack{
    queue<int> q1;
    queue<int> q2;

    public:

    bool empty(){
        return q1.empty() &&  q2.empty();
    }

    //////push weree elemtss are preset
    void push(int x){
      if(empty()){
        q1.push(x);
      }else if(q1.empty()){
        q2.push(x);
      }else{
        q1.push(x);
      }
    }

    int pop(){
        if(empty()){
            return 0;
        }else if(q1.empty()){ //q2 ke andar leemts hai toh last ko chorke q1 maqi daldo sare
                while(q2.size()>1){
                    q1.push(q2.front());
                    q2.pop();
                }

                int ele = q2.front();
                q2.pop();
                return ele;
        }else{
            while(q1.size()>1){
                    q2.push(q1.front());
                    q1.pop();
                }

                int ele = q1.front();
                q1.pop();
                return ele;
        }
    }

    int top(){
        if(empty()){
            return 0;

        }else if(q1.empty()){
            return q2.back();
        }else{
           return  q1.back();
        }
    }

};

int main() {
    return 0;
}