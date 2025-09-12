#include <bits/stdc++.h>
using namespace std;

/*
Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.
*/

// Naive Approach
int trap(vector<int> &arr) {
    int n=arr.size();
    int water_trapped=0;
    for (int i=0;i<n;i++) {
        int j=i;
        int leftMax=0;
        while (j>=0) {
            leftMax=max(leftMax,arr[j]);
            j--;
        }
        j=i;
        int rightMax=0;
        while (j<n) {
            rightMax=max(rightMax,arr[j]);
            j++;
        }
        water_trapped+=min(leftMax,rightMax)-arr[i];
    }
    return water_trapped;
}
//time:O(n^2),space:O(1)

// Better Approach
int trap(vector<int> &arr) {
    int n=arr.size();
    int prefix[n],suffix[n];
    prefix[0]=arr[0];
    for (int i=1;i<n;i++) prefix[i]=max(prefix[i-1],arr[i]);
    suffix[n-1]=arr[n-1];
    for (int i=n-2;i>=0;i--) suffix[i]=max(suffix[i+1],arr[i]);
    int water_trapped=0;
    for (int i=0;i<n;i++) water_trapped+=min(prefix[i],suffix[i])-arr[i];
    return water_trapped;
} 
//time:O(n),space:O(1)