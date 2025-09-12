#include <bits/stdc++.h>
using namespace std;

/*
Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).
*/

// Brute-force -> generate all permutations, store them and then returen the next permutaion

// Solution 1 -> inbuilt function (next_permutation(arr.begin(),arr.end()))

// Solution 2 -> concept of break point

vector<int> nextGreaterPermutation(vector<int> &a) {
    int n=a.size();
    // 1. Find break point 
    int ind=-1;
    for (int i=n-2;i>=0;i--) {
        if (a[i]<a[i+1]) {
            ind=i;
            break;
        }
    }
    // if breakpoint does'nt exist
    if (ind==-1) {
        reverse(a.begin(),a.end());
        return a;
    }
    // 2. Find next greater element and swap it with arr[ind]
    for (int i=n-1;i>=ind;i--) {
        if (a[i]>a[ind]) 
        swap(a[i],a[ind]);
        break;
    }
    reverse(a.begin()+ind+1,a.end());
    return;
}
//time:O(n),space:O(1)
