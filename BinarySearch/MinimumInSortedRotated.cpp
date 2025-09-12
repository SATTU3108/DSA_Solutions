#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 
*/

int findMIn(vector<int> &arr) {
    int low=0,high=arr.size()-1;
    int ans=INT_MAX;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[low]<=arr[high]) {
            ans=min(ans,arr[low]);
            break;
        }
        if (arr[low]<=arr[mid]) {
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else {
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
    }
    return ans;
}
// Time complexity:O(logN),Space complexity:O(1)