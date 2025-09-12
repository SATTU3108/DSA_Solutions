/*
Given an array arr[] of n integers, the task is to replace each element of Array with their rank in array. The rank of an element is defined as the distance between the element with the first element of the array when the array is arranged in ascending order. If two or more are same in the array then their rank is also the same as the rank of the first occurrence of the element. 
*/

#include <bits/stdc++.h>
using namespace std;

// Naive Approach
vector<int> replaceWithRank(vector<int> &arr) {
    int n=arr.size();
    vector<int> res(n);
    for (int i=0;i<n;i++) {
        unordered_set<int> st;
        for (int j=0;j<n;j++) {
            if (arr[j]<arr[i]) st.insert(arr[j]);
        }
        res[i]=st.size()+1;
    }
    return res;
}
//time:O(n^2),space:O(n)

// Optimal Approach
vector<int> replaceWithRank(vector<int> &arr) {
    int n=arr.size();
    vector<int> res(n);
    // create min heap of pairs(elements,indices)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    // push elements with their indices
    for (int i=0;i<n;i++) pq.push({arr[i],i});
    int rank=0,last_num=INT_MAX;
    // process elements in their sorted order
    while (!pq.empty()) {
        int curr=pq.top().first,index=pq.top().second;
        // increment rank only for new numbers
        if (last_num==INT_MAX || curr!=last_num) rank++;
        // assign rank to original positions
        res[index]=rank;
        last_num=curr;
    }
    return res;
}