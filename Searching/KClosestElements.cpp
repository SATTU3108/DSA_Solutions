#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array arr[] and a value x, find the k closest elements to x in arr[]. Note that if the element is present in array, then it should not be in output, only the other closest elements are required.
*/

// Method 1 -> Linear Search

// Method 2 -> Binary Search
int findCrossover(vector<int>& arr, int x) {
    int low=0,high=arr.size()-1;
    if (x<arr[0]) return 0;
    if (x>=arr[high]) return high;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]<=x && arr[mid+1]>x) return mid;
        if (arr[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
    int l=findCrossover(arr,x);
    int r=l+1;
    if (l >= 0 && arr[l] == x) l--;
    vector<int> ans;
    int count = 0;
    while (l >= 0 && r<n && count<k) {
        int diffL=abs(arr[l]-x);
        int diffR=abs(arr[r]-x);
        if (diffL < diffR) ans.push_back(arr[l--]);
        else if (diffR < diffL) ans.push_back(arr[r++]);
        else ans.push_back(arr[r++]);
        count++;
    }
    while (count<k && l>=0) {
        ans.push_back(arr[l--]);
        count++;
    }
    while (count<k && r<n) {
        ans.push_back(arr[r++]);
        count++;
    }
    return ans;
}
// Time complexity:O(logN+K), Space complexity:O(K)