#include <bits/stdc++.h>
using namespace std;

/*
Given an m x n grid of characters board and a string word, return true if the word exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/

bool searchNext(vector<vector<char>> &board,int m,int n, string word, int index, int row, int col) {
    if (index==word.length()) return true;
    if (row<0 || col<0 || row==m || col==n || board[row][col]!=word[index] || board[row][col]=='!') return false;
    char c=board[row][col];
    board[row][col]='!';
    bool top=searchNext(board,m,n,word,index+1,row-1,col);
    bool right=searchNext(board,m,n,word,index+1,row,col+1);
    bool down=searchNext(board,m,n,word,index+1,row+1,col);
    bool left=searchNext(board,m,n,word,index,row,col-1);
    board[row][col]=c;
    return (top || right || down || left);
}
bool exist(vector<vector<char>> board,string word) {
    int m=board.size(),n=board[0].size();
    int index=0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (board[i][j]==word[index]) {
                if (searchNext(board,m,n,word,index,i,j)) return true;
            }
        }
    }
    return false;
}
//time:O(m*n*4^k),space:O(k)