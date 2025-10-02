#include <bits/stdc++.h>
using namespace std;

// each unique element appears at most 1 time
int removeDuplicates(vector<int> &nums) {
    if (nums.size()==1) return 1;
    int i=1;
    for (int j=1;j<nums.size();j++) {
        if (nums[j]!=nums[i-1]) {
            nums[i]=nums[j];
            i++;
        }
    }
    return i;
}

// each unique element appears at most 2 times
int removeDuplicates(vector<int>& nums) {
    if (nums.size()<=2) return true;
    int i=2;
    for (int j=2;j<nums.size();j++) {
        if (nums[j]!=nums[i-2]) {
            nums[i]=nums[j];
            i++;
        }
    }
    return i;
}
