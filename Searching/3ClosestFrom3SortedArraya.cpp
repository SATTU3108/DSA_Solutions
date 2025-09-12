#include <bits/stdc++.h>
using namespace std;

/*
Given three sorted arrays A[], B[] and C[], find 3 elements i, j and k from A, B and C respectively such that max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized. Here abs() indicates absolute value.
*/

// Naive method
vector<int> findClosest(vector<int> A,vector<int> B,vector<int> C) {
    int p=A.size(),q=B.size(),r=C.size();
    int a,b,c,ans=INT_MAX;
    for (int i=0;i<p;i++) {
        for (int j=0;j<q;j++) {
            for (int k=0;k<r;k++) {
                int curr=max({abs(A[i]-B[j]),abs(B[j]-C[k]),abs(C[k]-A[i])});
                if (curr<ans) {
                    ans=curr;
                    a=A[i],b=B[j],c=C[k];
                }
            }
        }
    }
    return {a,b,c};
}
// Time complexity:O(p*q*r),Aux. Space:O(1)

vector<int> findClosest(vector<int> A,vector<int> B,vector<int> C) {
    int p=A.size(),q=B.size(),r=C.size();
    int diff=INT_MAX;
    int res_i=0,res_j=0,res_k=0;
    int i=0,j=0,k=0;
    while (i<p && j<q && k<r) {
        int minimum=min({A[i],B[j],C[k]});
        int maximum=max({A[i],B[j],C[k]});
        if ((maximum-minimum)<diff) {
            res_i=i,res_j=j,res_k=k;
            diff=maximum-minimum;
        }
        if (diff==0) break;
        if (A[i]==minimum) i++;
        else if (B[j]==minimum) j++;
        else k++;
    }
    return {res_i,res_j,res_k};
}
// Time complexity:O(p+q+r),Space complexity:O(1)