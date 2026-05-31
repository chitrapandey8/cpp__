#include <bits/stdc++.h>
using namespace std;

void TOH(int n, char source, char helper, char destination){

    if(n == 1){
        cout<<"MOVE"<<" "<<n<<" "<<"DISK"<<" "<<"FROM"<<" "<<source<<" "<<"TO"<<destination<<endl;
        return;
    }

    TOH(n-1, source, destination, helper);
    cout<<"MOVE"<<" "<<n<<" "<<"DISK"<<" "<<"FROM"<<" "<<source<<" "<<"TO"<<destination<<endl;
    TOH(n-1,helper,source,destination);

}



int main() {
    TOH(3,'A','B','C');
    return 0;
}