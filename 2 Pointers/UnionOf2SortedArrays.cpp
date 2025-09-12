#include <bits/stdc++.h>
using namespace std;

/*
Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.
*/

// Naive Approach -> Using sets or maps - O((m+n)log(m+n))

// Efficient Approach -> 2 Pointers
vector<int> findUnion(vector<int> arr1,vector<int> arr2) {
    int n=arr1.size(),m=arr2.size();
    vector<int> Union;
    int i=0,j=0;
    while (i<n && j<m) {
        if (arr1[i]<=arr2[j]) {
            if (Union.size()==0 || Union.back()!=arr1[i]) Union.push_back(arr1[i]);
            i++;
        }
        else {
            if (Union.size()==0 || Union.back()!=arr2[j]) Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i<n) {
        if (Union.back()!=arr1[i]) Union.push_back(arr1[i]);
        i++;
    }
    while (j<n) {
        if (Union.back()!=arr2[j]) Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}
//time:O(m+n),space:O(m+n) to represent the union array