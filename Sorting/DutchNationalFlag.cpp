#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] consisting of only 0s, 1s, and 2s. The task is to sort the array, i.e., put all 0s first, then all 1s and all 2s in last.
*/

// Naive Approach -> Sorting

// Better Approach -> Counting 0,1,2
void sort012(vector<int> &arr) {
    int n=arr.size();
    int c0=0,c1=0,c2=0;
    for (int i=0;i<n;i++) {
        if (arr[i]==0) c0++;
        else if (arr[i]==1) c1++;
        else c2++;
    }
    int idx=0;
    for (int i=0;i<c0;i++) arr[idx++]=0;
    for (int i=0;i<c1;i++) arr[idx++]=1;
    for (int i=0;i<c2;i++) arr[idx++]=2;
}
//time:O(n),space:O(1) -> requires 2 traversals

void sort012(vector<int> &arr) {
    int n=arr.size();
    int lo=0,mid=0,high=n-1;
    while (mid<=high) {
        if (arr[mid]==0) {
            swap(arr[lo],arr[mid]);
            lo++;
            mid++;
        }
        else if (arr[mid]==1) mid++;
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
//time:O(n),space:O(1) -> requires 1 traversal