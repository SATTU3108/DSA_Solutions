#include <bits/stdc++.h>
using namespace std;

/*
SUBSET SUM 1
Given an array print all the sum of the subset generated from it, in the increasing order.
*/

void subsetSumHelper(int ind,vector<int> &arr,int n,vector<int> &ans,int sum) {
    if (ind==n) {
        ans.push_back(sum);
        return;
    }
    subsetSumHelper(ind+1,arr,n,ans,sum+arr[ind]); //pick up the element
    subsetSumHelper(ind+1,arr,n,ans,sum);
}
vector<int> subsetSums(vector<int> &arr,int n) {
    vector<int> ans;
    subsetSumHelper(0,arr,n,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}

/*
SUBSET SUM 2
Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.
*/

void subsetSumHelper(vector<int> &nums,int index,vector<int> ds,set<vector<int>> &res) {
    if (index==nums.size()) {
        sort(ds.begin(),ds.end());
        res.insert(ds);
        return;
    }
    ds.push_back(nums[index]);
    subsetSumHelper(nums,index+1,ds,res);
    ds.pop_back();
    subsetSumHelper(nums,index+1,ds,res);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans;
    set<vector<int>> res;
    vector<int> ds;
    subsetSumHelper(nums,0,ds,res);
    for (auto it:res) ans.push_back(it);
    return ans;
}