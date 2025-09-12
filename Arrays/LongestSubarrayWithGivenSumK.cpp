#include <bits/stdc++.h>
using namespace std;

/*
Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
*/

// Naive Approach
int getLongestSubarray(vector<int> &a,long long k) {
    int n=a.size();
    int len=0;
    for (int i=0;i<n;i++) {
        long long s=0;
        for (int j=i;j<n;j++) {
            s+=a[j];
            if (s==k) len=max(len,j-i+1);
        }
    }
    return len;
}
//time:O(n^2),space:O(1)

// Better Approach -> Hashing
int getLongestSubarray(vector<int> &a,long long k) {
    int n=a.size();
    map<long long,int> prefix_sum;
    long long sum=0;
    int max_len=0;
    for (int i=0;i<n;i++) {
        sum+=a[i];
        if (sum==k) max_len=max(max_len,i+1);
        long long rem=sum-k;
        if (prefix_sum.find(rem)!=prefix_sum.end()) {
            int len=i-prefix_sum[rem];
            max_len=max(max_len,len);
        }
        if (prefix_sum.find(sum)==prefix_sum.end()) prefix_sum[sum]=i; // we add only the first occured element, since we want the longest subarray
    }
    return max_len;
}
//time:O(nlogn),space:O(n)

//Optimal Approach -> 2 Pointer (cant be used when array might contain negatives as well)
int getLongestSubarray(vector<int> &a,long long k) {
    int n=a.size();
    int left=0,right=0;
    long long sum=a[0];
    int max_len=0;
    while (right<n) {
        while (left<=right && sum>k) {
            sum-=a[left];
            left++;
        }
        if (sum==k) max_len=max(max_len,right-left+1);
        right++;
        if (right<n) sum+=a[right];
    }
    return max_len;
}
//time:O(n),space:O(1)