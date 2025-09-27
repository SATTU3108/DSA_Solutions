#include <bits/stdc++.h>
using namespace std;

/*
COMBINATION SUM I
Given an array of distinct integers candidates and a target integer target, return all unique combinations of candidates where the chosen numbers sum to target. You may reuse the same number an unlimited number of times.
*/

void helper(vector<int> &candidates,int target,int ind,vector<int> &curr,vector<vector<int>> &ans) {
    if (target==0) {
        ans.push_back(curr);
        return;
    }
    if (target<0 || ind==candidates.size()) return;
    curr.push_back(candidates[ind]);
    helper(candidates,target-candidates[ind],ind,curr,ans);
    curr.pop_back();
    helper(candidates,target,ind+1,curr,ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates,int target) {        
    vector<int> curr;
    vector<vector<int>> ans;
    helper(candidates,target,0,curr,ans);
    return ans;
}

/*
COMBINAITON SUM 2
Given a collection of candidate numbers (candidates) that may contain duplicates and a target number, find all unique combinations in candidates where the numbers sum to the target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations
*/

void findCombinations2(vector<int> &candidates,int target,int ind,vector<int> curr,set<vector<int>> &res)  {
    int n=candidates.size();
    if (target==0) {
        res.insert(curr);
        return;
    }
    for (int i=ind;i<candidates.size();i++) {
        if (i>ind && candidates[i]==candidates[i-1]) continue;
        if (candidates[i]>target) break;
        curr.push_back(candidates[i]);
        findCombinations2(candidates,target-candidates[i],i+1,curr,res);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates,int target) {
    sort(candidates.begin(),candidates.end());
    set<vector<int>> res;
    vector<int> curr;
    findCombinations2(candidates,target,0,curr,res);
    vector<vector<int>> ans;
    for (auto it:res) ans.push_back(it);
    return ans;
}

/*
COMBINATION SUM 3
Find all valid combinations of k numbers that sum up to n such that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Each number in the combination must be used only once.

Constraints:
Only numbers from 1 to 9 can be used.

Each number used at most once.

No duplicates in combinations.
*/

void findCombinations3(int i,int k,int target,vector<int> &curr,vector<vector<int>> &res) {
    if (curr.size()>k) return;
    if (target==0 && curr.size()==k) {
        res.push_back(curr);
        return;
    }
    for (int choice=i;choice<=9;choice++) {
        curr.push_back(choice);
        findCombinations3(choice+1,k,target-choice,curr,res);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum(int k,int n) {
    vector<vector<int>> res;
    vector<int> curr;
    findCombinations3(1,k,n,curr,res);
    return res;
}
