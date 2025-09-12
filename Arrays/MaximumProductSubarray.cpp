#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] consisting of positive, negative, and zero values, find the maximum product that can be obtained from any contiguous subarray of arr[].
*/

// Approach 1 -> Brute-force
int maxProduct(vector<int> &arr) {
    int n=arr.size();
    int maxProd=arr[0];
    for (int i=0;i<n;i++) {
        int mul=1;
        for (int j=i;j<n;j++) {
            mul*=arr[j];
            maxProd=max(maxProd,mul);
        }
    }
    return maxProd;
}
//time:O(n^2),space:O(1)

// Approach 2 -> Similar to Kadane algo.
int maxProduct(vector<int> &arr) {
    int n=arr.size();
    int currMax=arr[0],currMin=arr[0],maxProd=arr[0];
    for (int i=1;i<n;i++) {
        int temp=max({arr[i],arr[i]*currMax,arr[i]*currMin});
        currMin=min({arr[i],arr[i]*currMax,arr[i]*currMin});
        currMax=temp;
        maxProd=max(maxProd,currMax);
    }
    return maxProd;
}
//time:O(n),space:O(1)

// Approach 3
int maxProduct(vector<int> &arr) {
    int n=arr.size();
    int maxProd=INT_MIN;
    int leftToRight=1,rightToLeft=1;
    for (int i=0;i<n;i++) {
        if (leftToRight==0) leftToRight=1;
        if (rightToLeft=0) rightToLeft=1;
        leftToRight*=arr[i];
        rightToLeft*=arr[n-i-1];
        maxProd=max({leftToRight,rightToLeft,maxProd});
    }
    return maxProd;
}
//time:O(n),space:O(1)