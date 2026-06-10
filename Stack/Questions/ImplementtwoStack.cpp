#include <bits/stdc++.h>
using namespace std;
class Nstack{
    public:
    ///kya kya  cheeze hogi
    int *arr;
    int top1;
    int top2;
    int size;

    ///Initialisation
    Nstack(int n){
      this->size = n;
      arr  = new int[n];
      top1 = -1;
      top2 = n;
    }

    ///push in Stack 1
    void Push1(int x){
        if(top1 + 1 == top2){
            return;
        }

        top1++;
        arr[top1] = x;
    }
    
    //push in stack2
    void Push2(int x){
        if(top2 - 1 == top1){
            return;
        }

        top2--;
        arr[top2] = x;
    }
    
    //popp and return from stack1
    int Pop1(){
        if(top1 == -1){
            return -1;
        }

        int ele = arr[top1];
        top1--;
        return ele;
    }

    int Pop2(){
        if(top2 == size){
            return -1;
        }

        int ele = arr[top2];
        top2++;
        return ele;
    }



};

int main() {
    Nstack st(5);
    st.Push1(1);
    st.Push1(2);
    st.Push2(5);
    cout<<st.Pop1()<<endl;
    cout<<st.Pop2()<<endl;

    return 0;
}