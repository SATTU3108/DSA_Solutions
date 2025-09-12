#include <bits/stdc++.h>
using namespace std;

/*
You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.
*/

// Naive Approach
bool possible(vector<int> &arr,int day,int m,int k) {
    int n=arr.size();
    int count=0,bouquets=0;
    for (int i=0;i<n;i++) {
        if (arr[i]<=day) count++;
        else {
            bouquets+=(count/k);
            count=0;
        }
    }
    bouquets+=(count/k);
    return (bouquets>=m);
}
int roseGarden(vector<int> &arr,int k,int m) {
    int n=arr.size();
    long long val=m*1ll*k*1ll;
    if (val>n) return -1;
    int mini=INT_MAX,maxi=INT_MIN;
    for (int i=0;i<n;i++) {
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }
    for (int i=mini;i<=maxi;i++) {
        if (possible(arr,i,m,k)) return i;
    }
    return -1;
}
//time:O((max-min)*n),space:O(1)

// Binary Search Approach
bool possible(vector<int> &arr,int day,int m,int k) {
    int n=arr.size();
    int count=0,bouquets=0;
    for (int i=0;i<n;i++) {
        if (arr[i]<=day) count++;
        else {
            bouquets+=(count/k);
            count=0;
        }
    }
    bouquets+=(count/k);
    return (bouquets>=m);
}
int roseGarden(vector<int> &arr,int k,int m) {
    int n=arr.size();
    long long val=m*1ll*k*1ll;
    if (val>n) return -1;
    int mini=INT_MAX,maxi=INT_MIN;
    for (int i=0;i<n;i++) {
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }
    int low=mini,high=maxi;
    int ans;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (possible(arr,mid,m,k)) {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return -1;
}