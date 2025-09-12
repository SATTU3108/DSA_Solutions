#include <bits/stdc++.h>
using namespace std;

/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
*/

// Naive Approach -> use extra space
void merge(long long arr1[],long long arr2[],int n,int m) {
    long long arr3[n+m];
    int left=0,right=0;
    int index=0;
    while (left<n && right<m) {
        if (arr1[left]<=arr2[right]) {
            arr3[index]==arr1[left];
            left++;
            index++;
        }
        else {
            arr3[index]=arr2[right];
            right++;
            index++;
        }
    }
    while (left<n) {
        arr3[index]=arr1[left];
        left++;
        index++;
    }
    while (right<m) {
        arr3[index]=arr2[right];
        right++;
        index++;
    }
    for (int i=0;i<n;i++) {
        if (i<n) arr1[i]=arr3[i];
        else arr2[i-n]=arr3[i];
    }
}

// Optimal Approach 1
void merge(long long arr1[],long long arr2[],int n,int m) {
    int left=n-1,right=0;
    // swap the elements until arr[left] is smaller that arr2[right]
    while (left>=0 && right<m) {
        if (arr1[left]>arr2[right]) {
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
        else break;
    }
    // sort arr1 and arr2 individually
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}
//time:O(min(n,m))+O(nlogn)+O(mlogm),space:O(1)

// Optimal Approach 2
void swapIfGreater(long long arr1[],long long arr2[],int ind1,int ind2) {
    if (arr1[ind1]>arr2[ind2]) swap(arr1[ind1],arr2[ind2]);
}
void merge(long long arr1[],long long arr2[],int n,int m) {
    int len=n+m;
    int gap=(len/2)+(len%2);
    while (gap>0) {
        int left=0,right=left+gap;
        while (right<len) {
            // case1: left in arr1[] & right in arr2[]
            if (left<n && right>=n) swapIfGreater(arr1,arr2,left,right-n);
            // case2: both pointers in arr2[]
            else if (left>=n) swapIfGreater(arr2,arr2,left-n,right-n);
            // case3: both pointers in arr1[]
            else swapIfGreater(arr1,arr1,left,right);
            left++;
            right++;
        }
        // break if iteration gap is completed
        if (gap==1) break;
        // otherwise, calcualte new gap
        gap=(gap/2)+(gap%2);
        
    }
}
//time:O(n+m*log(n+m)),space:O(1)