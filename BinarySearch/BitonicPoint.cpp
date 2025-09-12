#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of integers which is initially strictly increasing and then strictly decreasing, the task is to find the bitonic point, that is the maximum value in the array. 

Note: Bitonic Point is a point in bitonic sequence before which elements are strictly increasing and after which elements are strictly decreasing.
*/

// Naive Approach: Linear Search
int findMaximum(vector <int> &arr) {
    int n=arr.size();
    int max_element=arr[0];
    for (int i=1;i<n;i++) {
        if (arr[i]>max_element) max_element=arr[i];
    }
    return max_element;
}

// Optimal Approach: Binary Search
int findMaximum(vector<int> &arr) {
    int n=arr.size();
    if (n==1 || arr[0]>arr[1]) return arr[0];
    if (arr[n-1]>arr[n-2]) return arr[n-1];
    int low=1,high=n-2;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return arr[mid];
        else if (arr[mid]<arr[mid+1]) low=mid+1;
        else high=mid-1;
    }
    return arr[high];
} 

// this question is very similar to peak element