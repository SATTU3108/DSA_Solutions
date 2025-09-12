#include <bits/stdc++.h>
using namespace std;

/*
Given an array of n strings arr[]. The task is to determine the number of words remaining after pairwise destruction.
If two consecutive words in the array are identical, they cancel each other out. This process continues until no more eliminations are possible.
*/

// Naive Approach -> Inbuilt Functions
int removeConsecutiveSame(vector<string>& arr) {
    int i=0;
    while (i<arr.size()-1) {    
            if (arr[i]==arr[i+1]) {
            arr.erase(arr.begin()+i);
            arr.erase(arr.begin()+i);    
            if (i>0) i--;
        } 
        else i++;
    }
}
//time:O(n^2),space:O(1)

// Efficient Approach -> Stacks
int removeConsecutiveSame(vector<string> &arr) {
    stack<string> st;
    for (string &word:arr) {
        if (!st.empty() && st.top()==word) st.pop();
        st.push(word);
    }
    return st.size();
}
//time:O(n),space:O(n)