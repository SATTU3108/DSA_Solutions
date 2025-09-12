#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array of arr. Find the first element in an array such that all of its left elements are smaller and all right elements of its are greater than it.

Note: Return -1 if there is no such element.
*/

int findElement(vector<int> &arr) {
    int n=arr.size();
    vector<int> prefix(n),suffix(n);
    prefix[0]=arr[0],suffix[n-1]=arr[n-1];
    for (int i=1;i<n;i++) {
        prefix[i]=max(prefix[i-1],arr[i]);
    }
    for (int i=n-2;i>=0;i--) {
        suffix[i]=min(suffix[i+1],arr[i]);
    }
    for (int i=2;i<n-1;i++) {
        if (arr[i]>prefix[i-1] && arr[i]<suffix[i+1]) return arr[i];
    }
    return -1;
}