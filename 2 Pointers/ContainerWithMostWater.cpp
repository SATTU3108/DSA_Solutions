/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

#include <bits/stdc++.h>
using namespace std;

// Naive Approach
int maxArea(vector<int> &height) {
    int n=height.size();
    int ans=0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            int curr=(j-i)*min(height[i],height[j]);
            ans=max(ans,curr);
        }
    }
    return ans;
}
//time:O(n^2),space:O(1)

// Optimal approach
int maxArea(vector<int> &height) {
    int n=height.size();
    int ans=0;
    int left=0,right=n-1;
    while (left<=right) {
        int curr=(right-left)*min(height[left],height[right]);
        ans=max(ans,curr);
        if (height[left]<=height[right]) left++;
        else right--;
    }
    return ans;
}
//time:O(n),space:O(1)
