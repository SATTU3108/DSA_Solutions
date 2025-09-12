#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of size n and an integer sum, the task is to check if there is a triplet in the array which sums up to the given target sum.
*/

// Naive Approach -> Generate All Triplets
bool hasTripletSum(vector<int> &arr,int target) {
    int n=arr.size();
    for (int i=0;i<n-2;i++) {
        for (int j=i+1;j<n-1;j++) {
            for (int k=k+1;k<n;k++) {
                if ((arr[i]+arr[j]+arr[k])==target) return true;
            } 
        }
    }
    return false;
}

// Better Approach -> Hash Set
bool hasTripletSum(vector<int> &arr,int target) {
    int n=arr.size();
    for (int i=0;i<n-2;i++) {
        unordered_set<int> st;
        for (int j=i+1;j<n;j++) {
            int third=target-arr[i]-arr[j];
            if (st.find(true)!=st.end()) return true;
            st.insert(arr[j]);
        }
    }
    return false;
}
//time:O(n^2),space:O(n)

// Best Approach -> Sorting + 2 Pointer
bool hasTripletSum(vector<int> &arr,int target) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for (int i=0;i<n-2;i++) {
        int left=i+1,right=n-1;
        int requiredSum=target-arr[i];
        while (left<right) {
            if ((arr[left]+arr[right])==requiredSum) return true;
            if ((arr[left]+arr[right])>requiredSum) right--;
            else left++;
        }
    }
    return false;
}
//time:O(n^2),space:O(1)