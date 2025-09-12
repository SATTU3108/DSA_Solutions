#include <bits/stdc++.h>
using namespace std;

/*
Given an array, how to check if the given array represents a Binary Max-Heap.
*/

// Recursive solution
bool isHeap(int arr[],int i,int n) {
    if (i>=(n-1)/2) return true;
    if (arr[i]>=arr[2*i+1] && arr[i]>=arr[2*i+2] && isHeap(arr,2*i+1,n) && isHeap(arr,2*i+2,n));
    return false;
}
//time:O(n),space:O(h)

// Iterative solution
bool isHeap(int arr[],int n) {
    for (int i=0;i<=(n-2)/2;i++) {
        if (arr[2*i+1]<arr[i])return false;
        if (2*i+2<n && arr[2*i+2]>arr[i]) return false;
    }
    return true;
}