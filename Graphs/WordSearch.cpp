/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once. 
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &board,int i,int j, string word,int k) {
    if (k==word.length()) return true;
    if (i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][k]!=word[k]) return false;
    char temp=board[i][j];
    board[i][j]='#'; // mark current cell as visited
    bool found=dfs(board,i+1,j,word,k+1) || dfs(board,i-1,j,word,k+1) || dfs(board,i,j+1,word,k+1) || dfs(board,i,j-1,word,k+1);
    board[i][j]=temp; // unmark cell
    return found;
}
bool exist(vector<vector<char>> &board,string word) {
    int m=board.size(),n=board[0].size();
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (dfs(board,i,j,word,0)) return true;
        }
    }
    return false;
}

// Further optimisation can be done by elimination invalid starting points and early temination (pruning) by checking wjether the board contains enough of each cahracter in the word  
