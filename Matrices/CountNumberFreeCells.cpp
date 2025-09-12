#include <bits/stdc++.h>
using namespace std;

/*
Suppose you have a Matrix size n*n, and given an integer k and a set of coordinates arr of size k*2. Initially, the matrix contains only 0. You are given k tasks and for each task, you are given two coordinates (r = arr[i][0],c = arr[i][1]) [1 based index r and c]. Where coordinates (r,c) denotes rth row and cth column of the given matrix.

You have to perform each task sequentially in the given order. For each task, You have to put 1 in all cells of rth row  and all cells of cth column.

After each task, You have to calculate the number of 0 present in the matrix and return it.
*/

vector<long long int> countZero(int n, int k, vector<vector<int>>& arr) {
    unordered_set<int> rowsMarked,colsMarked;
    vector<long long> result;
    for (int i=0;i<k;i++) {
        int r=arr[i][0],c=arr[i][1];
        rowsMarked.insert(r);
        colsMarked.insert(c);
        long long ones=(long long)rowsMarked.size()*n+(long long)colsMarked.size()*n-(long long)rowsMarked.size()*colsMarked.size();
        result.push_back((long long)n*n-ones);
    }
    return result;
}
//time:O(k),space:O(n+n+k)