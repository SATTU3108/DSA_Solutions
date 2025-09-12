#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array arr[] and an integer x, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x. This element is called the ceil of x. If such an element does not exist, return -1.

Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.
*/

int findCeil(vector<int>& arr, int x) {
    int n=arr.size();
    int low=0,high=n-1;
    int ans=-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]<x) low=mid+1;
        else {
            ans=mid;
            high=mid-1;
        }
    }
    if (ans==INT_MAX) return -1;
    else return ans;
}

/*
Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] that is less than or equal to x. This element is called the floor of x. If such an element does not exist, return -1.

Note: In case of multiple occurrences of ceil of x, return the index of the last occurrence.
*/

int findFloor(vector<int>& arr, int x) {
    int n=arr.size();
    int low=0,high=n-1;
    int ans=-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]>x) high=mid-1;
        else {
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}