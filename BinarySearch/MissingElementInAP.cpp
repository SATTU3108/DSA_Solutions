#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array arr[] that represents an Arithmetic Progression (AP) with exactly one missing element, find the missing number.
The array arr[] is sorted in either ascending or descending order.

Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression. If the given sequence already forms a valid complete AP, return the (n+1)-th element that would come next in the sequence.
*/

int findMissing(vector<int>& arr) {
    int n=arr.size();
    // 1. Determine if AP is increasing or decreasing
    int sign=(arr[1]>arr[0]) ? 1:-1;
    // 2. Compute correct diff using abs differences
    int diff=INT_MAX;
    for (int i=1;i<n;i++) diff=min(diff,abs(arr[i]-arr[i-1]));
    diff*=sign;  // Apply correct sign to diff
    // 3. Apply BS to find missing element
    int low=0,high=n-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        int expected=arr[0]+mid*diff;
        if (arr[mid]==expected) low=mid+1; // if it is not distorted till mid, then there is no missing number before the mid element
        else high=mid-1;
    }
    return arr[0]+low *diff;
}