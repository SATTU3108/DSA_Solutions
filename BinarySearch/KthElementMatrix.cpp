#include <bits/stdc++.h>
using namespace std;

/*
Given an n x n matrix, every row and column is sorted in non-decreasing order. Given a number K where K lies in the range [1, n*n], find the Kth smallest element in the given 2D matrix.
*/

// Sorting
int kthSmallest(vector<vector<int>> &matrix,int k) {
    int n=matrix.size();
    vector<int> arr;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            arr.push_back(matrix[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    return arr[k-1];
}
//time:O(n^2log(n^2)),space:O(n^2)

// Priority Queue
int kthSmallest(vector<vector<int>> &matrix,int k) {
    int n=matrix.size();
    priority_queue<int> pq;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            int curr=matrix[i][j];
            pq.push(curr);
            if (pq.size()>k) pq.pop();
        }
    }
    return pq.top();
}
//time:O(n^2logk),space:O(k)

// Binary Search
int countSmallerEqual(vector<vector<int>> &matrix,int x) {
    int n=matrix.size();
    int row=0,col=n-1;
    int count=0;
    while (row<n && col>=0) {
        if (matrix[row][col]<=x) {
            count+=(col+1);
            row++;
        }
        else col--;
    }
    return count;
}
int kthSmallest(vector<vector<int>> &matrix,int k) {
    int n=matrix.size();
    int low=matrix[0][0],high=matrix[n-1][n-1];
    int ans=0;
    while (low<=high) {
        int mid=low+(high-low)/2;
        int count=countSmallerEqual(matrix,mid);
        if (count<k) low=mid+1;
        else {
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}
//time:O(n*log(max-min)),space:O(1)