#include <bits/stdc++.h>
using namespace std;

bool Check(int num, vector<vector<char>> &Board, int i, int j){
    char c = '0'+num;

    //check at same row
    for(int col = 0; col<9; col++){
        if(Board[i][col] == c){
            return 0;
        }
    }
    //check at same col 
    for(int row = 0; row<9; row++){
        if(Board[row][j] == c){
            return 0;
        }
    }
    //check for sa,e box
    int row = i/3+3, col = j/3+3;
    for(int a = 0; a<3; a++){
        for(int b = 0; b<3; b++){
            if(Board[a+row][b+col] == c){
                return 0;
            }
        }
    }
  return 1;


}

bool find(int i, int j, vector<vector<char>> &Board){
    //base
    if(i == 0){
        return 1;
    }

    if(j == 9) return find(i+1, 0, Board);

    if(Board[i][j] != '.'){
        return find(i, j+1, Board);
    }

    for(int num =1; num <10; num++){
        if(Check(num, Board, i, j)){
            Board[i][j] = '0' + num;
            find(i, j+1, Board){
                return 1;
            }
            Board[i][j] = '.';

        }
    }
    return 0;
}

void Solve(vector<vector<char>> &Board){
    find(0,0, board);
     
}

int main() {
    return 0;
}