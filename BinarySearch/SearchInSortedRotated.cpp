#include <bits/stdc++.h>
using namespace std;

// Naive Approach -> Linear Search

// Expected Approach 1 (Binary Search twice)
int binarySearch(vector<int> &arr,int low,int high,int target) {
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]==target) return mid;
        if (arr[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int findMinIndex(vector<int> &arr,int low,int high) {
    int low=0,high=arr.size()-1;
    int minValue=INT_MAX,minIndex=high-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        // Array is alreay sorted fully
        if (arr[low]<=arr[high]) {
            if (arr[low]<minValue) {
                minValue=arr[low];
                minIndex=low;
            }
            break;
        }
        // Left half is sorted
        if (arr[low]<=arr[mid]) {
            if (arr[low]<minValue) {
                minValue=arr[low];
                minIndex=low;
            }
            low=mid+1;
        }
        // Right half is sorted
        else {
            if (arr[mid]<minValue) {
                minValue=arr[mid];
                minIndex=mid;
            }
            high=mid-1;
        }
    } 
    return minIndex;
}
int search(vector<int> &arr,int key) {
    int n=arr.size();
    int pivot=findMinIndex(arr,0,n-1);
    if (arr[pivot]==key) return pivot;
    if (pivot==0) return binarySearch(arr,0,n-1,key);
    if (arr[0]<=key) return binarySearch(arr,0,pivot-1,key);
    return binarySearch(arr,pivot+1,n-1,key);
}
// Time complexity:O(NlogN), but two traversals

// Expected Approach 2 (Single Binary Search) 
int search(vector<int> &arr,int target) {
    int low=0,high=arr.size()-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]==target) return mid;
        // if there are duplicates in the code, then this commented code needs to be there
        /*
        if (arr[low]==arr[mid] && arr[mid]==arr[high]) {
        low++;
        high--;
        continue;
        }
        */
        if (arr[mid]>=arr[low]) {
            if (target>=arr[low] && target<arr[mid]) high=mid-1;
            else low=mid+1;
        }
        else {
            if (target>arr[mid] && target<=arr[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}
