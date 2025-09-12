#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array and an integer x, the task is to find if there exists a pair of elements in the array whose absolute difference is x. 
*/

// Naive method -> 2 Nested loops

// Method 1 -> Sorting + BS
bool findPair(vector<int> &arr,int x) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
    for (int i=0;i<n;i++) {
        int target=arr[i]+x;
        if (binary_search(arr.begin()+i+1,arr.end(),target)) return true;
    }
    return false;
}
// Time complexity:O(NlogN),Space:O(1)

// Method 2 -> Sorting + 2 pointers
bool findPair(vector<int> &arr,int x) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int j=1;
    for (int i=0;i<n;i++) {
        while (j<n && (arr[j]-arr[i])<x) j++;
        if (j<n && i!=j && (arr[j]-arr[i])==x) return true;
    }
    return false;
}
// time:O(nlogn),space:O(1)

// Method 3 -> Hash Set
bool findPair(vector<int> &arr,int x) {
    unordered_set <int> st;
    for (int num:arr) {
        if (st.count(num+x) || st.count(num-x)) return true;
        st.insert(num);
    }
    return false;
}
//time:O(n),space:O(n)