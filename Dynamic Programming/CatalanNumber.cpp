#include <bits/stdc++.h>
using namespace std;

// Recursion
int findCatalan(int n) {
    if (n<=1) return 1;
    int res=0;
    for (int i=0;i<n;i++) res=+findCatalan(i)*findCatalan(n-i-1);
}
//time:O(2^n),space:O(n)

// Dynamic Programming
int findCatalan(int n) {
    int catalan[n+1];
    catalan[0]=catalan[1]=1;
    for (int i=2;i<=n;i++) {
        catalan[i]=0;
        for (int j=0;j<i;j++) catalan[i]+=catalan[j]*catalan[i-j-1];
    }
    return catalan[n];
}
//time:O(n^2),space:O(n)

// Binomial Coefficient
int nCr(int n,int r) {
    if (r>(n-r)) r=n-r;
    int res=1;
    for (int i=0;i<r;i++) {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int findCatalan(int n) {
    int intermediate=nCr(2*n,n);
    return intermediate/(n+1);
}
//time:O(n),space:O(1)

// Using (n-1)th catalan number
int findCatlan(int n) {
    int res=1;
    for (int i=2;i<=n;i++) {
        res=((res)*(4*i-2))/(i+1);
    }
    return res;
}
//time:O(n),space:O(n)



/*
This same question can be asked in multiple variations
1. Number of unique BST with n keys
2. Number of valid parathesis of length n
3. Number of ways of triangulation for a polygon
4. Number of full binary trees 
5. Number of ways to draw n chords in a circle with 2xn points such that not two intersect with each other
*/