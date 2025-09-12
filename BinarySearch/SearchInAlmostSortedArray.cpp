#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted integer array arr[] consisting of distinct elements, where some elements of the array are moved to either of the adjacent positions, i.e. arr[i] may be present at arr[i-1] or arr[i+1].
Given an integer target.  You have to return the index ( 0-based ) of the target in the array. If target is not present return -1.
*/

// Naive approach -> Linear Search

// Optimised Approach -> Binary Search
int findTarget(vector <int> &arr, int target) {
    int left=0,right=arr.size()-1;
    while (left<=right) {
        int mid=left+(right-left)/2;
        if (arr[mid]==target) return mid;
        if (mid>left && arr[mid-1]==target) return mid-1;
        if (mid<right && arr[mid+1]==target) return mid+1;
        if (arr[mid]>target) right=mid-2;
        else left=mid+2;
    }
    return -1;
}