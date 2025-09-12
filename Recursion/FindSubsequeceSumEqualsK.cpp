#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals the given target sum(k).
*/
bool helperFunc(vector<int> &arr,int n,int k,int sum,int ind) {
    if (ind==n) {
        if (sum==k) return true;
        return false;
    }
    bool notPick=helperFunc(arr,n,k,sum,ind+1); //dont pick the element
    bool pick=helperFunc(arr,n,k,sum+arr[ind],ind+1); //pick the element
    return pick || notPick;
}
bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    return helperFunc(arr,n,k,0,0);
}

/*
Given an array arr[] of length n and a number k, the task is to find all the subsequences of the array with sum of its elements equal to k.

Note: A subsequence is a subset that can be derived from an array by removing zero or more elements, without changing the order of the remaining elements.
*/
void findSubsequence(int ind,int sum,int k,vector<int> &cur,vector<int> &arr,vector<vector<int>> &res) {
    int n=arr.size();
    if(ind==n) {
        if(sum==k) res.push_back(cur);
        return;
    }
    findSubsequence(ind+1,sum,k,cur,arr,res);
    cur.push_back(arr[ind]);
    findSubsequence(ind+1,sum+arr[ind],k,cur,arr,res);
    cur.pop_back();
}
vector<vector<int>> subsequencesSumK(vector<int> &arr, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    findSubsequence(0,0,k,cur,arr,res);
    return res;
}