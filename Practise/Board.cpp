#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<string>> board = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{"8","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
     for(int i = 0; i<9; i++){
            unordered_set<string> hs;
            for(int j = 0; j<9; j++){
                if(hs.count(board[i][j])){
                    cout<<"false"<<endl;
                    return 0;
                }
                hs.insert(board[i][j]);
            }
        }
         
        for(int i = 0; i<9; i++){
            unordered_set<string> hs;
            for(int j = 0; j<9; j++){
                if(hs.count(board[j][i])){
                    cout<<"false"<<endl;
                    
                }
                hs.insert(board[j][i]);
            }
        }

    return 0;
}