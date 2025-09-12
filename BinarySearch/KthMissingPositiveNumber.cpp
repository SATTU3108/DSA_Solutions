#include <bits/stdc++.h>
using namespace std;

/*
You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.
*/

// Brute-force approach -> hash set
int kthMissing(vector<int> &arr,int k) {
    unordered_set<int> st(arr.begin(),arr.end());
    int count=0,curr=0;
    while (count<k) {
        curr++;
        if (st.find(curr)==st.end()) count++;
    }
    return curr;
}
//time:O(n+k),space:O(n)

// Better Approach -> index comparision
int kthMissing(vector<int> &arr,int k) {
    int n=arr.size();
    for (int i=0;i<n;i++) {
        if (arr[i]>(k+i)) return k+i;
    }
    return k+n;
}
//time:O(n),space:O(1)

// Optimal Approach -> binary search
int kthMissing(vector<int> &arr,int k) {
    int low=0,high=arr.size()-1;
    int res=arr.size()+k;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]>mid+k) {
            res=mid+k;
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}
//time:O(logn),space:O(1)