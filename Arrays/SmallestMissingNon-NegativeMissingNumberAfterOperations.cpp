/*
You are given a 0-indexed integer array nums and an integer value.

In one operation, you can add or subtract value from any element of nums.

For example, if nums = [1,2,3] and value = 2, you can choose to subtract value from nums[0] to make nums = [-1,2,3].
The MEX (minimum excluded) of an array is the smallest missing non-negative integer in it.

For example, the MEX of [-1,2,3] is 0 while the MEX of [1,0,3] is 2.
Return the maximum MEX of nums after applying the mentioned operation any number of times.
*/

#include <bits/stdc++.h>
using namespace std;

int findSmallestInteger(vector<int> &nums,int value) {
    // 1. Count the frequency of each remainder. With a given number, we can form any number with that same remainder
    unordered_map<int,int> remainders;
    for (int num:nums) {
        int rem=((num%value)+value)%value;
        remainders[rem]++;
    }
    // 2. Try to form every non-negative integer; for each i, check if we have a number with i%value
    int i=0;
    while (true) {
        int rem=i%value;
        if (remainders[rem]>0) {
            remainders[rem]--;
            i++;
        }
        else return i;
    }
}
