#include <bits/stdc++.h>
using namespace std;

/*
Given an array, find an element before which all elements are equal or smaller than it, and after which all the elements are equal or greater.

Note: Print -1, if no such element exists.
*/

// Naive approach
int findElement(vector<int> &arr) {
    for (int i=1;i<arr.size()-1;i++) {
        int left=INT_MIN;
        for (int j=0;j<i;j++) {
            if (left>arr[j]) left=arr[j];
        }
        int right=INT_MAX;
        for (int j=i+1;j<arr.size();j++) {
            if (right<arr[j]) right=arr[j];
        }
        if (arr[i]>=left && arr[i]<=right) return arr[i];
    }
    return -1;
}
// Time complexity:O(N^2),Space complexity:O(1)

// Efficient Approach (Prefix and Suffix Arrays)
int findElement(vector<int> &arr) {
    int n=arr.size();
    vector<int> leftMax(n);
    leftMax[0]=arr[0];
    for (int i=1;i<n;i++) leftMax[i]=max(leftMax[i-1],arr[i]);
    vector <int> rightMin(n);
    rightMin[n-1]=arr[n-1];
    for (int i=n-2;i>=0;i--) rightMin[i]=min(rightMin[i+1],arr[i]);
    for (int i=1;i<n-1;i++) {
        if (arr[i]>=leftMax[i-1] && arr[i]<=rightMin[i]) return arr[i];
    }
    return -1;
}
// Time complexity:O(N),Space complexity:O(N)
