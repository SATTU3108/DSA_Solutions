#include <bits/stdc++.h>
using namespace std;

/*
Given a row-wise sorted matrix of size MXN, where M is no. of rows and N is no. of columns, find the median in the given matrix.
*/

// Brute-force -> store in array, sort it and return middle element
int median(vector<vector<int>> &matrix) {
    int m=matrix.size(),n=matrix[0].size();
    vector<int> list;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) list.push_back(matrix[i][j]);
    }
    sort(list.begin(),list.end());
    return list[(m*n)/2];
}
//time:O(m*n)+O(m*nlog(m*n)),space:O(m*n)

// Optimal Approach -> Binary Search
int upperBound(vector<int> &arr,int x,int n) {
    int low=0,high=n-1;
    int ans=n; // returns first index whose value is greater than mid
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]>x) {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int countSmallEqual(vector<vector<int>> &mat,int m,int n,int x) {
    int count=0;
    for (int i=0;i<m;i++) {
        count+=upperBound(mat[i],x,n);
    }
    return count;
}
int median(vector<vector<int>> &mat,int m,int n) {
    int low=INT_MAX,high=INT_MIN;
    for (int i=0;i<m;i++) {
        low=min(low,mat[i][0]);
        high=max(high,mat[i][n-1]);
    }
    int req=(n*m)/2;
    while (low<=high) {
        int mid=low+(high-low)/2;
        int small_equal=countSmallEqual(mat,m,n,mid);
        if (small_equal<=req) low=mid+1;
        else high=mid-1;
    }
    return low;
}
//time:O(nlogm*log(max-min)),space:O(1)