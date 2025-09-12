#include <bits/stdc++.h>
using namespace std;

/*
You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order.
But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
*/

// Brute-force approach
bool searchElement(vector<vector<int>> &matrix,int target) {
    int n=matrix.size(),m=matrix[0].size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (matrix[i][j]==target) return true;
        }
    }
    return false;
}
//tiime:O(n*m),space:O(1)

// Better Approach -> BS row-wise
bool binarySearch(vector<int> &nums,int target) {
    int n=nums.size();
    int low=0,high=n-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (nums[mid]==target) return true;
        if (nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return false;
}
bool searchElement(vector<vector<int>> &matrix,int target) {
    int n=matrix.size();
    for (int i=0;i<n;i++) {
        bool flag=binarySearch(matrix[i],target);
        if (flag==true) return true;
    }
    return false;
}
//time:O(nlogm),space:O(1)

// Optimal Approach -> BS 
bool searchElement(vector<vector<int>> &matrix,int target) {
    int n=matrix.size(),m=matrix[0].size();
    int row=0,col=m-1;
    while (row<n && col>=0) {
        if (matrix[row][col]==target) return true;
        else if (matrix[row][col]>target)  col--;
        else row++;
    }
    return false;
}
//time:O(n+m),space:O(1)

/*
However, if it was ensured that first element of a row is always greater than the last element of the previos row, then observe that even on flattening the 2d matrix, it will be a sorted array. So, we can use the concept of flattening the 2D matrix and converting that into array. However, it will be n*m operation. But if we could somehow get only the index where the current element would fit into the flattened array, then our task will be completed
*/
// Approach in case of this:
bool searchMatrix(vector<vector<int>> &matrix,int target) {
    int n=matrix.size(),m=matrix[0].size();
    int low=0,high=n*m-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        int row=mid/m,col=mid%m;
        if (matrix[row][col]==target) return true;
        else if (matrix[row][col]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}
//time:O(log(n*m)),space:O(1)