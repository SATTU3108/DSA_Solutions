/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board) {
    vector<vector<bool>> row_check(9,vector<bool> (9,false));
    vector<vector<bool>> col_check(9,vector<bool> (9,false));
    vector<vector<bool>> subbox_check(9,vector<bool> (9,false));
    for (int row=0;row<9;row++) {
        for (int col=0;col<9;col++) {
            if (board[row][col]=='.') continue;
            int num=board[row][col]-'0'-1;
            int subbox_index=(row/3)*3+(col%3);
            if (row_check[row][num]) return false;
            if (col_check[col][num]) return false;
            if (subbox_check[subbox_index][num]) return false;
            row_check[row][num]=true;
            col_check[col][num]=true;
            subbox_check[subbox_index][num]=true;
        }
    }
    return true;
}
