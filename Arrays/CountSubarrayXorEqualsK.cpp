#include <bits/stdc++.h>
using namespace std;

/*
Given an array. Find total no. of subarrays whose xor=K
*/

// Naive Method
int subarraysWIthXorK(vector<int> &a,int k) {
    int n=a.size();
    int count=0;
    // 1. generate subarrays
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            // calculate xor of all elements
            int xor_result=0;
            for (int x=i;x<=j;x++) xor_result=xor_result^a[x];
            // 3. check xr and count
            if (xor_result==k) count++;
        }
    }
    return count;
}
//time:O(n^3),space:O(1)

// Better Approach -> just a little optimisation over naive appraoch
int subarraysWithXorK(vector<int> &a,int k) {
    int n=a.size();
    int count=0;
    for (int i=0;i<n;i++) {
        int xor_result=0;
        for (int j=i;j<n;j++) {
            xor_result^=a[j];
            if (xor_result==k) count++;
        }
    }
    return count;
}
//time:O(n^2),space:O(1)

// Optimal Approach -> Prefix XOR
int subarraysWithXorK(vector<int> &a,int k) {
    int n=a.size();
    int xr=0;
    map<int,int> mp;
    mp[xr]++;
    int count=0;
    for (int i=0;i<n;i++) {
        xr^=a[i];
        int x=xr^k;
        count+=mp[x];
        mp[xr]++;
    }
    return count;
}
//time:O(nlogn),space:O(n)