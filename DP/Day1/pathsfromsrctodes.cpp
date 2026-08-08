#include <bits/stdc++.h>
using namespace std;

int arr[3][3];
int main() {
    arr[0][0]= 1;
    for(int i = 0; i<3; i++){
        for(int j = 0; j <3; j++){
            if(i+1 < 3){
                arr[i+1][j] += arr[i][j];
            }
            if(j+1 < 3){
                arr[i][j+1] += arr[i][j];
            }
        }
    }

    cout<<arr[2][2]<<endl;

    return 0;
}