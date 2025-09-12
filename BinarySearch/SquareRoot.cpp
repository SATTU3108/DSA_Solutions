#include <bits/stdc++.h>
using namespace std;

/*

You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

Note: The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n.
*/

// Brute-force approach
int floorSqrt(int n) {
    int ans=0;
    for (long long i=1;i<=n;i++) {
        long long val=i*i;
        if (val<=n*1ll) ans=i;
        else break;
    }
    return ans;
}
//time:O(n),space:O(1)

// Optimal Approach 1-> sqrt function
int floorSqrt(int n) {
    int low=1,high=n;
    int ans;
    while (low<=high) {
        long long mid=low+(high-low)/2;
        long long val=mid*mid;
        if (val==(long long)(n)) {
            ans=mid;
            break;
        }
        else if (mid*mid<(long long)(n)) {
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}