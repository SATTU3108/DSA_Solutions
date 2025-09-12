#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of integers, the task is to find the Next Greater Element for each element of the array in order of their appearance in the array.
Note: The Next Greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1. 
*/

// Naive Approach -> Nested Loops
vector<int> nextLargerElement(vector<int> &arr) {
    int n=arr.size();
    vector<int> res(n,-1);
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) 
        if (arr[j]>arr[i]) {
            res[i]=arr[j];
            break;
        }
    }
    return res;
}
//time:O(n^2),space:O(1)

// Efficient Approach -> Stacks
vector<int> nextLargerElement(vector<int> &arr) {
    int n=arr.size();
    vector<int> res(n,-1);
    stack<int> st;
    for (int i=(n-1);i>=0;i--) {
        while (!st.empty() && st.top()<=arr[i]) st.pop();
        if (!st.empty()) res[i]=st.top();
        st.push(arr[i]);
    }
    return res;
}
//time:O(n),space:O(n)


/*What if the array is circular, that is greater elements can be on left also, just start traversing from its right and then go round about to the first element after last element has beeen traversed

Here the main difference between both the codes is that here we will attach same elements to the end as well
*/ 
vector<int> nextGreaterElements(vector<int> &nums) {
    int n=nums.size();
    vector<int> nge(n,-1);
    stack<int> st;
    for (int i=(n-1)+(n);i>=0;i--) {
        while (!st.empty() && st.top()<=nums[i%n]) st.pop();
        if (i<n) {
            if (!st.empty()) nge[i]=st.top();
        }
        st.push(nums[i%n]);
    }
    return nge;
}