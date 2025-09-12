#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array of integers, sort the array into a wave array. An array arr[0..n-1] is sorted in wave form if: arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= .....
*/

// Naive Approach -> Sorting
void sortInWave(vector<int> &arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for (int i=0;i<n-1;i+=2) swap(arr[i],arr[i+1]);
}
//time:O(nlogn),space:O(1)

// Optimal Approach 
void sortInWave(vector<int> &arr) {
    int n=arr.size();
    for (int i=0;i<n;i+=2) {
        if (i>0 && arr[i]<arr[i-1]) swap(arr[i],arr[i-1]);
        if (i<n-1 && arr[i]<arr[i+1]) swap(arr[i],arr[i+1]);
    }
}
//time:O(n),space:O(1)