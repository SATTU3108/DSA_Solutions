#include <bits/stdc++.h>
using namespace std;

/*
You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.
*/

// Naive method -> Linear 

// Optimised method -> Binary Search
int firstOccurence(vector<int> &arr,int target) {
    int low=0,high=arr.size()-1;
    int first=-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]==target) {
            first=mid;
            high=mid-1;
        }
        else if (arr[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return first;
}
int lastOccurence(vector<int> &arr,int target) {
    int low=0,high=arr.size()-1;
    int last=-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]==target) {
            high=mid;
            low=mid+1;
        }
        else if (arr[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return last;
}
int count(vector<int> &arr,int target) {
    int first=firstOccurence(arr,target);
    int last=lastOccurence(arr,target);
    if (first==-1) return 0;
    return (last-first+1);
}