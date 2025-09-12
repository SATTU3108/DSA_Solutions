#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array arr[] of size n, find the inversion count in the array. Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Note: Inversion Count for an array indicates that how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is maximum. 
*/

// Naive Approach -> 2 Nested Loops
int inversionCount(vector<int> &arr) {
    int n=arr.size();
    int inversionCount=0;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i]>arr[j]) inversionCount++;
        }
    }
    return inversionCount;
}
//time:O(n^2),space:O(1)

// Efficient Approach -> Merge Sort
int merge(vector<int> &arr,int low,int mid,int high) {
    vector<int> temp;
    int left=low,right=mid+1;
    int count=0;
    while (left<=mid && right<=high) {
        if (arr[left]<=arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(right);
            count+=(mid+1-left);
            right++;
        }
    } 
    while (left<=mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i=low;i<=high;i++) arr[i]=temp[i-low];
    return count;
}
int mergeSort(vector<int> &arr,int low,int high) {
    int count=0;
    if (low>=high) return count;
    int mid=low+(high-low)/2;
    count+=mergeSort(arr,low,mid);
    count+=mergeSort(arr,mid+1,high);
    count+=merge(arr,low,mid,high);
    return count;
}
int inversionCount(vector<int> &arr) {
    int n=arr.size();
    return mergeSort(arr,0,n-1);
}
//time:O(nlogn),space:O(n)