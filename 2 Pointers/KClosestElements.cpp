#include <bits/stdc++.h>
using namespace std;

/*
You are given a sorted array arr[] containing unique integers, a number k, and a target value x. Your goal is to return exactly k elements from the array that are closest to x, excluding x itself if it is present in the array.

An element a is closer to x than b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a > b (i.e., prefer the larger element if tied)
*/

// Naive Approach -> Custom operator
vector<int> printKClosest(vector<int> &arr,int k,int x) {
    sort(arr.begin(),arr.end(),[x] (int a,int b) {
        int diff_a=abs(a-x);
        int diff_b=abs(b-x);
        if (diff_a==diff_b) return a>b;
        return (diff_a<diff_b);
    });
    vector<int> result;
    int count=0;
    for (int num:arr) {
        if (num==x) continue;
        result.push_back(num);
        count++;
        if (count==k) break;
    }
    return result;
}
//time:O(nlogn),space:O(k)

// Better Approach -> Linear Search
vector<int> printKClosest(vector<int> &arr,int k,int x) {
    int n=arr.size();
    int i=0;
    while (i<n && arr[i]<x) i++;
    int left=i-1,right=i;
    if (arr[right]==x) right++;
    vector<int> res;
    while (left>=0 && right<n && res.size()<k) {
        int left_diff=abs(arr[left]-x);
        int right_diff=abs(arr[right]-x);
        if (left_diff<right_diff) {
            res.push_back(arr[left]);
            left--;
        }
        else {
            res.push_back(arr[right]);
            right++;
        }
    }
    while (left>=0 && res.size()<k) {
        res.push_back(arr[left]);
        left--;
    }
    while (right<n && res.size()<k) {
        res.push_back(arr[right]);
        right++;
    }
    return res;
}
//time:O(n),space:O(k)

// Binary Search
vector<int> printKClosest(vector<int> &arr,int k,int x) {
    int n=arr.size();
    int i=0;
    int low=0,high=n-1,pos=-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]<x) {
            pos=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    int left=pos,right=pos+1;
    if (arr[right]==x) right++;
    vector<int> res;
    while (left>=0 && right<n && res.size()<k) {
        int left_diff=abs(arr[left]-x);
        int right_diff=abs(arr[right]-x);
        if (left_diff<right_diff) {
            res.push_back(arr[left]);
            left--;
        }
        else {
            res.push_back(arr[right]);
            right++;
        }
    }
    while (left>=0 && res.size()<k) {
        res.push_back(arr[left]);
        left--;
    }
    while (right<n && res.size()<k) {
        res.push_back(arr[right]);
        right++;
    }
    return res;
}