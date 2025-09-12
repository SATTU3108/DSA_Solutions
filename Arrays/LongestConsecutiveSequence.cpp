#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements. And the consecutive numbers need not necessarily lie consecutively.
*/

// Naive Approach -> Linear Search
bool linearSearch(vector<int> &a,int num) {
    int n=a.size();
    for (int i=0;i<n;i++) {
        if (a[i]==num) return true;
    }
    return false;
}
int longestConsecutiveElements(vector<int> &a) {
    int n=a.size();
    int longest=1;
    for (int i=0;i<n;i++) {
        int x=a[i];
        int count=1;
        while (linearSearch(a,x+1)==true) {
            x++;
            count++;
        }
        longest=max(longest,count);
    }
    return longest;
}
//time:O(n^2),space:O(1)

// Better Appraoch -> Sorting
int longestConsecutiveElements(vector<int> &arr) {
    if (arr.empty()) return 0;
    sort(arr.begin(),arr.end());
    int res=1,count=1;
    for (int i=1;i<arr.size();i++) {
        if (arr[i]==arr[i-1]) continue;
        if (arr[i]==arr[i-1]+1) count++;
        else count=1;
        res=max(res,count);
    }
    return res;
}
//time:O(nlogn),space:O(1)

// Optimal Approach -> hashing
int longestConsecutiveElements(vector<int> &arr) {
    unordered_set<int> st;
    int res=0;
    // hash all array elements
    for (int val:arr) st.insert(val);
    // chack each possible sequence consider ith element as starting point
    for (int val:arr) {
        if (st.find(val)!=st.end() && st.find(val-1)==st.end()) {
            int curr=val,count=0;
            while (st.find(curr)!=st.end()) {
                st.erase(curr);
                curr++;
                count++;
            }
            res=max(res,count);
        }   
    }
    return res;
}