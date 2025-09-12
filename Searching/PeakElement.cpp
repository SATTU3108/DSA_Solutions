#include <bits/stdc++.h>
using namespace std;

/*
Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.
*/

int findPeakElement(vector<int> &arr) {
    int n=arr.size();
    if (n==1) return 0;
    if (arr[0]>arr[1]) return 0;
    if (arr[n-1]>arr[n-2]) return (n-1);
    int low=1,high=n-2;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        if (arr[mid]>arr[mid-1]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
// Time complexity:O(logN),Space complexity:O(1)