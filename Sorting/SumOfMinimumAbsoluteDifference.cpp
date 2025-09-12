#include <bits/stdc++.h>
using namespace std;

/*
Given an array of n distinct integers. The task is to find the sum of minimum absolute difference of each array element. For an element arr[i] present at index i in the array, its minimum absolute difference is calculated as: 

Min absolute difference (arr[i]) = min(abs(arr[i] - arr[j])), where 0 <= j < n and j != i and abs is the absolute value. 
*/

// Naive Approach -> 2 nested loops
int minSumDiff(vector<int> &arr) {
    int n=arr.size();
    int sum=0;
    for (int i=0;i<n;i++) {
        int min_diff=INT_MAX;
        for (int j=0;j<n;j++) {
            if (j!=i) min_diff=min(min_diff,abs(arr[i]-arr[j]));
        }
        sum+=min_diff;
    }
    return sum;
}
//time:O(n^2),space:O(1)

// Efficient Approach
int minSumDiff(vector<int> &arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int sum=0;
    sum+=(arr[1]-arr[0]);
    sum+=(arr[n-1]-arr[n-2]);
    for (int i=1;i<(n-1);i++) {
        int left_diff=arr[i]-arr[i-1];
        int right_diff=arr[i+1]-arr[i];
        sum+=min(left_diff,right_diff);
    }
    return sum;
}
//time:O(nlogn),space:O(1)