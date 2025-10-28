/*
You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and choose a movement direction of either left or right.

After that, you repeat the following process:

If curr is out of the range [0, n - 1], this process ends.
If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, or decrementing curr if you are moving left.
Else if nums[curr] > 0:
Decrement nums[curr] by 1.
Reverse your movement direction (left becomes right and vice versa).
Take a step in your new direction.
A selection of the initial position curr and movement direction is considered valid if every element in nums becomes 0 by the end of the process.

Return the number of possible valid selections.
*/

#include <bits/stdc++.h>
using namespace std;

int countValidSelections(vector<int>& nums) {
    int n=nums.size();
    vector<int> left(n,0);
    left[0]=nums[0];
    for (int i=1;i<n;i++) {
        left[i]=left[i-1]+nums[i];
    }
    vector<int> right(n,0);
    right[n-1]=nums[n-1];
    for (int i=n-2;i>=0;i--) {
        right[i]=right[i+1]+nums[i];
    }
    int count=0;
    for (int i=0;i<n;i++) {
        if (nums[i]!=0) continue;
        if (left[i]==right[i]) count+=2;
        else if (abs(left[i]-right[i])==1) count++;
    }
    return count;
}
//time:O(n),space:O(n)
