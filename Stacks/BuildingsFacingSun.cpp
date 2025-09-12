#include <bits/stdc++.h>
using namespace std;

/*
Given the array arr[] of heights of certain buildings that lie adjacent to each other, Sunlight starts falling from the left side of the buildings. If there is a building of a certain height, all the buildings to the right side of it having lesser heights cannot see the sun. The task is to find the total number of buildings that receive sunlight.
*/

// Better Approach -> Stacks 
int longest(vector<int>& arr) {
    int n=arr.size();
    stack<int> st;
    int count=0;
    for (int i=0;i<n;i++) {
        while (!st.empty() && st.top()<=arr[i]) st.pop();
        if (st.empty()) count++;
        st.push(arr[i]);
    }
    return count;
}
//time:O(n),space:O(n)

// Efficient Approach 
int longest(vector<int>& arr) {
    int n=arr.size();
    int count=1,max_height=arr[0];
    for (int i=1;i<n;i++) {
        if (arr[i]>=max_height) {
            count++;
            max_height=arr[i];
        }
    }
    return count;
}