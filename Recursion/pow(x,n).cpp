#include <bits/stdc++.h>
using namespace std;

/*
Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).
*/

// Naive Method
double myPow(double x,int n) {
    double ans=1.0;
    for (int i=0;i<n;i++) ans*=x;
    return ans;
}
//time:O(n),space:O(1)

// Efficient Recursive Approach
double myPow(double x,int n) {
    if (n==0) return 1.0;
    long long nn=n;
    if (nn<0) {
        nn=-nn;
        x=1/x;
    }
    return power(x,nn);
}
double power(double x,long long n) {
    if (n==0) return 1.0;
    double half=power(x,n/2);
    if (n%2==0) return half*half;
    else return half*half*x;
}
//time:O(logn),space:O(logn)

// Efficient Iterative Approach
double myPower(double x,int n) {
    double ans=1.0;
    long long nn=n;
    if (nn<0) nn=-nn;
    while (nn!=0) {
        if (nn%2==1) {
            ans=ans*x;
            nn=nn-1;
        }
        else {
            x=x*x;
            nn=nn/2;
        }
    }
    if (n<0) return (double)1.0/(double)ans;
    return ans;
}
//time:O(logn),space:O(1)