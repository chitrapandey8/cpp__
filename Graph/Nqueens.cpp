#include <bits/stdc++.h>
using namespace std;

///time complexity -- N ,* n-1 * n-2 = O(n!)
//Space Com[plexity] O(n*n)

bool Check(int n, vector<string> Board, int i, int j){

    ////upper left dig,
    int row = i; int col = j;
    while(row>-1 && col >-1){
        if(Board[row][col] == 'Q'){
            return 0;
        }
        row--; col--;
    }
    //uppper right Dig,
   row = i; col = j;
   while(row > -1 && col < n){
    if(Board[row][col] == 'Q'){
        return 0;
    }
    row--; col++;
   }

  return 1;
}

void find(int row, int n, vector<vector<string>> ans, vector<string> Board, vector<bool> column, vector<int> leftDig, vector<int> RightDig){
//left Dig = n-1+col-row
//right : row+col
    if(row == n){
        ans.push_back(Board);
        return;
    }
//Base Condition
for(int j = 0; j<n; j++){
    if(column[j] == 0 && leftDig[n-1+j-row] == 0 && RightDig[row+j] == 0){
        column[j] = 1;
        Board[row][j]= 'Q';
        leftDig[n-1+j-row] = 1;
        RightDig[row+j] = 1;
        find(row+1, n, ans, Board, column, leftDig, RightDig); //agar aab next row p ebhar nhi sakti toh wapas row pe jao
        column[j ] = 0;
        Board[row][j] = '.';
        leftDig[n-1+j-row] = 0;
        RightDig[row+j] = 0;


    }
}
}

void SolveQueens(int n, vector<vector<string>> ans){
vector<string>Board(n);
for(int i= 0; i<n; i++){
    for(int j = 0; j<n; j++){
        Board[i].push_back('.');
    }
}
vector<int> leftDig(2*n-1, 0);
vector<int> RightDig(2*n-1, 0);

vector<bool> column(n,0);

find(0, n, ans, Board, column, leftDig, RightDig);
}

int main() {
    return 0;
}