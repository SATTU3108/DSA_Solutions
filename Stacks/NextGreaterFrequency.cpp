#include <bits/stdc++.h>
using namespace std;

/*
Given an array, for each element find the value of the nearest element to the right which is having a frequency greater than that of the current element. If there does not exist an answer for a position, then make the value '-1'.
*/

// Naive Approach: Nested Loops
vector<int> findGreater(vector<int> &arr) {
    unordered_map<int,int> freq;
    for (int num:arr) freq[num]++;
    vector<int> result;
    for (int i=0;i<arr.size();i++) {
        bool found=false;
        for (int j=i+1;j<arr.size();j++) {
            if (freq[arr[j]]>freq[arr[i]]) {
                result.push_back(arr[j]);
                found=true;
                break;
            }
        }
        if (!found) result.push_back(-1);
    }
    return result;
}
//time:O(n),space:O(n)

// Efficient Approach -> Stacks
vector<int> findGreater(vector<int> &arr) {
    int n=arr.size();
    vector<int> res(n,-1);
    unordered_map<int,int> freq;
    for (int num:arr) freq[num]++;
    stack<int> st;
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && freq[arr[i]]>=freq[arr[st.top()]]) st.pop();
        if (!st.empty()) res[i]=arr[st.top()];
        st.push(i);
    }
    return res;
}