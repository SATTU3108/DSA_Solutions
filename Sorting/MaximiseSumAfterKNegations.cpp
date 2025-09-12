#include <bits/stdc++.h>
using namespace std;

/*
Given an array of size n and an integer k. We must modify array k number of times. In each modification, we can replace any array element arr[i] by -arr[i]. The task is to perform this operation in such a way that after k operations, the sum of the array is maximum.
*/

// Naive Approach -> Negating Minimum ELement k times
int maximiseSUM(vector<int> &arr,int k) {
    int n=arr.size();
    for (int i=0;i<k;i++) {
        int min_index=0;
        for (int j=1;j<n;j++) {
            if (arr[j]<arr[min_index]) min_index=j;
        }
        arr[min_index]=-arr[min_index];
    }
    int sum=0;
    for (int i=0;i<n;i++) sum+=arr[i];
    return sum;
}
//time:O(n*k),space:O(1)

// Sorting
int maximiseSum(vector<int> &arr,int k) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for (int i=0;i<n && k>0 && arr[i]<=0;i++) {
        arr[i]=-arr[i];
        k--;
    }
    k=k%2;
    int sum=0;
    for (int i=0;i<n;i++) sum+=arr[i];
    if (k==0) return sum;
    int min_index=0;
    for (int i=1;i<n;i++) {
        if (arr[i]<arr[min_index]) min_index=i;
    }
    return (sum-2*arr[min_index]);
}
